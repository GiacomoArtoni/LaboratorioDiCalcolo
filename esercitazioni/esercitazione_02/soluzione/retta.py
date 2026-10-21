# Per eseguire questo script, dare il comando: python3 retta.py
import matplotlib.pyplot as plt
import numpy as np

# Punti usati in retta.c
xp, yp = np.loadtxt('punti.dat', unpack=True)

# m e q stampati da retta.c
m = -0.912281
q = 4.568421
x = np.linspace(0, 9, 10)
y = m*x + q

plt.title('retta y = mx + q con m = -0.912281 e q = 4.568421')
plt.xlabel('asse x')
plt.ylabel('asse y')
plt.xlim(0, 9)
plt.ylim(-4, 5)
plt.plot(xp, yp, 'go', label='punti')
plt.plot(x, y, '-', label='y = mx + q')
plt.legend()
plt.savefig('retta.png')
plt.show()
