import matplotlib.pyplot as plt
import numpy as np

plt.title('Traiettoria e Velocita\'')
plt.xlabel('x')
plt.ylabel('y')
x, y, vx, vy = np.loadtxt('traiettoria.dat', usecols=(1, 2, 3, 4), unpack=True)

# Le unità di misura delle frecce sono le stesse del plot
# arrow(x, y, dx, dy) disegna una freccia da (x, y) a (x+dx, y+dy)
# anche width, head_width, etc. sono in unità di misura del plot
# di conseguenza se gli assi hanno unità differenti le frecce risultano "deformate"
for cc in range(0, len(x)):
    xi = x[cc]
    yi = y[cc]
    vxi = vx[cc]
    vyi = vy[cc]
    plt.arrow(xi, yi, vxi, vyi, width=0.02, head_width=0.2, head_length=0.3, fc='r', ec='r')

# Impostiamo le stesse unità di misura per gli assi x e y per non deformare le frecce 
# (gca è un acronimo per "get current axes")
ax = plt.gca().set_aspect('equal')
plt.plot(x, y,'x', label='Traiettora con velocità')
plt.savefig('velocita.png')
plt.show()
