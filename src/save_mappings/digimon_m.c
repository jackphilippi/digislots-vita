#include "digimon_m.h"

DigimonMapping digimonMap[] = {
    {0x00, "NULL"}, {0x01, "Botamon"}, {0x02, "Koromon"}, {0x03, "Agumon"}, {0x04, "Betamon"},
    {0x05, "Greymon"}, {0x06, "Devimon"}, {0x07, "Airdramon"}, {0x08, "Tyrannomon"}, {0x09, "Meramon"},
    {0x0A, "Seadramon"}, {0x0B, "Numemon"}, {0x0C, "Metalgreymon"}, {0x0D, "Mamemon"}, {0x0E, "Monzaemon"},
    {0x0F, "Punimon"}, {0x10, "Tsunomon"}, {0x11, "Gabumon"}, {0x12, "Elecmon"}, {0x13, "Kabuterimon"},
    {0x14, "Angemon"}, {0x15, "Birdramon"}, {0x16, "Garurumon"}, {0x17, "Frigimon"}, {0x18, "Whamon"},
    {0x19, "Vegiemon"}, {0x1A, "Skullgreymon"}, {0x1B, "Metalmamemon"}, {0x1C, "Vademon"}, {0x1D, "Poyomon"},
    {0x1E, "Tokomon"}, {0x1F, "Patamon"}, {0x20, "Kunemon"}, {0x21, "Unimon"}, {0x22, "Ogremon"},
    {0x23, "Shellmon"}, {0x24, "Centarumon"}, {0x25, "Bakemon"}, {0x26, "Drimogemon"}, {0x27, "Sukamon"},
    {0x28, "Andromon"}, {0x29, "Giromon"}, {0x2A, "Etemon"}, {0x2B, "Yuramon"}, {0x2C, "Tanemon"},
    {0x2D, "Biyomon"}, {0x2E, "Palmon"}, {0x2F, "Monochromon"}, {0x30, "Leomon"}, {0x31, "Coelamon"},
    {0x32, "Kokatorimon"}, {0x33, "Kuwagamon"}, {0x34, "Mojyamon"}, {0x35, "Nanimon"}, {0x36, "Megadramon"},
    {0x37, "Piximon"}, {0x38, "Digitamamon"}, {0x39, "Penguinmon"}, {0x3A, "Ninjamon"}, {0x3B, "Phoenixmon"},
    {0x3C, "H-Kabuterimon"}, {0x3D, "Megaseadramon"}, {0x3E, "Weregarurumon"}, {0x3F, "Panjyamon"},
    {0x40, "Gigadramon"}, {0x41, "Metaletemon"}, {0x42, "Myostismon"}, {0x43, "Yanmamon"}, {0x44, "Gotsumon"},
    {0x45, "Flarerizamon"}, {0x46, "Warumonzaemon"}, {0x47, "Snowagumon"}, {0x48, "Hyogamon"},
    {0x49, "Platinumsukamon"}, {0x4A, "Dokunemon"}, {0x4B, "Shimaunimon"}, {0x4C, "Tankmon"},
    {0x4D, "Redvegiemon"}, {0x4E, "J-Mojyamon"}, {0x4F, "Nisedrimogemon"}, {0x50, "Goburimon"},
    {0x51, "Mudfrigimon"}, {0x52, "Psychemon"}, {0x53, "Modokibetamon"}, {0x54, "Toyagumon"},
    {0x55, "Piddomon"}, {0x56, "Aruraumon"}, {0x57, "Geremon"}, {0x58, "Vermilimon"}, {0x59, "Fugamon"},
    {0x5A, "Tekkamon"}, {0x5B, "Morishellmon"}, {0x5C, "Guardromon"}, {0x5D, "Muchomon"}, {0x5E, "Icemon"},
    {0x5F, "Akatorimon"}, {0x60, "Tsukaimon"}, {0x61, "Sharmamon"}, {0x62, "Clearagumon"}, {0x63, "Weedmon"},
    {0x64, "Icedevimon"}, {0x65, "Darkrizamon"}, {0x66, "Sandyanmamon"}, {0x67, "Snowgoburimon"},
    {0x68, "Bluemeramon"}, {0x69, "Gururumon"}, {0x6A, "Saberdramon"}, {0x6B, "Soulmon"}, {0x6C, "Rockmon"},
    {0x6D, "Otamamon"}, {0x6E, "Gekomon"}, {0x6F, "Tentomon"}, {0x70, "Waruseadramon"}, {0x71, "Meteormon"},
    {0x72, "NULL"}, {0x73, "Machinedramon"}, {0x74, "Analogman"}, {0x75, "Jijimon"}, {0x76, "Market Manager"},
    {0x77, "Shogungekomon"}, {0x78, "King of Sukamon"}, {0x79, "Cherrymon"}, {0x7A, "Hagurumon"},
    {0x7B, "Tinmon"}, {0x7C, "Master Tyrannomon"}, {0x7D, "Goburimon"}, {0x7E, "Brachiomon"}, {0x7F, "Demimeramon"}
};

const int digimon_m_SIZE = sizeof(digimonMap) / sizeof(DigimonMapping);

char* getDigimonName(unsigned int searchId) {
    const char* digimonName = "Unknown";
    for (int i = 0; i < digimon_m_SIZE; i++) {
        if (digimonMap[i].value == searchId) {
            digimonName = digimonMap[i].name;
            break;
        }
    }
    return (char*)digimonName;
}