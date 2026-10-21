#include <stdio.h>

int main(){
	// Inizializziamo i due punti scelti
	double x1 = 1.5;
	double y1 = 3.2;
	double x2 = 7.2;
	double y2 = -2.0;

	// Calcoliamo coefficiente angolare ed intercetta
	double m = (y2 - y1) / (x2 - x1);
	double q = y1 - m * x1;

	printf("Coefficiente angolare: %lf - intercetta: %lf\n", m, q);

	// verifica: m * x1 + q deve restituire y1
	printf("Verifica: m * x1 + q = %lf (y1 = %lf)\n", m * x1 + q, y1);

	return 0;
}
