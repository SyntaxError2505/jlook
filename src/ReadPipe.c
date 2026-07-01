#include "ReadPipe.h"

#include <stdio.h>

// returns 0 if EOF
char readPipe(){
    char c = getchar();
    return c == EOF ? 0 : c;
}
