import matplotlib.pyplot as plt
import numpy as np

t, x, y = np.loadtxt('traiettoria.dat', usecols=(0, 1, 2), unpack=True)

plt.figure(1)
plt.title('Traiettoria')
plt.xlabel('x')
plt.ylabel('y')
# Impostiamo le stesse unità di misura per gli assi x e y 
# (gca è un acronimo per "get current axes")
plt.gca().set_aspect('equal')
plt.plot(x, y, 'b-s', label='Traiettoria')
plt.legend()
plt.savefig('traiettoria.png')


plt.figure(2)
plt.title('x in funzione del tempo')
plt.xlabel('t')
plt.ylabel('x')
plt.plot(t, x, 'g-o', label='x in funzione di t')
plt.legend()
plt.savefig('x.png')


plt.figure(3)
plt.title('y in funzione del tempo')
plt.xlabel('t')
plt.ylabel('y')
plt.plot(t, y, 'r-o', label='y in funzione di t')
plt.legend()
plt.savefig('y.png')
plt.show()
