#ifndef PRINT_CHAR_H
#define PRINT_CHAR_H

enum Color {
    STRING_LITERAL,
    NUMBER_LITERAL,
    BRACKETS_1,
    BRACKETS_2,
    BRACKETS_3,
    COMMENT,
    OTHER,
};

void printChar(char c, enum Color color);

#endif
