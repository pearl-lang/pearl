#include "vector.h"
#include <stdlib.h>
#include <string.h>

void vector_init(vector_t *vec, size_t element_size) {
    vec->data = NULL;
    vec->element_size = element_size;
    vec->count = 0;
    vec->capacity = 0;
}

void vector_free(vector_t *vec) {
    free(vec->data);
    vec->data = NULL;
    vec->count = 0;
    vec->capacity = 0;
}

bool vector_push_back(vector_t *vec, const void *element) {
    if (vec->count == vec->capacity) {
        size_t new_capacity = vec->capacity == 0 ? 1 : vec->capacity * 2;
        void *new_data = realloc(vec->data, new_capacity * vec->element_size);
        if (!new_data) {
            return false;
        }
        vec->data = new_data;
        vec->capacity = new_capacity;
    }
    memcpy((char*)vec->data + vec->count * vec->element_size, element, vec->element_size);
    vec->count++;
    return true;
}

void* vector_get(vector_t *vec, size_t index) {
    if (index >= vec->count) {
        return NULL;
    }
    return (char*)vec->data + index * vec->element_size;
}

size_t vector_size(vector_t *vec) {
    return vec->count;
}