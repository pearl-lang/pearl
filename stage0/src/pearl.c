#include <stdio.h>
#include "pearl.h"

void help() {
    printf("Pearl Programming Language Compiler\n");
    printf("Usage: pearl [options] <source_file>\n");
    printf("Options:\n");
    printf("  -h, --help       Show this help message\n");
    printf("  -V, --version    Show version information\n");
}

void short_help() {
    printf("Usage: pearl [options] <source_file>\n");
    printf("Options:\n");
    printf("   -h   Show this help message\n");
    printf("   -V   Show version information\n");
}