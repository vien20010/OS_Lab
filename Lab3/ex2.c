#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
    pid_t pA, pB, pC, pD, pE, pF, pG, pI;
    strcpy(argv[0], "A");
    pB = fork();
    if(pB == 0) {
        strcpy(argv[0], "B");
        pE = fork();
        if(pE > 0) {
            pF = fork();
            if( pF == 0)
                strcpy(argv[0], "F");
        }
        else strcpy(argv[0], "E");

    }
    else {
        pC = fork();
        if(pC == 0) {
            strcpy(argv[0], "C");
            pG = fork();
            if(pG == 0) {
                strcpy(argv[0], "G");
                pI = fork();
                if(pI == 0)
                    strcpy(argv[0], "I");
            }
        }
        else {
            pD = fork();
            if(pD == 0)
                strcpy(argv[0], "D");
        }
    }
    sleep(1);
    return 0;
}
