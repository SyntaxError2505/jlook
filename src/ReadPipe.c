#include "ReadPipe.h"

#include <stdio.h>
#include <stdlib.h>

char* readPipe(){
    int capacity = 4096;
    int length = 0;

    char* buffer = malloc(capacity);
    if(!buffer){
        return NULL;
    }

    int c;
    while ((c = getchar()) != EOF) {
        if (length + 1 >= capacity) {
            capacity *= 2;
            char *tmp = realloc(buffer, capacity);
            if (!tmp) {
                free(buffer);
                return NULL;
            }
            buffer = tmp;
        }

        buffer[length++] = (char)c;
    }

    buffer[length] = 0;
    return buffer;
}
