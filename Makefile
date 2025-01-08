,PREFIX := .
SUB := src lib

all: $(SUB)

build: $(SUB)

clean: $(SUB)

$(SUB):
ifeq ($(MAKECMDGOALS),)
	$(MAKE) -C $@
else
	$(MAKE) $(MAKECMDGOALS) -C $@
endif

.PHONY: all build clean $(SUB)
