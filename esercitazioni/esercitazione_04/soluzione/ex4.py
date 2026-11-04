import matplotlib.pyplot as plt
import numpy as np

plt.title('Funzione Sin(x)/x')
plt.xlabel('x')
plt.ylabel('y')

x, y = np.loadtxt('sinxx.dat', unpack=True, usecols=(0, 1))
plt.xlim(-15.1, 15.1)
plt.plot(x, y, '--o', label='Punti generati da sinxx.c')
plt.legend()
plt.savefig('sinxx.png')
plt.show()
