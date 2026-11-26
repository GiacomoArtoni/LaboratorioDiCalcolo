#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NMAX 20 // 21! non sta in un unsigned long long int

unsigned long long int fattoriale(int n);
double binomiale(double p, int k, int n);

int main() {
  double Pk, p = 0.;
  int k, n = 0;
  FILE *output;
  
  // assicuriamoci che l'utente non inserisca numeri assurdi
  do {
    printf("Inserire la probabilità p (ricorda: deve essere un numero compreso tra 0 e 1): ");
    scanf("%lf", &p);
  } while(p <= 0 || p >= 1);
  
  do {
    printf("Inserire il numero di esperimenti n (ricorda: deve essere un numero intero tra 1 e %d): ", NMAX);
    scanf("%d", &n);
  } while(n <= 0 || n > NMAX);
  
  // calcoliamo e stampiamo
  output = fopen("bernoulli.dat", "w");
  if(output == NULL) {
    fprintf(stderr, "Errore: impossibile aprire il file bernoulli.dat\n");
    return 1;
  }
  
  for(k = 0; k <= n; k++) {
    Pk = binomiale(p, k, n);
    fprintf(output, "%d %lf\n", k, Pk);
  }
  
  fclose(output);
  
  return 0;
}

unsigned long long int fattoriale(int n) {
  int i;
  unsigned long long int risultato = 1;
  for(i = 2; i <= n; i++) {
    risultato *= i; // risultato = risultato * i;
  }
  
  return risultato;
}

double binomiale(double p, int k, int n) {
  if(k < 0 || k > n) {
    fprintf(stderr, "Attenzione, k (%d) deve essere un numero positivo minore o uguale a n (%d)\n", k, n);
    exit(1);
  }
  return fattoriale(n) / (double)(fattoriale(k) * fattoriale(n - k)) * pow(p, k) * pow(1. - p, n - k);
}
