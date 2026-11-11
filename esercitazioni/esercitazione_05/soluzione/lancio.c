#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	// così facendo il seed cambia ogni secondo
	int seed = time(NULL);
	// qui inizializziamo il seed: ricordatevi di farlo UNA VOLTA SOLA per programma
	srand48(seed);

	// estraiamo il numero
	int X = (int) (drand48() * 36.) + 1;

	// lo stampiamo
	printf("%d ", X);

	// e poi stampiamo se il numero è pari o dispari
	if(X % 2 == 0) {
		printf("E ");
	}
	else {
		printf("O ");
	}

	// e se è minore o maggiore di 18
	if(X <= 18) {
		printf("M\n");
	}
	else {
		printf("P\n");
	}
	
	return 0;
}
