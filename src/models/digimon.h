#ifndef DIGIMON_H_
#define DIGIMON_H_

typedef enum {
    Fresh,
    InTraining,
    Rookie,
    Champion,
    Ultimate
} Stage;

typedef enum {
    Data,
    Vaccine,
    Virus
} Type;

// Struct equivalent of EvolutionRequirements class
typedef struct {
    int hp;
    int mp;
    int offense;
    int defense;
    int speed;
    int brains;
    int care;
    int weight;
    int discipline;
    int happiness;
    int battles;
    int techs;
    bool minCare;
    bool minBattles;
} EvolutionRequirements;

typedef struct Digimon Digimon; // forward reference

typedef struct {
    unsigned int searchId;
    Digimon *digimon;
} DigimonMapping;

extern DigimonMapping digimonMap[];

extern const int DIGIMON_MAPPING_SIZE;

char* getNameFromByteId(unsigned int searchId);


// Struct equivalent of Digimon class
typedef struct Digimon {
    char* name;
    Stage stage;
    Type type;
    EvolutionRequirements req;
    Digimon** evolutionPath; // Array of pointers to Digimon
    int evolutionPathSize;
    Digimon* digimonBonus; // Optional, can be NULL
} Digimon;

void initialiseDigimon();

const char* getDigiStageString(Stage stage);

const char* getDigiTypeString(Type type);

const char* getEvolutionNameStrings(const Digimon* digimon);

extern Digimon botamon;
extern Digimon poyomon;
extern Digimon punimon;
extern Digimon yuramon;
extern Digimon koromon;
extern Digimon tanemon;
extern Digimon tokomon;
extern Digimon tsunomon;
extern Digimon agumon;
extern Digimon betamon;
extern Digimon biyomon;
extern Digimon elecmon;
extern Digimon gabumon;
extern Digimon kunemon;
extern Digimon palmon;
extern Digimon patamon;
extern Digimon penguinmon;
extern Digimon airdramon;
extern Digimon angemon;
extern Digimon bakemon;
extern Digimon birdramon;
extern Digimon centarumon;
extern Digimon coelamon;
extern Digimon devimon;
extern Digimon drimogemon;
extern Digimon frigimon;
extern Digimon garurumon;
extern Digimon greymon;
extern Digimon kabuterimon;
extern Digimon kokatorimon;
extern Digimon kuwagamon;
extern Digimon leomon;
extern Digimon meramon;
extern Digimon mojyamon;
extern Digimon monochromon;
extern Digimon nanimon;
extern Digimon ninjamon;
extern Digimon numemon;
extern Digimon ogremon;
extern Digimon seadramon;
extern Digimon shellmon;
extern Digimon sukamon;
extern Digimon tyrannomon;
extern Digimon unimon;
extern Digimon vegiemon;
extern Digimon whamon;
extern Digimon andromon;
extern Digimon digitamamon;
extern Digimon etemon;
extern Digimon giromon;
extern Digimon hkabuterimon;
extern Digimon mamemon;
extern Digimon megadramon;
extern Digimon megaseadramon;
extern Digimon metalgreymon;
extern Digimon metalmamemon;
extern Digimon monzaemon;
extern Digimon phoenixmon;
extern Digimon piximon;
extern Digimon skullgreymon;
extern Digimon vademon;

#endif