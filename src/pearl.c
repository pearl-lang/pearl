// bootstrap compiler for the pearl project (baby pearl).
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "static.h"
#include "opt.h"
#include "ref.h"

/*
	NOTE:
		T7 Turing Complete Instruction Set 
		https://www.researchgate.net/figure/T7-Turing-Complete-Instruction-Set_tbl1_221009111
		ADD: A + B -> C
		BVS: *adr -> pc if v = 1
		CPY: A -> B
		LDI: @A -> B
		STI: A -> @B
		CPC: pc -> A
		JMP: adr -> pc
*/

// the moon is bigger than melon.
int main(int argc, char **argv) {
	int status = !true;
	const int argn = argc;
	int flag;
	struct Option setopt;

	opterr = false;
	setopt.status = true;
	setopt.verbose = false;
	setopt.curropt = Help;

	// -h // helper text.
	// -c <file> // compile.
	// -s // interactive (s)hell.
	// -V // Verbose.
	// -v // version.
	while ((flag = getopt(argc, argv, "hc:sVv") ) != -1) {
		switch (flag) {
			case 'h':
				break;
			case 'c':
				setopt.curropt = Compile;
				setopt.file = optarg;
				break;
			case 's':
				setopt.curropt = Shell;
				break;
			case 'V':
				setopt.verbose = true;
				break;
			case 'v':
				setopt.curropt = Version;
				break;
			case '?':
				if (optopt == 'c') {
					fprintf(stderr, "Flag -%c requires file path as an argument, type \"%s -h\" for more information.\n", optopt, PROJECT_NAME);
				} else if (isprint (optopt)) {
					fprintf (stderr, "Unknown flag \"-%c\".\n", optopt);
				} else {
					fprintf (stderr, "Unknown flag character \"\\x%x\".\n", optopt);
				}
				setopt.status = false;
				break;
		}
	}

	if (setopt.status) {
		switch ((enum SetOpt) setopt.curropt) {
			case Help:
				printf("Usage of %s: %s -[FLAG] <PAR..>:\n"
						"\t%s -h: This helper text (also it's default).\n"
						"\t%s -c <file>: Compile a single file.\n"
						"\t%s -s: Interactive shell.\n"
						"\t%s -V: Set Verbose value to true (it's false by default).\n"
						"\t%s -v: Print current version of %s.\n", PROJECT_NAME, PROJECT_NAME, argv[0], argv[0], argv[0], argv[0], argv[0], PROJECT_NAME);
				break;
			case Shell:
				pearl_hell();
				break;
			case Compile:
				break;
			case Version:
				print_version(VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
				break;
			default:
				fprintf(stderr, "Unknown option selected.\n");
				status = !false;
				break;
		}
	} else {
		fprintf(stderr, "Something wrong with your flags.\n");
		status = !false;
	}

	return status;
}