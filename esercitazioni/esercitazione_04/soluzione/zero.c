#include <stdio.h>
#include <math.h>

#ifndef NP
#error "NP non definito: compilare con -DNP=<numero di punti>, ad es. gcc -o zero zero.c -lm -DNP=100"
#endif

#define EPSILON 1e-9 // tolleranza per il confronto con zero

int main() {
    int i, nzeri = 0;
    double fxL, fxR, xL, xR, dx;
    double a = -15.0, b = 15.0;
    int N = NP - 1;

    dx = (b - a) / N;
    for(i = 0; i < N; i++) {
        xL = a + i * dx;
        xR = xL + dx;
        if(fabs(xL) < EPSILON) { // mai confrontare double con ==
            fxL = 1.0;
        }
        else {
            fxL = sin(xL) / xL;
        }
        if(fabs(xR) < EPSILON) {
            fxR = 1.0;
        }
        else {
            fxR = sin(xR) / xR;
        }

        if(fxL * fxR < 0) {
            nzeri++;
        }
    }
    printf("Numero zeri trovati = %d\n", nzeri);
    return 0;
}
