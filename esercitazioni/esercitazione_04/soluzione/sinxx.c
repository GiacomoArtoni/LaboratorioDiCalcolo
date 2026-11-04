#include <stdio.h>
#include <math.h>

#define EPSILON 1e-9 // tolleranza per il confronto con zero

int main() {
    int i, Np;
    double fx, x, dx, a = -15.0, b = 15.0;
    do {
        fprintf(stderr, "Inserire il numero di punti per il calcolo della funzione (Np >= 100)\n");
        scanf("%i", &Np);
        if(Np < 100) {
            fprintf(stderr, "Attenzione! Il numero dei punti deve essere >= 100\n");
        }
    } while(Np < 100);


    dx = (b - a) / (Np - 1);

    for(i = 0; i < Np; i++) {
        x = a + i * dx;
        if(fabs(x) < EPSILON) { // mai confrontare double con ==
            fx = 1.0;
        }
        else {
            fx = sin(x) / x;
        }
        fprintf(stdout, "%.14lf %.14lf\n", x, fx);
    }
    return 0;
}
