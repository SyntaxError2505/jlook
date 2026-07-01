#include "Args.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void printHelp(){
printf("\
JLOOK - a pipeable json prettyfier\
\njlook [args]\
\nArgs:\
\n-h --help:      Print this page and exit\
\n-nc --no-color: Print without syntax coloring, good for piping into other programs without support for color\
\n-i [length]:    Set length of indents to [length]. Space in between arg and variable is required\
\n\
");
} // printHelp

void parseArgs(struct Args *args, int argc, char** argv){
    args->color = true;
    args->indent_length = 4;

    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-i") == 0){
            i++;
            if(i > argc - 1){
                printf("JLOOK: -i requires to be followed by a number\n");
                exit(-1);
            }
            args->indent_length = atoi(argv[i]);
            continue;
        }

        if(strcmp(argv[i], "-nc") == 0 || strcmp(argv[i], "--no-color") == 0){
            args->color = false;
            continue;
        }

        if(strcmp(argv[i], "--help") == 0 || strcmp(argv[1], "-h") == 0){
            printHelp();
            exit(0);
        }
    }
}
