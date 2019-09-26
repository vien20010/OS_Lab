#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* aligned_malloc(unsigned int size, unsigned int align);
void* aligned_free(void* ptr);
