#ifndef PRINT_JSON_H
#define PRINT_JSON_H

#include <stdbool.h>

void printJson(bool* in_string_literal, int* indent_level, char* json_string, int indent_length, bool color);
void printIndents(int indent_level);

#endif
