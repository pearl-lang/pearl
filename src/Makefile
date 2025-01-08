CC := gcc
PAR := -o
CFLAGS := -Wall
SRC := $(wildcard *.c)
BIN := $(patsubst %.c,%,$(SRC))

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $(PAR) $@ $<

clean:
	rm -vf $(BIN)

.PHONY: all clean
