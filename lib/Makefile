LEX := flex
SRC := $(wildcard *.l)
OUT := $(patsubst %.l,%.c,$(SRC))

all: $(OUT)

%.c: %.l
	$(LEX) -o $@ $<

analyzer:
	gcc -Wall -Wextra -fanalyzer -o program *.c

clean:
	rm -vf $(OUT) program

.PHONY: all clean
