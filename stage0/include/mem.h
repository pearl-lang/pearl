#ifdef MEM_H
#define MEM_H

typedef unsigned long usize;
typedef unsigned char u8;

typedef struct {
    uint8_t *buffer;
    size_t capacity;
    size_t offset;
} Arena;

Arena *arena_create(size_t initial_capacity);
void *arena_alloc(Arena *arena, size_t size);
void arena_reset(Arena *arena);
void arena_destroy(Arena *arena);

#endif // MEM_H