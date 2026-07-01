#include "ReadPipe.h"

#include <stdio.h>

char readPipe(){
    char c = getchar();
    return c == EOF ? 0 : c;
}
