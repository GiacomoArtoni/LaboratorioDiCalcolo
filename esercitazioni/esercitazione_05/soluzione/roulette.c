#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int occorrenze[36] = {0};
	int X, i;
	int NE = 0;
	int NM = 0;
	// così facendo il seed cambia ogni secondo
	int seed = time(NULL);
	// qui inizializziamo il seed: ricordatevi di farlo UNA VOLTA SOLA per programma
	srand48(seed);

	// facciamo girare la roulette N volte
	for(i = 0; i < N; i++) {
		// estraiamo il numero
		X = (int) (drand48() * 36.) + 1;

		// aggiorniamo l'array
		occorrenze[X - 1]++;
		
		// controlliamo se il numero è pari o dispari
		if(X % 2 == 0) {
			NE++;
		}
		
		// e se è minore o maggiore di 18
		if(X <= 18) {
			NM++;
		}
	}

	// stampiamo le frequenze pari/dispari, manque/pass
	fprintf(stderr, "Frequenza di numeri pari: %lf\n", NE / (double) N);
	fprintf(stderr, "Frequenza di numeri minori o uguali a 18: %lf\n", NM / (double) N);

	// stampiamo tutte le occorrenze e le frequenze
	for(i = 0; i < 36; i++) {
		printf("%d %d %lf\n", i + 1, occorrenze[i], occorrenze[i] / (double) N);
	}
	
	return 0;
}
