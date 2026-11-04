#include <stdio.h>
#include <math.h>

#ifndef NP
#error "NP non definito: compilare con -DNP=<numero di punti>, ad es. gcc -o zero_facoltativo zero_facoltativo.c -lm -DNP=100"
#endif

#define EPSILON 1e-9 // tolleranza per il confronto con zero

int main() {
    int i, nzeri = 0;
    double s, fxL, fxR, xL, xR, dx;
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
        s = fxL * fxR;
        if(s < 0) {
            double xbest = (xL + xR) / 2.0;
            double xerr = (xR - xL) / 2.0;
            fprintf(stderr, "Trovato uno zero x = %12.7f +- %9.7f\n", xbest, xerr);

            nzeri++;
        }
    }
    fprintf(stderr, "Numero zeri trovati = %d\n", nzeri);
    fprintf(stdout, "%d %d\n", NP, nzeri);
    return 0;
}
