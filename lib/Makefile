LEX := flex
SRC := $(wildcard *.l)

all:

analyzer:
	gcc -Wall -Wextra -fanalyzer -o program *.c

clean:
	rm -vf $(OUT) program

.PHONY: all clean
