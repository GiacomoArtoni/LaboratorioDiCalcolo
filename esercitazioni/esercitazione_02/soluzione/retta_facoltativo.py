# Per eseguire questo script, dare il comando: python3 retta_facoltativo.py
import matplotlib.pyplot as plt
import numpy as np

# 22 punti in [-10, 10], estremo destro incluso
x = np.linspace(-10.0, 10.0, 22, endpoint=True)
y = (12.0/5.0)*x - 12.5

plt.title('y = (12/5) x - 12.5')
plt.xlabel('asse x')
plt.ylabel('asse y')
plt.xlim(-6.25, 6.25)
plt.ylim(-27.5, 2.6)
plt.plot(x, y, 'r--o', markersize=5, label='y = (12/5) x - 12.5')
plt.legend()
plt.savefig('retta_facoltativo.png')
plt.show()
