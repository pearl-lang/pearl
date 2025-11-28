#ifndef PEARL_H
#define PEARL_H

#include "vector.h"

// General definitions
#define PEARL_VERSION "0.1.0"

// Backend types
#define BACKEND_LLVM 0
#define BACKEND_PIRE 1 // Pearl Intermediate Representation

// Verbosity levels
#define PEARL_VERBOSITY_SILENT  0
#define PEARL_VERBOSITY_ERROR   1
#define PEARL_VERBOSITY_WARNING 2
#define PEARL_VERBOSITY_INFO    3
#define PEARL_VERBOSITY_DEBUG   4

extern int pearl_verbosity_level;

typedef struct {
    vector_t   *source_file;
    const char *output_file;
    int         backend; // 0 = LLVM
} pearl_config_t;

void help();
void short_help();
void pearl_set_verbosity();

#endif // PEARL_H