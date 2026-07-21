#include <stdbool.h>

#include "Args.h"
#include "PrintJson.h"

int main(int argc, char **argv) {
    struct Args args;
    parseArgs(&args, argc, argv);

    int indent_level = 0;
    bool in_string_literal = false;

    printJson(&in_string_literal, &indent_level, &args);

    return 0;
}
