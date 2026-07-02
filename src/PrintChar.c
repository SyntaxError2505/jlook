#include "PrintChar.h"

#include <stdio.h>

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\e[0;34m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_ORANGE "\x1b[38;5;208m"
#define ANSI_COLOR_GRAY "\033[90m"

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

        case BRACKETS_1:
        printf("%s%c%s", ANSI_COLOR_YELLOW, c, ANSI_COLOR_RESET);
        break;

        case BRACKETS_2:
        printf("%s%c%s", ANSI_COLOR_CYAN, c, ANSI_COLOR_RESET);
        break;

        case BRACKETS_3:
        printf("%s%c%s", ANSI_COLOR_ORANGE, c, ANSI_COLOR_RESET);
        break;

        case COMMENT:
        printf("%s%c%s", ANSI_COLOR_GRAY, c, ANSI_COLOR_RESET);
        break;

        default:
        printf("UNKNOWN COLOR");
        break;
    }
}
