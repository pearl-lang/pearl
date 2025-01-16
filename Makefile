PREFIX := .
SUB := lib src

all: $(SUB)
build: $(SUB)
clean: $(SUB)
analyzer: $(SUB)

$(SUB):
ifeq ($(MAKECMDGOALS),)
	$(MAKE) -C $@
else
	$(MAKE) $(MAKECMDGOALS) -C $@
endif


.PHONY: all build clean analyzer setup unsetup $(SUB)
