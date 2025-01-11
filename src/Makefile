CC := gcc
PAR := -o
CFLAGS := -Wall
SRC := $(wildcard *.c)
BIN := $(patsubst %.c,%,$(SRC))

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $(PAR) $@ $<

analyzer:
	gcc -Wall -Wextra -fanalyzer -o program *.c

clean:
	rm -vf $(BIN) program

.PHONY: all clean
