LEX := flex
SRC := $(wildcard *.l)
OUT := $(patsubst %.l,%.c,$(SRC))

all: $(OUT)

%.c: %.l
	$(LEX) -o $@ $<

clean:
	rm -vf $(OUT)

.PHONY: all clean
