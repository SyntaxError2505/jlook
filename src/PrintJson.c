#include <stddef.h>
#include <stdio.h>

#include "PrintJson.h"
#include "PrintChar.h"
#include "ReadPipe.h"

#define INDENT_LENGTH 4

void printIndents(int indent_level, int length){
    for(int i = 0; i < indent_level * length; i++){
        printf(" ");
    }
}

void printJson(bool* in_string_literal, int *indent_level, int indent_length, bool color){
    while(1) {
        char c = readPipe();
        if(c == 0) break;
        if(!(*in_string_literal)){
            switch (c) {
                case '{':
                    printChar('{', BRACKETS_1 + *indent_level);
                    printChar('\n', OTHER);
                    (*indent_level)++;
                    printIndents(*indent_level, indent_length);
                break;

                case '}':
                    *indent_level -= 1;
                    printf("\n");
                    printIndents(*indent_level, indent_length);
                    printChar('}', BRACKETS_1 + *indent_level);
                    if (readPipe() == ',') {
                        printChar(',', OTHER);
                    }
                    printChar('\n', OTHER);
                    printIndents(*indent_level, indent_length);

                break;

                case '[':
                    printChar('[', BRACKETS_1 + *indent_level);
                    printChar('\n', OTHER);
                    (*indent_level)++;
                    printIndents(*indent_level, indent_length);
                break;

                case ']':
                    *indent_level -= 1;
                    printf("\n");
                    printIndents(*indent_level, indent_length);
                    printChar(']', BRACKETS_1 + *indent_level);
                break;

                case '"':
                    printChar('"', color ? STRING_LITERAL : OTHER);
                    *in_string_literal = true;
                break;

                case ',':
                    printf(",\n");
                    printIndents(*indent_level, indent_length);
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
                        printChar(c, color ? NUMBER_LITERAL : OTHER);
                    } else {
                        printChar(c, OTHER);
                    }
                break;
            } 

        } else { // if(in_string_literal)
            if(c == '"'){
                *in_string_literal = false;
            }
            printChar(c, color ? STRING_LITERAL : OTHER);
        }
    }
}
