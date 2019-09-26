#include <stdio.h>
#include <unistd.h>

int main(int argv, char** argc) {
    pid_t pA, pB, pC, pD, pE, pF, pG, pI;
    pB = fork();
    if(pB == 0) {
        pE = fork();
        if(pE > 0)
            pF = fork();
    }
    else {
        pC = fork();
        if(pC == 0) {
            pG = fork();
            if(pG == 0)
                pI = fork();
        }
        else {
            pD = fork();
        }
    }
    while(1);
    return 0;
}
