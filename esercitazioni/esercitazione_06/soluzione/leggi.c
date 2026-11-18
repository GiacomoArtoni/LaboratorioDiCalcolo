#include <stdio.h>
#define N_MESI 12

int main() {
    int i;
    int dati[N_MESI][2];
    double media[N_MESI];

    FILE *input = fopen("temperature.dat", "r");
    if(input == NULL) {
        fprintf(stderr, "Impossibile aprire il file temperature.dat\n");
        return 1;
    }

    for(i = 0; i < N_MESI; i++) {
        fscanf(input, "%*d %d %d", &dati[i][0], &dati[i][1]);
        media[i] = (dati[i][0] + dati[i][1]) / 2.0; // 2.0 e non 2: altrimenti divisione tra interi!
    }
    fclose(input);

    for(i = 0; i < N_MESI; i++) {
        fprintf(stdout, "%d %d %d %lf\n", i + 1, dati[i][0], dati[i][1], media[i]);
    }

    return 0;
}
