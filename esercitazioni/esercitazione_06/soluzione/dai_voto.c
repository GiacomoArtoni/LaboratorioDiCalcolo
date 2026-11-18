#include <stdio.h>
#define N_MESI 12

int main() {
    int i, j;
    int dati[N_MESI][2];
    double media[N_MESI], sortmedia[N_MESI][2];
    int voto[N_MESI];
    double tmp;

    FILE *input = fopen("temperature.dat", "r");
    if(input == NULL) {
        fprintf(stderr, "Impossibile aprire il file temperature.dat\n");
        return 1;
    }

    for(i = 0; i < N_MESI; i++) {
        fscanf(input, "%*d %d %d", &dati[i][0], &dati[i][1]);
        media[i] = (dati[i][0] + dati[i][1]) / 2.0; // 2.0 e non 2: altrimenti divisione tra interi!
        sortmedia[i][0] = i + 1;
        sortmedia[i][1] = media[i];
    }
    fclose(input);

    for(i = 0; i < N_MESI - 1; i++) {
        for(j = 0; j < N_MESI - i - 1; j++) {
            if(sortmedia[j][1] > sortmedia[j + 1][1]) {
                tmp = sortmedia[j][1];
                sortmedia[j][1] = sortmedia[j + 1][1];
                sortmedia[j + 1][1] = tmp;

                tmp = sortmedia[j][0];
                sortmedia[j][0] = sortmedia[j + 1][0];
                sortmedia[j + 1][0] = tmp;
            }
        }
    }

    for(i = 0; i < N_MESI; i++) {
        int indice_mese = sortmedia[i][0] - 1;
        voto[indice_mese] = i + 1;
    }

    FILE *output = fopen("voti.dat", "w");
    for(i = 0; i < N_MESI; i++) {
        fprintf(stdout, "%d %d %d %lf %d\n", i + 1, dati[i][0], dati[i][1], media[i], voto[i]);
        fprintf(output, "%d %d %d %lf %d\n", i + 1, dati[i][0], dati[i][1], media[i], voto[i]);
    }
    fclose(output);

    return 0;
}
