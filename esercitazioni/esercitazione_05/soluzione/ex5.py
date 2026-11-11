import matplotlib.pyplot as plt
import numpy as np

nbins=36

plt.figure(1)
plt.title('Istogramma delle occorrenze')
plt.xlabel('numeri')
plt.ylabel('occorrenza')
x, y = np.loadtxt('isto.dat', usecols=(0,1), delimiter=' ', unpack=True)
plt.bar(x,y,fill=True)
plt.savefig('isto1.png')

plt.figure(2)
plt.xlabel('numeri')
plt.ylabel('frequenza')
x, y = np.loadtxt('isto10.dat', usecols=(0,2), delimiter=' ', unpack=True)
plt.bar(x,y,fill=True,label='N = 10')

plt.figure(2)
plt.xlabel('numeri')
plt.ylabel('frequenza')
x, y = np.loadtxt('isto100.dat', usecols=(0,2), delimiter=' ', unpack=True)
plt.bar(x,y,fill=True,color='magenta',label='N = 100')

plt.figure(2)
plt.xlabel('numeri')
plt.ylabel('frequenza')
x, y = np.loadtxt('isto1000.dat', usecols=(0,2), delimiter=' ', unpack=True)
plt.bar(x,y,fill=True,color='green',label='N = 1000')

plt.figure(2)
plt.xlabel('numeri')
plt.ylabel('frequenza')
x, y = np.loadtxt('isto10000.dat', usecols=(0,2), delimiter=' ', unpack=True)
plt.bar(x,y,fill=True,color='red',label='N = 10000')

plt.figure(2)
plt.xlabel('numeri')
plt.ylabel('frequenza')
x, y = np.loadtxt('isto100000.dat', usecols=(0,2), delimiter=' ', unpack=True)
plt.bar(x,y,fill=True,color='red',label='N = 100000')

plt.figure(2)
x = np.linspace(0, nbins+1, 2)
y = [(1. / nbins) for _ in x]
plt.plot(x,y,'--',label='Valore aspettato',color='black')
plt.savefig('isto2.png')

plt.legend()
plt.show()
