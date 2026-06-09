sourceFiles := src/main.c
compilerArgs := -std=c17

default: main

main: $(sourceFiles)
	gcc -o main $(compilerArgs) $(sourceFiles)
