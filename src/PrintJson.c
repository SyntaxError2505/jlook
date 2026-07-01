#include <stdio.h>
#include "PrintJson.h"
#include "PrintChar.h"
#include "ReadPipe.h"
#include "Args.h"

#define INDENT_LENGTH 4

void printIndents(int indent_level, int length){
    for(int i = 0; i < indent_level * length; i++){
        printf(" ");
    }
}

void printJson(bool* in_string_literal, int *indent_level, struct Args *args){
    while(1) {
        char c = readPipe();
        if(c == 0) break;
        if(!(*in_string_literal)){
            switch (c) {
                case '{':
                    printChar('{', args->color ? BRACKETS_1 + *indent_level : OTHER);
                    printChar('\n', OTHER);
                    (*indent_level)++;
                    printIndents(*indent_level, args->indent_length);
                break;

                case '}':
                    *indent_level -= 1;
                    printf("\n");
                    printIndents(*indent_level, args->indent_length);
                    printChar('}', args->color ? BRACKETS_1 + *indent_level : OTHER);
                    if (readPipe() == ',') {
                        printChar(',', OTHER);
                    }
                    printChar('\n', OTHER);
                    printIndents(*indent_level, args->indent_length);

                break;

                case '[':
                    printChar('[', args->color ? BRACKETS_1 + *indent_level : OTHER);
                    printChar('\n', OTHER);
                    (*indent_level)++;
                    printIndents(*indent_level, args->indent_length);
                break;

                case ']':
                    *indent_level -= 1;
                    printf("\n");
                    printIndents(*indent_level, args->indent_length);
                    printChar(']', args->color ? BRACKETS_1 + *indent_level : OTHER);
                break;

                case '"':
                    printChar('"', args->color ? STRING_LITERAL : OTHER);
                    *in_string_literal = true;
                break;

                case ',':
                    printf(",\n");
                    printIndents(*indent_level, args->indent_length);
                break;

                case ':':
                    printf(": ");
                break;

                case ' ':
                break;
                case '\n':
                break;

                default:
                    if ((c >= '0' && c <= '9') || c == '.') {
                        printChar(c, args->color ? NUMBER_LITERAL : OTHER);
                    } else {
                        printChar(c, OTHER);
                    }
                break;
            } 

        } else { // if(in_string_literal)
            if(c == '"'){
                *in_string_literal = false;
            }
            printChar(c, args->color ? STRING_LITERAL : OTHER);
        }
    }
}
