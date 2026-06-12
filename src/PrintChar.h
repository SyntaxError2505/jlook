#ifndef PRINT_CHAR_H
#define PRINT_CHAR_H

enum Color {
    STRING_LITERAL,
    NUMBER,
    BRACKETS_1,
    BRACKETS_2,
    BRACKETS_3,
};

void printChar(char c, Color color);

#endif
