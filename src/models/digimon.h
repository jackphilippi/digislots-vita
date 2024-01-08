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

#endif