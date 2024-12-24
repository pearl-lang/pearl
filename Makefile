PREFIX := /usr
LIBDIR := lib
SRCDIR := src
COMPLR := gcc
OUTDIR := build
PARAMS := --help
OUT := $(OUTDIR)/pearl

all: build install

build:
	mkdir -p $(OUTDIR)
	ln -vfs ../$(LIBDIR) $(SRCDIR)
	$(COMPLR) $(SRCDIR)/pearl.c -o $(OUT)

install:

clean:
	rm -rvf $(OUTDIR)

run:
	$(OUT) $(PARAMS)

.PHONY: all build install clean
