#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define SIZE1 100
#define SIZE2 2000
#define SIZE3 300

void transposes(mpz_t* A, mpz_t* B) {
    for(int i =0;i<SIZE2;i++)
        for(int j=0;j<SIZE3;j++)
}

void multi(mpz_t* A, mpz_t* B, mpz_t* C) {
   // #pragma omp parallel`
    {
        int i, j, k;
       // #pragma omp for
    for(i = 0; i< SIZE1 ; i++) {
        for(j = 0; j < SIZE3; j++) {
            mpz_init(*(C + i * SIZE3 + j));
            for( k = 0; k < SIZE2; k++) {
                mpz_t temp;
                mpz_init(temp);
                mpz_mul(temp, *(A + i * SIZE2 +k), *(B + k * SIZE3 + j));
                mpz_add(*(C + i * SIZE3 + j), *(C + i * SIZE3 + j), temp);
            }
        }
    }
    }
}
int main() {
    unsigned long seed;
    gmp_randstate_t rstate;
    gmp_randinit_mt(rstate);
    gmp_randseed_ui(rstate, seed);
    struct timespec start, end, elapsed;
    mpz_t* A = (mpz_t*)malloc(SIZE1 * SIZE2 * sizeof(mpz_t));
    mpz_t* B = (mpz_t*)malloc(SIZE2 * SIZE3 * sizeof(mpz_t));
    mpz_t* C = (mpz_t*)malloc(SIZE1 * SIZE3 * sizeof(mpz_t));
    for(int i = 0 ; i < SIZE1; i++) {

        for(int j = 0; j < SIZE2; j++) {
            mpz_init(*(A + i * SIZE2 + j));
    
        mpz_urandomb(*(A + i * SIZE2 + j), rstate, 3);
        }
    }
    for(int i = 0 ; i < SIZE2; i++) {
        for(int j = 0; j < SIZE3; j++) {
            mpz_init(*(B + i * SIZE3 + j));
            mpz_urandomb(*(B + i * SIZE3 + j), rstate, 3);
        }
    }
    for(int i =0; i< SIZE1; i++) {
        for(int j = 0; j< SIZE2; j++) {
            //mpz_out_str(stdout, 10, *(A + i * SIZE2 + j));
            //printf("\t");
        }
        //printf("\n");
    }
    for(int i =0; i< SIZE2; i++) {
        for(int j = 0; j< SIZE3; j++) {
            //mpz_out_str(stdout, 10, *(B + i * SIZE3 + j));
            //printf("\t");
        }
        //printf("\n");
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    multi(A, B, C);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    elapsed.tv_sec = end.tv_sec - start.tv_sec;
    elapsed.tv_nsec = end.tv_nsec - start.tv_nsec;
    if(elapsed.tv_nsec < 0) {
        elapsed.tv_nsec += 1e9;
        elapsed.tv_sec -= 1;
    }
     for(int i = 0; i< SIZE1 ; i++) {
        for(int j = 0; j < SIZE3; j++) {
            //mpz_inits(*(C + i * SIZE3 + j));
            /*for(int k = 0; k < SIZE2; k++) {
                mpz_t temp;
                mpz_inits(temp);
                //mpz_mul(temp, *(A + i * SIZE2 +k), *(B + k * SIZE3 + j));
                mpz_add(*(C + i * SIZE3 + j), *(C + i * SIZE3 + j), temp);
            }*/
        }
    }
    for(int i = 0 ; i < SIZE1; i++) {
        for(int j = 0; j < SIZE3; j++) {
            //mpz_out_str(stdout, 10, *(C + i * SIZE3 + j));
            //printf("%d\t%d\n", i, j);

           // printf("\t");
        }
       // printf("\n");
    }
    printf("%.5lf", (double)elapsed.tv_sec + (double)elapsed.tv_nsec / 1.0e9);
    return 0;
}


