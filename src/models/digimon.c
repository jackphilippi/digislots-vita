#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "digimon.h"

Digimon botamon;
Digimon poyomon;
Digimon punimon;
Digimon yuramon;
Digimon koromon;
Digimon tanemon;
Digimon tokomon;
Digimon tsunomon;
Digimon agumon;
Digimon betamon;
Digimon biyomon;
Digimon elecmon;
Digimon gabumon;
Digimon kunemon;
Digimon palmon;
Digimon patamon;
Digimon penguinmon;
Digimon airdramon;
Digimon angemon;
Digimon bakemon;
Digimon birdramon;
Digimon centarumon;
Digimon coelamon;
Digimon devimon;
Digimon drimogemon;
Digimon frigimon;
Digimon garurumon;
Digimon greymon;
Digimon kabuterimon;
Digimon kokatorimon;
Digimon kuwagamon;
Digimon leomon;
Digimon meramon;
Digimon mojyamon;
Digimon monochromon;
Digimon nanimon;
Digimon ninjamon;
Digimon numemon;
Digimon ogremon;
Digimon seadramon;
Digimon shellmon;
Digimon sukamon;
Digimon tyrannomon;
Digimon unimon;
Digimon vegiemon;
Digimon whamon;
Digimon andromon;
Digimon digitamamon;
Digimon etemon;
Digimon giromon;
Digimon hkabuterimon;
Digimon mamemon;
Digimon megadramon;
Digimon megaseadramon;
Digimon metalgreymon;
Digimon metalmamemon;
Digimon monzaemon;
Digimon phoenixmon;
Digimon piximon;
Digimon skullgreymon;
Digimon vademon;

const char* getDigiStageString(Stage stage) {
    switch (stage) {
        case Fresh:      return "Fresh";
        case InTraining: return "InTraining";
        case Rookie:     return "Rookie";
        case Champion:   return "Champion";
        case Ultimate:   return "Ultimate";
        default:         return "[ERR_UNKNOWN_STAGE]";
    }
}

const char* getDigiTypeString(Type type) {
    switch (type) {
        case Data:    return "Data";
        case Vaccine: return "Vaccine";
        case Virus:   return "Virus";
        default:      return "[ERR_UNKNOWN_TYPE]";
    }
}

const char* getEvolutionNameStrings(const Digimon* digimon) {
    int totalLength = 1; // Start with 1 for the null-terminator
    for (int i = 0; i < digimon->evolutionPathSize; ++i) {
        totalLength += strlen(digimon->evolutionPath[i]->name) + 2; // +2 for comma and space
    }

    char* result = malloc(totalLength);
    if (!result) {
        return NULL; // Memory allocation failed
    }

    result[0] = '\0'; // Initialize to an empty string
    for (int i = 0; i < digimon->evolutionPathSize; ++i) {
        strcat(result, digimon->evolutionPath[i]->name);
        if (i < digimon->evolutionPathSize - 1) {
            strcat(result, ", ");
        }
    }

    return result;
}

void 
initDigimon(
    Digimon* digimon,
    char* name,
    Stage stage,
    Type type,
    EvolutionRequirements req,
    Digimon** evolutionPath,
    int pathSize,
    Digimon* bonus
) {
    digimon->name = name;
    digimon->stage = stage;
    digimon->type = type;
    digimon->req = req;
    digimon->evolutionPath = evolutionPath;
    digimon->evolutionPathSize = pathSize;
    digimon->digimonBonus = bonus;
}

void initialiseDigimon() {
    Digimon* botamonEvolutions[2] = { &koromon, &sukamon };
    EvolutionRequirements botamonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&botamon, "Botamon", Fresh, Data, botamonReq, botamonEvolutions, 2, 0);

    Digimon* poyomonEvolutions[2] = { &tokomon, &sukamon };
    EvolutionRequirements poyomonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&poyomon, "Poyomon", Fresh, Data, poyomonReq, poyomonEvolutions, 2, 0);
    
    Digimon* punimonEvolutions[2] = { &tsunomon, &sukamon };
    EvolutionRequirements punimonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&punimon, "Punimon", Fresh, Data, punimonReq, punimonEvolutions, 2, 0);

    Digimon* yuramonEvolutions[2] = { &tanemon, &sukamon };
    EvolutionRequirements yuramonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&yuramon, "Yuramon", Fresh, Data, yuramonReq, yuramonEvolutions, 2, 0);

    Digimon* koromonEvolutions[4] = { &agumon, &gabumon, &kunemon, &sukamon };
    EvolutionRequirements koromonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&koromon, "Koromon", InTraining, Data, koromonReq, koromonEvolutions, 4, 0);

    Digimon* tanemonEvolutions[4] = { &palmon, &betamon, &kunemon, &sukamon };
    EvolutionRequirements tanemonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&tanemon, "Tanemon", InTraining, Data, tanemonReq, tanemonEvolutions, 4, 0);

    Digimon* tokomonEvolutions[4] = { &patamon, &biyomon, &kunemon, &sukamon };
    EvolutionRequirements tokomonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&tokomon, "Tokomon", InTraining, Data, tokomonReq, tokomonEvolutions, 4, 0);

    Digimon* tsunomonEvolutions[4] = { &elecmon, &penguinmon, &kunemon, &sukamon };
    EvolutionRequirements tsunomonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&tsunomon, "Tsunomon", InTraining, Data, tsunomonReq, tsunomonEvolutions, 4, 0);

    Digimon* agumonEvolutions[9] = { &greymon, &meramon, &birdramon, &centarumon, &monochromon, &tyrannomon, &numemon, &nanimon, &sukamon };
    EvolutionRequirements agumonReq = { 0, 1000, 0, 0, 0, 0, 3, 20, 0, 50, 0, 28, false, false };
    initDigimon(&agumon, "Agumon", Rookie, Vaccine, agumonReq, agumonEvolutions, 9, &koromon);

    Digimon* betamonEvolutions[7] = { &seadramon, &whamon, &shellmon, &coelamon, &numemon, &nanimon, &sukamon };
    EvolutionRequirements betamonReq = { 10, 10, 0, 1, 0, 0, 0, 15, 0, 0, 0, 0, false, false };
    initDigimon(&betamon, "Betamon", Rookie, Virus, betamonReq, betamonEvolutions, 7, &tanemon);

    Digimon* biyomonEvolutions[8] = { &birdramon, &airdramon, &kokatorimon, &unimon, &kabuterimon, &numemon, &nanimon, &sukamon };
    EvolutionRequirements biyomonReq = { 0, 10, 0, 1, 1, 0, 0, 15, 0, 0, 0, 0, false, false };
    initDigimon(&biyomon, "Biyomon", Rookie, Vaccine, biyomonReq, biyomonEvolutions, 8, &tokomon);

    Digimon* elecmonEvolutions[7] = { &leomon, &angemon, &bakemon, &kokatorimon, &numemon, &nanimon, &sukamon };
    EvolutionRequirements elecmonReq = { 10, 0, 1, 0, 1, 0, 0, 15, 0, 0, 0, 0, false, false };
    initDigimon(&elecmon, "Elecmon", Rookie, Data, elecmonReq, elecmonEvolutions, 7, &tsunomon);

    Digimon* gabumonEvolutions[9] = { &centarumon, &monochromon, &drimogemon, &tyrannomon, &ogremon, &garurumon, &numemon, &nanimon, &sukamon };
    EvolutionRequirements gabumonReq = { 0, 0, 0, 1, 1, 1, 0, 15, 0, 0, 0, 0, false, false };
    initDigimon(&gabumon, "Gabumon", Rookie, Data, gabumonReq, gabumonEvolutions, 9, &koromon);

    Digimon* kunemonEvolutions[7] = { &bakemon, &kabuterimon, &kuwagamon, &vegiemon, &numemon, &nanimon, &sukamon };
    EvolutionRequirements kunemonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&kunemon, "Kunemon", Rookie, Virus, kunemonReq, kunemonEvolutions, 7, 0);

    Digimon* palmonEvolutions[8] = { &kuwagamon, &vegiemon, &ninjamon, &whamon, &coelamon, &numemon, &nanimon, &sukamon };
    EvolutionRequirements palmonReq = { 0, 10, 0, 0, 1, 1, 0, 15, 0, 0, 0, 0, false, false };
    initDigimon(&palmon, "Palmon", Rookie, Vaccine, palmonReq, palmonEvolutions, 8, &tanemon);

    Digimon* patamonEvolutions[9] = { &drimogemon, &tyrannomon, &ogremon, &leomon, &angemon, &unimon, &numemon, &nanimon, &sukamon };
    EvolutionRequirements patamonReq = { 10, 0, 1, 0, 0, 1, 0, 15, 0, 0, 0, 0, false, false };
    initDigimon(&patamon, "Patamon", Rookie, Data, patamonReq, patamonEvolutions, 9, &tokomon);

    Digimon* penguinmonEvolutions[8] = { &whamon, &shellmon, &garurumon, &frigimon, &mojyamon, &numemon, &nanimon, &sukamon };
    EvolutionRequirements penguinmonReq = { 0, 10, 0, 1, 0, 1, 0, 15, 0, 0, 0, 0, false, false };
    initDigimon(&penguinmon, "Penguinmon", Rookie, Data, penguinmonReq, penguinmonEvolutions, 8, &tsunomon);

    Digimon* airdramonEvolutions[4] = { &megadramon, &phoenixmon, &vademon, &sukamon };
    EvolutionRequirements airdramonReq = { 10, 10, 1, 0, 0, 0, 0, 15, 0, 0, 0, 0, false, false };
    initDigimon(&airdramon, "Airdramon", Champion, Vaccine, airdramonReq, airdramonEvolutions, 4, 0);

    Digimon* angemonEvolutions[5] = { &andromon, &phoenixmon, &devimon, &vademon, &sukamon };
    EvolutionRequirements angemonReq = { 2000, 4000, 200, 400, 200, 400, 5, 40, 95, 0, 30, 30, true, false };
    initDigimon(&angemon, "Angemon", Champion, Vaccine, angemonReq, angemonEvolutions, 5, &patamon);

    Digimon* bakemonEvolutions[4] = { &skullgreymon, &giromon, &vademon, &sukamon };
    EvolutionRequirements bakemonReq = { 0, 1000, 0, 0, 0, 100, 0, 20, 0, 0, 0, 35, true, false };
    initDigimon(&bakemon, "Bakemon", Champion, Virus, bakemonReq, bakemonEvolutions, 4, 0);

    Digimon* birdramonEvolutions[3] = { &phoenixmon, &vademon, &sukamon };
    EvolutionRequirements birdramonReq = { 0, 0, 0, 0, 100, 0, 3, 20, 0, 0, 0, 35, false, false };
    initDigimon(&birdramon, "Birdramon", Champion, Vaccine, birdramonReq, birdramonEvolutions, 3, &biyomon);

    Digimon* centarumonEvolutions[4] = { &andromon, &giromon, &vademon, &sukamon };
    EvolutionRequirements centarumonReq = { 0, 0, 0, 0, 0, 100, 3, 30, 60, 0, 0, 28, true, false };
    initDigimon(&centarumon, "Centarumon", Champion, Data, centarumonReq, centarumonEvolutions, 4, 0);

    Digimon* coelamonEvolutions[3] = { &megaseadramon, &vademon, &sukamon };
    EvolutionRequirements coelamonReq = { 0, 0, 0, 100, 0, 0, 3, 30, 0, 0, 5, 35, false, true };
    initDigimon(&coelamon, "Coelamon", Champion, Data, coelamonReq, coelamonEvolutions, 3, 0);

    Digimon* devimonEvolutions[4] = { &skullgreymon, &megadramon, &vademon, &sukamon };
    EvolutionRequirements devimonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&devimon, "Devimon", Champion, Virus, devimonReq, devimonEvolutions, 4, 0);

    Digimon* drimogemonEvolutions[3] = { &metalgreymon, &vademon, &sukamon };
    EvolutionRequirements drimogemonReq = { 0, 0, 100, 0, 0, 0, 3, 40, 0, 50, 0, 28, false, false };
    initDigimon(&drimogemon, "Drimogemon", Champion, Data, drimogemonReq, drimogemonEvolutions, 3, 0);

    Digimon* frigimonEvolutions[4] = { &metalmamemon, &mamemon, &vademon, &sukamon };
    EvolutionRequirements frigimonReq = { 0, 1000, 0, 0, 0, 100, 5, 30, 0, 50, 0, 28, true, false };
    initDigimon(&frigimon, "Frigimon", Champion, Vaccine, frigimonReq, frigimonEvolutions, 4, 0);

    Digimon* garurumonEvolutions[4] = { &skullgreymon, &megaseadramon, &vademon, &sukamon };
    EvolutionRequirements garurumonReq = { 0, 1000, 0, 0, 100, 0, 1, 30, 90, 0, 0, 28, true, false };
    initDigimon(&garurumon, "Garurumon", Champion, Vaccine, garurumonReq, garurumonEvolutions, 4, 0);

    Digimon* greymonEvolutions[4] = { &metalgreymon, &skullgreymon, &vademon, &sukamon };
    EvolutionRequirements greymonReq = { 0, 0, 100, 100, 100, 100, 1, 30, 90, 0, 0, 35, true, false };
    initDigimon(&greymon, "Greymon", Champion, Vaccine, greymonReq, greymonEvolutions, 4, 0);

    Digimon* kabuterimonEvolutions[4] = { &hkabuterimon, &metalmamemon, &vademon, &sukamon };
    EvolutionRequirements kabuterimonReq = { 1000, 1000, 100, 0, 100, 0, 1, 30, 0, 0, 0, 35, true, false };
    initDigimon(&kabuterimon, "Kabuterimon", Champion, Vaccine, kabuterimonReq, kabuterimonEvolutions, 4, &kunemon);

    Digimon* kokatorimonEvolutions[4] = { &phoenixmon, &piximon, &vademon, &sukamon };
    EvolutionRequirements kokatorimonReq = { 1000, 0, 0, 0, 0, 0, 3, 30, 0, 0, 0, 28, false, false };
    initDigimon(&kokatorimon, "Kokatorimon", Champion, Vaccine, kokatorimonReq, kokatorimonEvolutions, 4, &biyomon);

    Digimon* kuwagamonEvolutions[4] = { &hkabuterimon, &piximon, &vademon, &sukamon };
    EvolutionRequirements kuwagamonReq = { 1000, 1000, 100, 0, 100, 0, 5, 30, 0, 0, 0, 28, false, false };
    initDigimon(&kuwagamon, "Kuwagamon", Champion, Virus, kuwagamonReq, kuwagamonEvolutions, 4, &kunemon);

    Digimon* leomonEvolutions[4] = { &andromon, &mamemon, &vademon, &sukamon };
    EvolutionRequirements leomonReq = { 0, 0, 100, 0, 100, 100, 1, 20, 0, 0, 10, 35, true, false };
    initDigimon(&leomon, "Leomon", Champion, Vaccine, leomonReq, leomonEvolutions, 4, 0);

    Digimon* meramonEvolutions[4] = { &metalgreymon, &andromon, &vademon, &sukamon };
    EvolutionRequirements meramonReq = { 0, 0, 100, 0, 0, 0, 5, 20, 0, 0, 10, 28, false, false };
    initDigimon(&meramon, "Meramon", Champion, Data, meramonReq, meramonEvolutions, 4, 0);

    Digimon* mojyamonEvolutions[4] = { &skullgreymon, &mamemon, &vademon, &sukamon };
    EvolutionRequirements mojyamonReq = { 1000, 0, 0, 0, 0, 0, 5, 20, 0, 0, 5, 28, false, true };
    initDigimon(&mojyamon, "Mojyamon", Champion, Vaccine, mojyamonReq, mojyamonEvolutions, 4, 0);

    Digimon* monochromonEvolutions[4] = { &metalgreymon, &metalmamemon, &vademon, &sukamon };
    EvolutionRequirements monochromonReq = { 1000, 0, 0, 100, 0, 100, 3, 40, 0, 0, 5, 35, true, true };
    initDigimon(&monochromon, "Monochromon", Champion, Data, monochromonReq, monochromonEvolutions, 4, 0);

    Digimon* nanimonEvolutions[3] = { &digitamamon, &vademon, &sukamon };
    EvolutionRequirements nanimonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&nanimon, "Nanimon", Champion, Virus, nanimonReq, nanimonEvolutions, 3, 0);

    Digimon* ninjamonEvolutions[5] = { &piximon, &metalmamemon, &mamemon, &vademon, &sukamon };
    EvolutionRequirements ninjamonReq = { 0, 1000, 100, 0, 100, 0, 1, 10, 0, 0, 15, 35, true, false };
    initDigimon(&ninjamon, "Ninjamon", Champion, Data, ninjamonReq, ninjamonEvolutions, 5, 0);

    Digimon* numemonEvolutions[3] = { &monzaemon, &vademon, &sukamon };
    EvolutionRequirements numemonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&numemon, "Numemon", Champion, Virus, numemonReq, numemonEvolutions, 3, 0);

    Digimon* ogremonEvolutions[4] = { &andromon, &giromon, &vademon, &sukamon };
    EvolutionRequirements ogremonReq = { 1000, 0, 100, 0, 0, 0, 5, 30, 0, 0, 15, 35, false, false };
    initDigimon(&ogremon, "Ogremon", Champion, Virus, ogremonReq, ogremonEvolutions, 4, 0);

    Digimon* seadramonEvolutions[4] = { &megadramon, &megaseadramon, &vademon, &sukamon };
    EvolutionRequirements seadramonReq = { 1000, 1000, 0, 0, 0, 0, 3, 30, 0, 0, 5, 28, false, true };
    initDigimon(&seadramon, "Seadramon", Champion, Data, seadramonReq, seadramonEvolutions, 4, 0);

    Digimon* shellmonEvolutions[4] = { &hkabuterimon, &megaseadramon, &vademon, &sukamon };
    EvolutionRequirements shellmonReq = { 1000, 0, 0, 100, 0, 0, 5, 40, 0, 0, 0, 35, false, false };
    initDigimon(&shellmon, "Shellmon", Champion, Data, shellmonReq, shellmonEvolutions, 4, &betamon);

    Digimon* sukamonEvolutions[2] = { &etemon, &vademon };
    EvolutionRequirements sukamonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&sukamon, "Sukamon", Champion, Virus, sukamonReq, sukamonEvolutions, 2, 0);

    Digimon* tyrannomonEvolutions[4] = { &metalgreymon, &megadramon, &vademon, &sukamon };
    EvolutionRequirements tyrannomonReq = { 1000, 0, 0, 100, 0, 0, 5, 30, 0, 0, 5, 28, true, true };
    initDigimon(&tyrannomon, "Tyrannomon", Champion, Data, tyrannomonReq, tyrannomonEvolutions, 4, 0);

    Digimon* unimonEvolutions[4] = { &giromon, &phoenixmon, &vademon, &sukamon };
    EvolutionRequirements unimonReq = { 1000, 0, 0, 0, 100, 0, 3, 30, 0, 0, 10, 35, true, false };
    initDigimon(&unimon, "Unimon", Champion, Vaccine, unimonReq, unimonEvolutions, 4, 0);

    Digimon* vegiemonEvolutions[3] = { &piximon, &vademon, &sukamon };
    EvolutionRequirements vegiemonReq = { 0, 1000, 0, 0, 0, 0, 5, 10, 0, 50, 0, 21, false, false };
    initDigimon(&vegiemon, "Vegiemon", Champion, Virus, vegiemonReq, vegiemonEvolutions, 3, 0);

    Digimon* whamonEvolutions[4] = { &megaseadramon, &mamemon, &vademon, &sukamon };
    EvolutionRequirements whamonReq = { 1000, 0, 0, 0, 0, 100, 5, 40, 60, 0, 0, 28, true, false };
    initDigimon(&whamon, "Whamon", Champion, Vaccine, whamonReq, whamonEvolutions, 4, 0);

    Digimon* andromonEvolutions[1] = { &sukamon };
    EvolutionRequirements andromonReq = { 0, 1000, 0, 0, 100, 100, 1, 30, 90, 0, 0, 35, true, false };
    initDigimon(&andromon, "Andromon", Ultimate, Vaccine, andromonReq, andromonEvolutions, 1, 0);

    Digimon* digitamamonEvolutions[1] = { &sukamon };
    EvolutionRequirements digitamamonReq = { 3000, 3000, 400, 400, 400, 300, 0, 10, 0, 0, 100, 49, true, false };
    initDigimon(&digitamamon, "Digitamamon", Ultimate, Data, digitamamonReq, digitamamonEvolutions, 1, 0);

    EvolutionRequirements etemonReq = { 2000, 3000, 400, 200, 400, 300, 0, 15, 0, 0, 50, 49, true, false };
    initDigimon(&etemon, "Etemon", Ultimate, Virus, etemonReq, NULL, 0, 0);

    Digimon* giromonEvolutions[1] = { &sukamon };
    EvolutionRequirements giromonReq = { 0, 0, 400, 0, 300, 400, 15, 5, 0, 95, 100, 35, false, false };
    initDigimon(&giromon, "Giromon", Ultimate, Vaccine, giromonReq, giromonEvolutions, 1, 0);

    Digimon* hkabuterimonEvolutions[1] = { &sukamon };
    EvolutionRequirements hkabuterimonReq = { 7000, 0, 400, 600, 400, 0, 5, 55, 0, 0, 0, 40, true, true };
    initDigimon(&hkabuterimon, "HKabuterimon", Ultimate, Data, hkabuterimonReq, hkabuterimonEvolutions, 1, 0);

    Digimon* mamemonEvolutions[1] = { &sukamon };
    EvolutionRequirements mamemonReq = { 0, 0, 400, 300, 300, 400, 15, 5, 0, 90, 0, 25, false, false };
    initDigimon(&mamemon, "Mamemon", Ultimate, Data, mamemonReq, mamemonEvolutions, 1, 0);

    Digimon* megadramonEvolutions[1] = { &sukamon };
    EvolutionRequirements megadramonReq = { 3000, 5000, 500, 300, 400, 400, 10, 55, 0, 0, 30, 30, true, false };
    initDigimon(&megadramon, "Megadramon", Ultimate, Virus, megadramonReq, megadramonEvolutions, 1, 0);

    Digimon* megaseadramonEvolutions[1] = { &sukamon };
    EvolutionRequirements megaseadramonReq = { 0, 4000, 500, 400, 0, 400, 5, 30, 0, 0, 0, 40, true, true };
    initDigimon(&megaseadramon, "MegaSeadramon", Ultimate, Data, megaseadramonReq, megaseadramonEvolutions, 1, 0);

    Digimon* metalgreymonEvolutions[1] = { &sukamon };
    EvolutionRequirements metalgreymonReq = { 4000, 3000, 500, 500, 300, 300, 10, 65, 95, 0, 30, 30, true, false };
    initDigimon(&metalgreymon, "MetalGreymon", Ultimate, Virus, metalgreymonReq, metalgreymonEvolutions, 1, 0);

    Digimon* metalmamemonEvolutions[1] = { &sukamon };
    EvolutionRequirements metalmamemonReq = { 0, 0, 500, 400, 400, 400, 15, 10, 0, 95, 0, 30, true, false };
    initDigimon(&metalmamemon, "MetalMamemon", Ultimate, Data, metalmamemonReq, metalmamemonEvolutions, 1, 0);

    Digimon* monzaemonEvolutions[1] = { &sukamon };
    EvolutionRequirements monzaemonReq = { 3000, 3000, 300, 300, 300, 300, 0, 40, 0, 0, 50, 49, true, false };
    initDigimon(&monzaemon, "Monzaemon", Ultimate, Vaccine, monzaemonReq, monzaemonEvolutions, 1, 0);

    Digimon* phoenixmonEvolutions[1] = { &sukamon };
    EvolutionRequirements phoenixmonReq = { 4000, 4000, 0, 0, 400, 600, 3, 30, 100, 0, 0, 40, true, true };
    initDigimon(&phoenixmon, "Phoenixmon", Ultimate, Vaccine, phoenixmonReq, phoenixmonEvolutions, 1, 0);

    Digimon* piximonEvolutions[1] = { &sukamon };
    EvolutionRequirements piximonReq = { 0, 0, 300, 300, 400, 400, 15, 5, 0, 95, 0, 25, false, false };
    initDigimon(&piximon, "Piximon", Ultimate, Data, piximonReq, piximonEvolutions, 1, 0);
    
    Digimon* skullgreymonEvolutions[1] = { &sukamon };
    EvolutionRequirements skullgreymonReq = { 4000, 6000, 400, 400, 200, 500, 10, 30, 0, 0, 40, 45, false, false };
    initDigimon(&skullgreymon, "SkullGreymon", Ultimate, Virus, skullgreymonReq, skullgreymonEvolutions, 1, 0);
    
    EvolutionRequirements vademonReq = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false };
    initDigimon(&vademon, "Vademon", Ultimate, Virus, vademonReq, NULL, 0, 0);

}