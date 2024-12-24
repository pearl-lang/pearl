PREFIX := /usr
LIBDIR := lib
SRCDIR := src
COMPLR := gcc
OUTDIR := build
PARAMS := --help
OUT := $(OUTDIR)/pearl

all: lib build install

lib:
	ln -vfs ../$(LIBDIR) $(SRCDIR)

build:
	mkdir -p $(OUTDIR)
	$(COMPLR) $(SRCDIR)/pearl.c -o $(OUT)

install:

clean:
	rm -rvf $(OUTDIR)

run:
	$(OUT) $(PARAMS)

.PHONY: all lib build install clean
