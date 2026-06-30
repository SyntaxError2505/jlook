#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "PrintJson.h"
#include "PrintChar.h"

#define INDENT_LENGTH 4

void printIndents(int indent_level, int length){
    for(int i = 0; i < indent_level * length; i++){
        printf(" ");
    }
}

void printJson(bool* in_string_literal, int *indent_level, char *json_string, int indent_length, bool color){
    size_t json_length = strlen(json_string);

    for(size_t i = 0; i < json_length; i++){
        if(!(*in_string_literal)){
            switch (json_string[i]) {
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
                    if (json_string[++i] == ',') {
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
                    if ((json_string[i] >= '0' && json_string[i] <= '9') || json_string[i] == '.') {
                        printChar(json_string[i], color ? NUMBER_LITERAL : OTHER);
                    } else {
                        printChar(json_string[i], OTHER);
                    }
                break;
            } 

        } else { // if(in_string_literal)
            if(json_string[i] == '"'){
                *in_string_literal = false;
            }
            printChar(json_string[i], color ? STRING_LITERAL : OTHER);
        }
    }
}
