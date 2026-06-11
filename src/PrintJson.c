#include "PrintJson.h"
#include <stdio.h>
#include <string.h>

#define INDENT_LENGTH 4

void printIndents(int indent_level){
    for(int i = 0; i < indent_level * INDENT_LENGTH; i++){
        printf(" ");
    }
}

void printJson(bool* in_string_literal, int *indent_level, char *json_string){
    size_t json_length = strlen(json_string);

    for(int i = 0; i < json_length; i++){
        if(!(*in_string_literal)){
            switch (json_string[i]) {
                case '{':
                    printf("{\n");
                    *indent_level += 1;
                    printIndents(*indent_level);
                break;

                case '}':
                    printf("\n}\n");
                    *indent_level -= 1;
                    printIndents(*indent_level);
                break;

                case '[':
                    printf("[\n");
                    *indent_level += 1;
                    printIndents(*indent_level);
                break;

                case ']':
                    *indent_level -= 1;
                    printf("\n");
                    printIndents(*indent_level);
                    printf("]");
                break;

                case '"':
                    printf("\"");
                    *in_string_literal = true;
                break;

                case ',':
                    printf(",\n");
                    printIndents(*indent_level);
                break;

                case ':':
                    printf(": ");
                break;

                default:
                    printf("%c", json_string[i]);
                break;
            } 

        } else { // if(in_string_literal)
            if(json_string[i] == '"'){
                *in_string_literal = false;
            }
            printf("%c", json_string[i]);
        }
    }
}
