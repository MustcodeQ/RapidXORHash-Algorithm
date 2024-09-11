// src/rapid_xor_hash.c
#include "rapid_xor_hash.h"
#include <string.h>

#define RAPID_OFFSET_BASIS_64 14695981039346656037ULL
#define RAPID_PRIME_64 1099511628211ULL
#define FINAL_XOR_CONSTANT 0xC6A4A7935BD1E995ULL

uint64_t rapid_xor_hash(const char *key)
{
    uint64_t hash = RAPID_OFFSET_BASIS_64;
    size_t len = strlen(key);
    size_t chunks = len / 8;

    // Process 8-byte chunks
    for (size_t i = 0; i < chunks; i++)
    {
        uint64_t chunk;
        memcpy(&chunk, key + i * 8, 8);
        hash ^= chunk;
        hash *= RAPID_PRIME_64;
    }

    // Process remaining bytes (if any)
    uint64_t last_chunk = 0;
    memcpy(&last_chunk, key + chunks * 8, len % 8);
    hash ^= last_chunk;
    hash *= RAPID_PRIME_64;

    // Final XOR to reduce collisions
    hash ^= FINAL_XOR_CONSTANT;

    return hash;
}
