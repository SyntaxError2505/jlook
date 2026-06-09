#include <stdio.h>
int main(int argc, char **argv){
    char json_string[1024];
    fgets(json_string, 1024, stdin);

    printf("%s\n", json_string);

    return 0;
}
