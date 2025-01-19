#include <stdio.h>
#include <stdlib.h>
#include "static.h"
#include "opt.h"

int main(int argc, char **argv) {
	int status = STATUS;
	const int argn = argc;

	for (; argc--; argv++)
		printf("[%d] %s\n", (argn - argc), *argv);

	return status;
}
