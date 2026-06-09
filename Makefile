sourceFiles := src/main.c

default: main

main:
	gcc -o main $(sourceFiles)
