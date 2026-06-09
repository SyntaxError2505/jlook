#include <string.h>
#define INDENT_LENGTH 4
#define BUFFER_LENGTH 1024

#include <stdio.h>

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

    for(int i = 0; i < json_length; i++){
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
            printf("]\n");
            indent_level--;
            print_indents(indent_level);
            break;

            case ',':
            printf(",\n");
            print_indents(indent_level);
            break;

            case ':':
            printf(":");
            if(json_string[i+1] != ' ') printf(" ");
            break;

            default:
            printf("%c", json_string[i]);
            break;
        }
    }

    return 0;
}
