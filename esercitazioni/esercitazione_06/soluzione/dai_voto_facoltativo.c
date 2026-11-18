#include <stdio.h>
#define N_MESI 12
#define N_ANNI 4

int main() {
    int i, j, anno;
    int dati[N_MESI][2 * N_ANNI];
    double media[N_MESI], sortmedia[N_MESI][2];
    int voto[N_MESI];
    double tmp;

    FILE *input = fopen("quattro_anni.dat", "r");
    if(input == NULL) {
        fprintf(stderr, "Impossibile aprire il file quattro_anni.dat\n");
        return 1;
    }

    for(i = 0; i < N_MESI; i++) {
        fscanf(input, "%*d"); // scartiamo la prima colonna
        for(anno = 0; anno < N_ANNI; anno++) { // leggiamo le altre otto, due alla volta
            fscanf(input, "%d %d", &dati[i][2 * anno], &dati[i][2 * anno + 1]);
        }
    }
    fclose(input);

    FILE *output = fopen("media.dat", "w");
    for(anno = 0; anno < N_ANNI; anno++) { // ciclo sugli anni
        // inizializziamo sortmedia con i dati dell'anno
        for(i = 0; i < N_MESI; i++) {
            media[i] = (dati[i][2 * anno] + dati[i][2 * anno + 1]) / 2.0;
            sortmedia[i][0] = i + 1;
            sortmedia[i][1] = media[i];
        }

        // applichiamo il bubblesort
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

        // assegniamo il voto
        for(i = 0; i < N_MESI; i++) {
            int indice_mese = sortmedia[i][0] - 1;
            voto[indice_mese] = i + 1;
        }

        // stampiamo la riga relativa all'anno
        for(i = 0; i < N_MESI; i++) {
            fprintf(output, "%lf %d ", media[i], voto[i]);
        }
        fprintf(output, "\n");
    }
    fclose(output);

    return 0;
}
