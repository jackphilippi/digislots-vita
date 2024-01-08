#ifndef ASCII_M_H_
#define ASCII_M_H_

// Define a structure to hold the mapping
typedef struct {
    unsigned int hexValue;
    char asciiChar;
} HexAsciiMap;

extern HexAsciiMap hexAsciiMapping[];
extern const int ascii_m_SIZE;

char bytesToAsciiChar(int byte1, int byte2);
void wordsArrayToString(int words[], int size, char *outputString);

#endif // ascii_m_H