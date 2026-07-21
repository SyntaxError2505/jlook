#include "Args.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../config.h"

static void printHelp() {
    printf("JLOOK - a pipeable json prettyfier\n\n"
           "jlook [args]\n"
           "Args:\n"
           "  -h --help:       Print this page and exit\n"
           "  -i [length]:     Set length of indents to [length]. Space in "
           "between arg and variable is required\n"
           "  -nc --no-color:  Print without syntax coloring, good for piping "
           "into other programs without support for color\n"
           "  -v --version     Print version number and exit\n");
}
void parseArgs(struct Args *args, int argc, char **argv) {
    args->color = true;
    args->indent_length = 4;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            i++;
            if (i > argc - 1) {
                printf("JLOOK: -i requires to be followed by a number. "
                       "Stopping\n");
                exit(-1);
            }
            args->indent_length = atoi(argv[i]);
            continue;
        } else if (strcmp(argv[i], "-h") == 0 ||
                   strcmp(argv[i], "--help") == 0) {
            printHelp();
            exit(0);
        } else if (strcmp(argv[i], "-nc") == 0 ||
                   strcmp(argv[i], "--no-color") == 0) {
            args->color = false;
            continue;
        } else if (strcmp(argv[i], "-v") == 0 ||
                   strcmp(argv[i], "--version") == 0) {
            printf("Jlook version: %s\n", JLOOK_VERSION);
            exit(0);
        } else {
            printf(
                "Unknown Argument: \"%s\". Ignoring and continuing execution\n",
                argv[i]);
        }
    }
}
