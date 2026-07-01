CFLAGS := -std=c17 -Wall -Wextra
TARGET := jlook

SOURCE = $(shell find "src" -type f -name "*.c")

DEBUG ?= 1
PREFIX ?= /usr/local/bin
CC := cc

ifeq ($(DEBUG), 1)
	CFLAGS += -g -O0
else 
	CFLAGS += -O3
endif

default: $(TARGET)

$(TARGET): $(SOURCE)
	gcc -o $(TARGET) $(CFLAGS) $(SOURCE)

install: $(TARGET)
	cp $(TARGET) $(PREFIX)

uninstall:
	rm -f $(shell which $(TARGET))

.PHONY: clean
clean:
	rm -f $(TARGET)
