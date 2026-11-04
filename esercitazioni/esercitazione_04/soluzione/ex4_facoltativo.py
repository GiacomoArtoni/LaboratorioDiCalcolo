import matplotlib.pyplot as plt
import numpy as np

plt.title('Zeri della funzione sin(x)/x')
plt.xlabel('Numero di intervalli in cui calcolare gli zeri')
plt.ylabel('Numero di zeri della funzione trovati')
x, y = np.loadtxt('zeri.dat', unpack=True)
plt.xlim(0, 20)
plt.plot(x, y, '-o', label='Output del codice')
plt.legend()
plt.savefig('zeri.png')
plt.show()
