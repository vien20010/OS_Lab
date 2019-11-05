#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#define NUM_THREAD 4

int nPoints = 0;
int n = 0;

static volatile int count = 0;
pthread_mutex_t lock;

void* generatePoint(void* i) {
    int temp = 0;
    unsigned int seed = rand() % 30000;
    for(int i = 0; i < n; i++) {
        double x = (double)(rand_r(&seed)) / (double)(RAND_MAX / 2) - 1; 
        double y = (double)(rand_r(&seed)) / (double)(RAND_MAX / 2) - 1; 
        if(x * x + y * y <= 1) {
            temp++;
        }
    }
    pthread_mutex_lock(&lock);
    count+= temp;
    pthread_mutex_unlock(&lock);
    pthread_exit(0);
}

int main(int argc, char* argv[]) {
    if(argv[1] == NULL || argv[1] <= 0)
        return 0;
    struct timespec start, end, elapsed;
    nPoints = atoi(argv[1]);
    printf("Number of test points: %d\n", nPoints);
    n = nPoints/ NUM_THREAD;
    pthread_t tid[NUM_THREAD];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    srand(time(NULL));
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    for(int i = 0; i< NUM_THREAD; i++) {
        pthread_create(&tid[i], &attr, generatePoint, (void*) i);
    }
    for(int i = 0; i < NUM_THREAD; i++) {
        pthread_join(tid[i], NULL); 
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    elapsed.tv_sec = end.tv_sec - start.tv_sec;
    elapsed.tv_nsec = end.tv_nsec - start.tv_nsec;
    if(elapsed.tv_nsec < 0) {
        elapsed.tv_nsec += 1e9;
        elapsed.tv_nsec += 1e9;
        elapsed.tv_sec -= 1;
    }
    double pi = 4 * (double)count/nPoints;
    printf("Number of points inside circle: %d\n", count);
    printf("Pi = %.5lf\n", pi);
    printf("Elapsed time = %.5lf seconds. \n", (double)elapsed.tv_sec + (double)elapsed.tv_nsec / 1.0e9);
    pthread_exit(NULL);
    return 0;
}
