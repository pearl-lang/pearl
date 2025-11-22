#ifndef PEARL_H
#define PEARL_H

// General definitions
#define PEARL_VERSION "0.1.0"

// Backend types
#define BACKEND_LLVM 0

typedef struct {
    const char *source_file;
    const char *output_file;
    int backend; // 0 = LLVM
} pearl_config_t;

#endif // PEARL_H