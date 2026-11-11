#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int occorrenze[36] = {0};
	int X, i, N_mani;
	int inserimento_ok;
	int credito = 100;
	int tipo_puntata;
	int puntata;
	int totale_puntate;
	char giocata;
	int vinto;
	// così facendo il seed cambia ogni secondo
	int seed = time(NULL);
	// qui inizializziamo il seed: ricordatevi di farlo UNA VOLTA SOLA per programma
	srand48(seed);

	inserimento_ok = 0;
	while(inserimento_ok == 0) {
		printf("Vuoi giocare 10 o 20 mani?\n");
		scanf("%d", &N_mani);
		if(N_mani != 10 && N_mani != 20) {
			printf("Attenzione, puoi giocare solo 10 o 20 mani!\n");
		}
		else {
			inserimento_ok = 1;
		}
	}

	// mettiamo anche una condizione sul credito: deve essere sempre maggiore di 0!
	for(i = 0; i < N_mani && credito > 0; i++) {
		// seleziona quanto vuoi puntare
		inserimento_ok = 0;
		while(!inserimento_ok) {
			printf("Credito residuo: %d. Selezionare la puntata inserendo il numero relativo all'importo desiderato:\n", credito);
			printf("1 - 1 euro\n");
			printf("2 - 2 euro\n");
			printf("3 - 5 euro\n");
			printf("4 - 10 euro\n");
			printf("5 - 50 euro\n");
			printf("6 - ALL IN\n");
			scanf("%d", &tipo_puntata);
			if(tipo_puntata < 1 || tipo_puntata > 6) {
				printf("Puntata '%d' non valida, riprova\n", tipo_puntata);
			}
			else {
				if(tipo_puntata == 1) {
					puntata = 1;
				}
				else if(tipo_puntata == 2) {
					puntata = 2;
				}
				else if(tipo_puntata == 3) {
					puntata = 5;
				}
				else if(tipo_puntata == 4) {
					puntata = 10;
				}
				else if(tipo_puntata == 5) {
					puntata = 50;
				}
				else if(tipo_puntata == 6) {
					puntata = credito;
				}

				if(puntata > credito) {
					printf("Attenzione, la puntata non può essere maggiore del credito residuo!\n");
				}
				else {
					inserimento_ok = 1;
				}
			}
		}

		totale_puntate += puntata;

		// seleziona su cosa vuoi puntare
		inserimento_ok = 0;
		while(!inserimento_ok) {
			printf("Scegli il tipo di giocata (E/O/M/P):\n");
			// qui serve lo spazio prima di %c, altrimenti rimane un "a capo" nel buffer
			scanf(" %c", &giocata);
			if(giocata != 'E' && giocata != 'O' && giocata != 'M' && giocata != 'P') {
				printf("Giocata '%c' non valida, riprova\n", giocata);
			}
			else {
				inserimento_ok = 1;
			}
		}
		
		X = (int) (drand48() * 36.) + 1;

		printf("\n***********************************************************\n");
		printf("Il numero uscito è %d", X);

		vinto = 0;
		if(X % 2 == 0 && giocata == 'E') {
			vinto = 1;
		}
		if(X % 2 != 0 && giocata == 'O') {
			vinto = 1;
		}
		if(X <= 18 && giocata == 'M') {
			vinto = 1;
		}
		if(X > 18 && giocata == 'P') {
			vinto = 1;
		}

		if(vinto) {
			credito += puntata;
			printf(" e hai vinto %d euro!\n", puntata);
		}
		else {
			credito -= puntata;
			printf(" e hai perso %d euro :-(\n", puntata);
		}
		printf("***********************************************************\n\n");

		if(credito <= 0) {
			printf("***********************************************************\n");
			printf("Peccato, hai finito il credito!\n");
			printf("***********************************************************\n\n");
		}
	}

	printf("***********************************************************\n");
	printf("RIEPILOGO DEL GIOCO:\n");
	printf("***********************************************************\n");
	printf("Numero di mani giocate: %d\n", i);
	printf("Ammontare totale delle puntate: %d\n", totale_puntate);
	printf("Credito finale a disposizione: %d\n", credito);
	
	return 0;
}
