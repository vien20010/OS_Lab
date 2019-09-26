#include <stdio.h>
#include <stdlib.h>

int main() {
    void* p = (int*)malloc(20);
    printf("%p", p);
    return 0;
}
