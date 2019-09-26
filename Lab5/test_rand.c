#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

int main() {
    srand(time(NULL));
    unsigned int seed = rand() % 30000;
    for(int i = 0; i < 100; i++){
        printf("%lf\n", (double)(rand_r(&seed))/ (double)(RAND_MAX / 2) - 1);
    }
    return 0;
}
