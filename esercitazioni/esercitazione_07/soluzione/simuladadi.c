#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 101 // k puo' andare da 0 a n = 100

int lancio_dado();
void crea_isto(double hist[], int numlanci, int numdadi);

int main() {
  int n = 0, N_lanci = 0;
  int k;
  FILE *output;
  double istogramma[NMAX] = {0.};
  
  // ricordate di inizializzare il generatore!
  srand48(time(NULL));
  
  do {
    printf("Inserire il numero di dadi n (ricorda: deve essere un numero intero compreso tra 2 e %d): ", NMAX - 1);
    scanf("%d", &n);
  } while(n < 2 || n > NMAX - 1);
  
  do {
    printf("Inserire il numero di lanci N_lanci (ricorda: deve essere un numero intero maggiore di zero): ");
    scanf("%d", &N_lanci);
  } while(N_lanci <= 0);

  crea_isto(istogramma, N_lanci, n);
  
  // normalizziamo l'istogramma
  for(k = 0; k <= n; k++) {
    istogramma[k] /= (double) N_lanci;
  }
  
  // e stampiamolo
  output = fopen("istogramma.dat", "w");
  if(output == NULL) {
    fprintf(stderr, "Errore: impossibile aprire il file istogramma.dat\n");
    return 1;
  }
  for(k = 0; k <= n; k++) {
    fprintf(output, "%d %lf\n", k, istogramma[k]);
  }
  fclose(output);
  
  return 0;
}

void crea_isto(double hist[], int numlanci, int numdadi) {
  int i, nl, k;
  for(nl = 0; nl < numlanci; nl++) {
    for(i = 0, k = 0; i < numdadi; i++) {
      if(lancio_dado() == 3) {
        k++;
      }
    }
    hist[k] += 1.0;
  }
}

int lancio_dado() {
  return (int) ((drand48() * 6) + 1);
}
