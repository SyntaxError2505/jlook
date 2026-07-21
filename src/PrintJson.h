#ifndef PRINT_JSON_H
#define PRINT_JSON_H

#include <stdbool.h>

#include "Args.h"

void printJson(bool *in_string_literal, int *indent_level, struct Args *args);
void printIndents(int indent_level, int length);

#endif
