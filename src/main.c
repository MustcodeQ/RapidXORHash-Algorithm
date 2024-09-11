// src/main.c
#include <stdio.h>
#include "rapid_xor_hash.h"

int main()
{
    const char *key = "example";
    printf("RapidXORHash: %llu\n", rapid_xor_hash(key));
    return 0;
}

//  main file a coons char key = "exmaple";