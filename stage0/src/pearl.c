#include <stdio.h>
#include "pearl.h"

int pearl_verbosity_level = PEARL_VERBOSITY_SILENT;

void help() {
    printf("Pearl Programming Language Compiler\n");
    printf("Usage: pearl [options] <source_file> <source_file>..\n");
    printf("Options:\n");
    printf("  -h, --help                Show this help message\n");
    printf("  -V, --version             Show version information\n");
    printf("  -o, --output  <file>      Specify output file name\n");
    printf("  -b, --backend <backend>   Specify backend (llvm or pire)\n");
    printf("  -v                        Increase verbosity level (can be used multiple times)\n");
    printf("https://github.com/pearl-lang - 2025\n");
}

void short_help() {
    printf("Usage: pearl [options] <source_file> <source_file>..\n");
    printf("Options:\n");
    printf("   -h        Show this help message\n");
    printf("   -V        Show version information\n");
    printf("   -o <par>  Specify output file name\n");
    printf("   -b <par>  Specify backend (llvm or pire)\n");
    printf("   -v        Increase verbosity level (can be used multiple times)\n");
}

void pearl_set_verbosity() {
    if (pearl_verbosity_level < PEARL_VERBOSITY_DEBUG) {
        pearl_verbosity_level++;
    }
}