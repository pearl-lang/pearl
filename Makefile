PREFIX := .
SUB := src lib

$(SUB):
ifeq ($(MAKECMDGOALS),)
	$(MAKE) -C $@
else
	$(MAKE) $(MAKECMDGOALS) -C $@
endif

all: $(SUB)
build: $(SUB)
clean: $(SUB)
analyzer: $(SUB)

.PHONY: all build clean analyzer $(SUB)
