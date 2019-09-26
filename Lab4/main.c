#include "ex1.h"
#define size 20
#define align 1024

int main(int argc, char** argv) {
    void* p = aligned_malloc(size, align);
    printf("%p", p);
    aligned_free(p);
    return 1;
}
