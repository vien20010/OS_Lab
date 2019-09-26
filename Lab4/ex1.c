#include "ex1.h"
char isPowerOfTwo(unsigned int align) {
    while(align > 2) {
        if(align % 2 != 0)
            return 0;
        align = align / 2;
    }
    return align == 2 ? 1 : 0;

}
void* aligned_malloc(unsigned int size, unsigned int align) {
    if(size == 0 || isPowerOfTwo(align) == 0)
        return NULL;
    void* p1;
    void** p2;
    int range = align - 1 + sizeof(void*);
    p1 = malloc(size + range);
    if(p1 == NULL)
        return NULL;
    p2 = (void**)(p1 + range - ((long long int)p1 + range) % align);
    p2[-1] = p1;
    printf("%p\t%p\n", p1, p2);
    return p2;
}

void* aligned_free(void* p) {
    free(((void**)p)[-1]);
}


