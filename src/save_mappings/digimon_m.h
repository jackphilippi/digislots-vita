// digimon_m.h
#ifndef DIGIMON_M_H_
#define DIGIMON_M_H_

typedef struct {
    unsigned int value;
    const char* name;
} DigimonMapping;

extern DigimonMapping digimonMap[];
extern const int digimon_m_SIZE;

char* getDigimonName(unsigned int searchId);

#endif // digimon_m_H
