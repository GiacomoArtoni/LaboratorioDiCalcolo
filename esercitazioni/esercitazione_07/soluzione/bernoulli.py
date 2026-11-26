import numpy as np
import matplotlib.pyplot as plt

# bernoulli.dat contiene la distribuzione dell'ultima esecuzione di bernoulli.c:
# eseguite questo script dopo ogni esecuzione (n = 2, 4, 8, 12 con p = 1/6)
x, y = np.loadtxt("bernoulli.dat", unpack=True)
n = len(x) - 1  # k va da 0 a n

plt.xlabel('k')
plt.ylabel('P(k)')
plt.bar(x, y, label="n = %d" % n)
plt.legend()
plt.title('Distribuzione binomiale con n = %d' % n)
# per il controllo con p = 1/2 e n = 4 salvate invece come 'distribuzione.png'
plt.savefig('bernoulli_%d.png' % n)

plt.show()
