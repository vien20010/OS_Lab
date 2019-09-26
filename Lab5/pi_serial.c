#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int count = 0;

int main(int argc, char* argv[]) {
    if(argv[1] == NULL || argv[1] <= 0)
        return 0;
    struct timespec start, end, elapsed;
    int nPoints = atoi(argv[1]);
    printf("Number of test points: %d\n", nPoints);
    srand(time(NULL));
    unsigned int seed = rand() % 30000;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    for(int i = 0; i < nPoints; i++) {
        double x = (double)(rand_r(&seed)) / (double)(RAND_MAX / 2) - 1; 
        double y = (double)(rand_r(&seed)) / (double)(RAND_MAX / 2) - 1; 
        if(x * x + y * y <= 1)
            count++;
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("Number of point inside circle: %d\n", count);
    elapsed.tv_sec = end.tv_sec - start.tv_sec;
    elapsed.tv_nsec = end.tv_nsec - start.tv_nsec;
    if(elapsed.tv_nsec < 0) {
        elapsed.tv_nsec += 1e9;
        elapsed.tv_sec -= 1;
    }
    double pi = 4 * (double)count/nPoints;
    printf("Pi = %lf\n", pi);
    printf("Elapsed time = %.5lf seconds. \n", (double)elapsed.tv_sec + (double)elapsed.tv_nsec / 1.0e9);
    return 0;
}
