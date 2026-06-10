#define INDENT_LENGTH 4
#define BUFFER_LENGTH 1024

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static void print_indents(int indent_level){
    for(int i = 0; i < indent_level * INDENT_LENGTH; i++){
        printf(" ");
    }
}

int main(int argc, char **argv){
    char json_string[BUFFER_LENGTH];
    fgets(json_string, BUFFER_LENGTH, stdin);

    int indent_level = 0;
    int json_length = strlen(json_string);
    bool in_string_literal = false;

    for(int i = 0; i < json_length; i++){
        if(!in_string_literal){
        switch (json_string[i]) {
            case '{':
            printf("{\n");
            indent_level++;
            print_indents(indent_level);
            break;

            case '}':
            printf("\n}\n");
            indent_level--;
            print_indents(indent_level);
            break;

            case '[':
            printf("[\n");
            indent_level++;
            print_indents(indent_level);
            break;

            case ']':
            indent_level--;
            printf("\n");
            print_indents(indent_level);
            printf("]");
            break;

            case '"':
            printf("\"");
            in_string_literal = true;
            break;

            case ',':
            printf(",\n");
            print_indents(indent_level);
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
                in_string_literal = false;
            }
            printf("%c", json_string[i]);
        }
    }
    return 0;
}
