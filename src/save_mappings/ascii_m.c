#include "ascii_m.h"

// Initialize the mapping
HexAsciiMap hexAsciiMapping[] = {
    {0x8140, ' '}, {0x8142, '.'}, {0x8143, ','}, {0x8146, ':'}, {0x8147, ';'},
    {0x8148, '?'}, {0x8149, '!'}, {0x815F, '\\'}, {0x8175, '\''}, {0x8176, '\"'},
    {0x817B, '+'}, {0x817C, '-'}, {0x817E, '^'}, // Representing <TRIANGLE> as '^'
    {0x8181, '='}, {0x819B, 'o'}, // Representing <CIRCLE> as 'o'
    {0x81A0, '#'}, // Representing <SQUARE> as '#'
    {0x81A2, 'x'}, // Representing <CROSS> as 'x'
    {0x824F, '0'}, {0x8250, '1'}, {0x8251, '2'}, {0x8252, '3'}, {0x8253, '4'},
    {0x8254, '5'}, {0x8255, '6'}, {0x8256, '7'}, {0x8257, '8'}, {0x8258, '9'},
    {0x8260, 'A'}, {0x8261, 'B'}, {0x8262, 'C'}, {0x8263, 'D'}, {0x8264, 'E'},
    {0x8265, 'F'}, {0x8266, 'G'}, {0x8267, 'H'}, {0x8268, 'I'}, {0x8269, 'J'},
    {0x826A, 'K'}, {0x826B, 'L'}, {0x826C, 'M'}, {0x826D, 'N'}, {0x826E, 'O'},
    {0x826F, 'P'}, {0x8270, 'Q'}, {0x8271, 'R'}, {0x8272, 'S'}, {0x8273, 'T'},
    {0x8274, 'U'}, {0x8275, 'V'}, {0x8276, 'W'}, {0x8277, 'X'}, {0x8278, 'Y'},
    {0x8279, 'Z'}, {0x8281, 'a'}, {0x8282, 'b'}, {0x8283, 'c'}, {0x8284, 'd'},
    {0x8285, 'e'}, {0x8286, 'f'}, {0x8287, 'g'}, {0x8288, 'h'}, {0x8289, 'i'},
    {0x828A, 'j'}, {0x828B, 'k'}, {0x828C, 'l'}, {0x828D, 'm'}, {0x828E, 'n'},
    {0x828F, 'o'}, {0x8290, 'p'}, {0x8291, 'q'}, {0x8292, 'r'}, {0x8293, 's'},
    {0x8294, 't'}, {0x8295, 'u'}, {0x8296, 'v'}, {0x8297, 'w'}, {0x8298, 'x'},
    {0x8299, 'y'}, {0x829A, 'z'}
};

// Define a constant for the number of mappings
const int ascii_m_SIZE = sizeof(hexAsciiMapping) / sizeof(HexAsciiMap);

char bytesToAsciiChar(int byte1, int byte2) {
    int val = (byte1 << 8) | byte2;
    for (int i = 0; i < ascii_m_SIZE; i++) {
        if (hexAsciiMapping[i].hexValue == val) {
            return hexAsciiMapping[i].asciiChar;
        }
    }
    return hexAsciiMapping[0x8148].asciiChar; // return ?
}

void wordsArrayToString(int words[], int size, char *outputString) {
    for (int i = 0; i < size; i++) {
        int highByte = (words[i] >> 8) & 0xFF;
        int lowByte = words[i] & 0xFF;
        *outputString++ = bytesToAsciiChar(highByte, lowByte);
    }
    *outputString = '\0'; // Null-terminate the string
}