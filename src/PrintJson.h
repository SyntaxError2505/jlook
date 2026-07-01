#ifndef PRINT_JSON_H
#define PRINT_JSON_H

#include <stdbool.h>

void printJson(bool* in_string_literal, int* indent_level, int indent_length, bool color);
void printIndents(int indent_level, int length);

#endif
