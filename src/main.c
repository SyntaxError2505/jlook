#define BUFFER_LENGTH 1024

#include <stdio.h>
#include <stdbool.h>

#include "PrintJson.h"


int main(int argc, char **argv){
    char json_string[BUFFER_LENGTH];
    fgets(json_string, BUFFER_LENGTH, stdin);

    int indent_level = 0;
    bool in_string_literal = false;

    printJson(&in_string_literal, &indent_level, json_string);

    return 0;
}
