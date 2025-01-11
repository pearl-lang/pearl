CC := gcc
PAR := -o
CFLAGS := -Wall
SRC := $(wildcard *.c)
BIN := $(patsubst %.c,%,$(SRC))

all: $(BIN)

%: %.c
	ln -vfs ../lib
	$(CC) $(CFLAGS) $(PAR) $@ $<

analyzer:
	ln -vfs ../lib
	gcc -Wall -Wextra -fanalyzer -o program *.c

clean:
	rm -vf $(BIN) program lib

.PHONY: all clean
