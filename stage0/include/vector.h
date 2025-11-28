#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void   *data;
    size_t  element_size;
    size_t  count;
    size_t  capacity;
} vector_t;

void vector_init(vector_t *vec, size_t element_size);
void vector_free(vector_t *vec);
bool vector_push_back(vector_t *vec, const void *element);
void* vector_get(vector_t *vec, size_t index);
size_t vector_size(vector_t *vec);

#endif // VECTOR_H