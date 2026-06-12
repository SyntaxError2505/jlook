#include "PrintChar.h"

#include <stdio.h>

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\e[0;34m"

#define ANSI_COLOR_RESET "\x1b[0m"

void printChar(char c, enum Color color){
    switch (color) {
        case STRING_LITERAL:
        printf("%s%c%s", ANSI_COLOR_GREEN, c, ANSI_COLOR_RESET);
        break;

        case NUMBER_LITERAL:
        printf("%s%c%s", ANSI_COLOR_BLUE, c, ANSI_COLOR_RESET);
        break;

        case OTHER:
        printf("%c", c);
        break;

        default:
        printf("UNKNOWN COLOR");
        break;
    }
}
