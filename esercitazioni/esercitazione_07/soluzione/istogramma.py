import matplotlib.pyplot as plt
import numpy as np

plt.title('Istogramma delle frequenze per n = 20');
plt.xlabel('Successi k')
plt.ylabel('Frequenza')
x, y = np.loadtxt('istogramma.dat', usecols=(0,1), unpack=True)
plt.bar(x,y,fill=True,color='C0')
plt.savefig('istogramma.png')
    
plt.show()
