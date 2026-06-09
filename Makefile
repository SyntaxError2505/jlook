PREFIX ?= /usr/local/bin

sourceFiles := src/main.c
compilerArgs := -std=c17

default: jlook

jlook: $(sourceFiles)
	gcc -o jlook $(compilerArgs) $(sourceFiles)

install: jlook
	cp jlook $(PREFIX)

uninstall:
	rm -f $(PREFIX)/jlook

clean:
	rm -f jlook
