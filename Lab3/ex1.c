#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXLINE  128
#define LINE 79

int modBigNumber(char* num, int mod) {
    int r = 0;
    for(int i=0; i< strlen(num) - 1; i++) {
        r = r*10 + num[i] - '0';
        r = r%mod;
    }
    return r;
}

int main(int argv, char** argc) {
    char arr[MAXLINE][LINE];
    FILE *fp;
    fp = fopen("./numbers.txt", "r");
    if(fp == NULL) {
        printf("Error while opening file.\n");
        return 0;
    }
    int line = 0;
    while(fgets(arr[line], LINE, fp) != NULL) {
        line++;
    }
    fclose(fp);
    for(int i=0; i<line; i++)
        printf("%s", arr[i]);
    pid_t pB, pC;
    int count = 0;
    pB = fork();
    if(pB == 0) {
        pC = fork();
        if(pC == 0) {
            for(int i=0; i<line; i++) {
                if(modBigNumber(arr[i], 2) == 0) {
                    count++;
                }
            }
            printf("Divisible by 2: %d\n", count);
            fflush(stdin);
        }
        else {
            for(int i=0; i<line; i++) {
                if(modBigNumber(arr[i], 3) == 0) {
                    count++;
                }
            }
            printf("Divisible by 3: %d\n", count);
            fflush(stdin);
        }
    }
    else {
        for(int i=0; i<line; i++) {
                if(modBigNumber(arr[i], 5) == 0) {
                    count++;
                }
            }
            printf("Divisible by 5: %d\n", count);
            fflush(stdin);
    }
    while(1);
    return 0;
}
