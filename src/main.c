#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "PrintJson.h"
#include "ReadPipe.h"


int main(int argc, char **argv){
    char* json_string = readPipe();
    if(json_string == NULL){
        fprintf(stderr, "JLOOK: ALLOCATING JSON FAILED, CHECK IF YOU HAVE ENOUGH RAM\n");
        return -1;
    }

    int indent_level = 0;
    bool in_string_literal = false;

    printJson(&in_string_literal, &indent_level, json_string);

    free(json_string);

    return 0;
}
