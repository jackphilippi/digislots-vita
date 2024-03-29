## This file is a quick tutorial on writing CMakeLists for targeting the Vita
cmake_minimum_required(VERSION 2.8)

## This includes the Vita toolchain, must go before project definition
# It is a convenience so you do not have to type
# -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake for cmake. It is
# highly recommended that you include this block for all projects.
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

## Define project parameters here
# Name of the project
project(digislots_vita)
# This line adds Vita helper macros, must go after project definition in order
# to build Vita specific artifacts (self/vpk).
include("${VITASDK}/share/vita.cmake" REQUIRED)

## Configuration options for this app
set(VITA_APP_NAME "DigiSlots Vita") # Display name (under bubble in LiveArea)
set(VITA_TITLEID  "VSDK00007") # 9 characters. Recommended: XXXXYYYYY (X= unique string of developer and Y = a unique number for this app)
set(VITA_VERSION  "01.00")

## Flags and includes for building
# Note that we make sure not to overwrite previous flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1") # Optional. You can specify more param.sfo flags this way.

# Add any additional include paths here
include_directories(
  common # This is for debugScreenPrintf(), you shouldn't need it in your projects
)

# Add any additional library paths here
link_directories(
  ${CMAKE_CURRENT_BINARY_DIR} # lets you use any library currently being built
)

## Add resources
file(COPY
  ${CMAKE_SOURCE_DIR}/resources/
  DESTINATION ${CMAKE_BINARY_DIR}/sce_sys/livearea/contents/resources/
)

## Build and link
# Add all the files needed to compile here
add_executable(${PROJECT_NAME}
  ${vitatoolbox_res}
  src/main.c
  src/models/digimon.c
  src/save_mappings/ascii_m.c
  src/save_mappings/item_m.c
  src/offsets.c
  src/screen.c
  common/debugScreen.c
)

# Library to link to (drop the -l prefix). This will mostly be stubs.
target_link_libraries(${PROJECT_NAME}
  vita2d  
  png # used by vita2d
  SceAppMgr_stub # used by vita2d
  SceAppUtil_stub
  SceAudio_stub
  SceAudiodec_stub
  SceCommonDialog_stub # used by vita2d
  SceCtrl_stub # for button presses etc
  SceDisplay_stub # used by debugScreenPrintf()
  SceGxm_stub # used by vita2d
  SceHttp_stub
  SceIme_stub
  SceLibKernel_stub
  SceMtpIfDriver_stub
  SceMusicExport_stub
  SceNet_stub
  SceNetCtl_stub
  ScePgf_stub
  ScePvf_stub
  ScePhotoExport_stub
  ScePower_stub
  ScePromoterUtil_stub
  SceShellSvc_stub
  SceSsl_stub
  SceSysmodule_stub
  SceTouch_stub
  SceUdcd_stub
  SceUsbstorVStorDriver_stub
  SceVshBridge_stub
  m # math
  z # zlib
)

## Create Vita files
vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME}
  UNSAFE
)

## Add resources
file(COPY
  ${CMAKE_SOURCE_DIR}/resources/
  DESTINATION ${CMAKE_BINARY_DIR}/sce_sys/livearea/contents/resources/
)

# The FILE directive lets you add additional files to the VPK, the syntax is
# FILE src_path dst_path_in_vpk. In this case, we add the LiveArea paths.
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
  FILE ${CMAKE_BINARY_DIR}/src/resources resources # Add resources from the source directory to the VPK
)