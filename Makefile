INCLUDED := lib
OUTPUT := pearl
CC := gcc

build:
	$(CC) -I $(INCLUDED) -o $(OUTPUT)

clean:
	
.PHONY: build clean
