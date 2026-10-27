#include <stdio.h>
#include <math.h>

int main() {
  double x, y, vx, vy, t;
  double R = 6.2;     // raggio (m)
  double omega = 0.1; // velocita' angolare (rad/s)

  fprintf(stderr, "Questo programma calcola le coordinate di x e y e le velocità vx vy di un moto circolare uniforme sul piano\n\n");

  fprintf(stderr,"Introdurre il tempo:\n");
  scanf("%lf", &t);

  x = R * cos(omega * t);
  y = R * sin(omega * t);

  vx = -omega * R * sin(omega * t);
  vy = omega * R * cos(omega * t);

  printf("%8.4lf %8.4lf %8.4lf %8.4lf %8.4lf\n", t, x, y, vx, vy);

  return 0;
}
