# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/git/digislots-vita

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/git/digislots-vita

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/d/git/digislots-vita/CMakeFiles /mnt/d/git/digislots-vita/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/d/git/digislots-vita/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named digislots_vita.vpk

# Build rule for target.
digislots_vita.vpk: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 digislots_vita.vpk
.PHONY : digislots_vita.vpk

# fast build rule for target.
digislots_vita.vpk/fast:
	$(MAKE) -f CMakeFiles/digislots_vita.vpk.dir/build.make CMakeFiles/digislots_vita.vpk.dir/build
.PHONY : digislots_vita.vpk/fast

#=============================================================================
# Target rules for targets named digislots_vita.self

# Build rule for target.
digislots_vita.self: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 digislots_vita.self
.PHONY : digislots_vita.self

# fast build rule for target.
digislots_vita.self/fast:
	$(MAKE) -f CMakeFiles/digislots_vita.self.dir/build.make CMakeFiles/digislots_vita.self.dir/build
.PHONY : digislots_vita.self/fast

#=============================================================================
# Target rules for targets named digislots_vita-velf

# Build rule for target.
digislots_vita-velf: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 digislots_vita-velf
.PHONY : digislots_vita-velf

# fast build rule for target.
digislots_vita-velf/fast:
	$(MAKE) -f CMakeFiles/digislots_vita-velf.dir/build.make CMakeFiles/digislots_vita-velf.dir/build
.PHONY : digislots_vita-velf/fast

#=============================================================================
# Target rules for targets named digislots_vita

# Build rule for target.
digislots_vita: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 digislots_vita
.PHONY : digislots_vita

# fast build rule for target.
digislots_vita/fast:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/build
.PHONY : digislots_vita/fast

common/debugScreen.obj: common/debugScreen.c.obj

.PHONY : common/debugScreen.obj

# target to build an object file
common/debugScreen.c.obj:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/common/debugScreen.c.obj
.PHONY : common/debugScreen.c.obj

common/debugScreen.i: common/debugScreen.c.i

.PHONY : common/debugScreen.i

# target to preprocess a source file
common/debugScreen.c.i:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/common/debugScreen.c.i
.PHONY : common/debugScreen.c.i

common/debugScreen.s: common/debugScreen.c.s

.PHONY : common/debugScreen.s

# target to generate assembly for a file
common/debugScreen.c.s:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/common/debugScreen.c.s
.PHONY : common/debugScreen.c.s

src/main.obj: src/main.c.obj

.PHONY : src/main.obj

# target to build an object file
src/main.c.obj:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/main.c.obj
.PHONY : src/main.c.obj

src/main.i: src/main.c.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/main.c.s
.PHONY : src/main.c.s

src/models/digimon.obj: src/models/digimon.c.obj

.PHONY : src/models/digimon.obj

# target to build an object file
src/models/digimon.c.obj:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/models/digimon.c.obj
.PHONY : src/models/digimon.c.obj

src/models/digimon.i: src/models/digimon.c.i

.PHONY : src/models/digimon.i

# target to preprocess a source file
src/models/digimon.c.i:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/models/digimon.c.i
.PHONY : src/models/digimon.c.i

src/models/digimon.s: src/models/digimon.c.s

.PHONY : src/models/digimon.s

# target to generate assembly for a file
src/models/digimon.c.s:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/models/digimon.c.s
.PHONY : src/models/digimon.c.s

src/offsets.obj: src/offsets.c.obj

.PHONY : src/offsets.obj

# target to build an object file
src/offsets.c.obj:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/offsets.c.obj
.PHONY : src/offsets.c.obj

src/offsets.i: src/offsets.c.i

.PHONY : src/offsets.i

# target to preprocess a source file
src/offsets.c.i:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/offsets.c.i
.PHONY : src/offsets.c.i

src/offsets.s: src/offsets.c.s

.PHONY : src/offsets.s

# target to generate assembly for a file
src/offsets.c.s:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/offsets.c.s
.PHONY : src/offsets.c.s

src/save_mappings/ascii_m.obj: src/save_mappings/ascii_m.c.obj

.PHONY : src/save_mappings/ascii_m.obj

# target to build an object file
src/save_mappings/ascii_m.c.obj:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/save_mappings/ascii_m.c.obj
.PHONY : src/save_mappings/ascii_m.c.obj

src/save_mappings/ascii_m.i: src/save_mappings/ascii_m.c.i

.PHONY : src/save_mappings/ascii_m.i

# target to preprocess a source file
src/save_mappings/ascii_m.c.i:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/save_mappings/ascii_m.c.i
.PHONY : src/save_mappings/ascii_m.c.i

src/save_mappings/ascii_m.s: src/save_mappings/ascii_m.c.s

.PHONY : src/save_mappings/ascii_m.s

# target to generate assembly for a file
src/save_mappings/ascii_m.c.s:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/save_mappings/ascii_m.c.s
.PHONY : src/save_mappings/ascii_m.c.s

src/save_mappings/item_m.obj: src/save_mappings/item_m.c.obj

.PHONY : src/save_mappings/item_m.obj

# target to build an object file
src/save_mappings/item_m.c.obj:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/save_mappings/item_m.c.obj
.PHONY : src/save_mappings/item_m.c.obj

src/save_mappings/item_m.i: src/save_mappings/item_m.c.i

.PHONY : src/save_mappings/item_m.i

# target to preprocess a source file
src/save_mappings/item_m.c.i:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/save_mappings/item_m.c.i
.PHONY : src/save_mappings/item_m.c.i

src/save_mappings/item_m.s: src/save_mappings/item_m.c.s

.PHONY : src/save_mappings/item_m.s

# target to generate assembly for a file
src/save_mappings/item_m.c.s:
	$(MAKE) -f CMakeFiles/digislots_vita.dir/build.make CMakeFiles/digislots_vita.dir/src/save_mappings/item_m.c.s
.PHONY : src/save_mappings/item_m.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... digislots_vita.vpk"
	@echo "... rebuild_cache"
	@echo "... digislots_vita.self"
	@echo "... digislots_vita-velf"
	@echo "... digislots_vita"
	@echo "... common/debugScreen.obj"
	@echo "... common/debugScreen.i"
	@echo "... common/debugScreen.s"
	@echo "... src/main.obj"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/models/digimon.obj"
	@echo "... src/models/digimon.i"
	@echo "... src/models/digimon.s"
	@echo "... src/offsets.obj"
	@echo "... src/offsets.i"
	@echo "... src/offsets.s"
	@echo "... src/save_mappings/ascii_m.obj"
	@echo "... src/save_mappings/ascii_m.i"
	@echo "... src/save_mappings/ascii_m.s"
	@echo "... src/save_mappings/item_m.obj"
	@echo "... src/save_mappings/item_m.i"
	@echo "... src/save_mappings/item_m.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

