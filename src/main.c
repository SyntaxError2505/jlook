#include <stdbool.h>

#include "PrintJson.h"
#include "ReadPipe.h"


int main(int argc, char **argv){
    char* json_string = readPipe();

    int indent_level = 0;
    bool in_string_literal = false;

    printJson(&in_string_literal, &indent_level, json_string);

    return 0;
}
