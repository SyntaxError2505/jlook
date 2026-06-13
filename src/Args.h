#ifndef ARGS_H
#define ARGS_H

#include <stdbool.h>

struct Args {
    int indent_length;
    bool color;
};

void parseArgs(struct Args *args, int argc, char** argv);

#endif
