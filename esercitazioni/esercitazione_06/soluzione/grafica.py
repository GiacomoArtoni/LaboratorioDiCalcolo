import matplotlib.pyplot as plt
import numpy as np

plt.figure(1)
plt.title('Temperature medie mensili a Roma')
plt.xlabel('Anno')
plt.ylabel('Temperatura media')

plt.xticks((0, 1, 2, 3), ("2021", "2011", "2001", "1991"))
plt.xlim(0, 4.5)

dati = np.loadtxt('media.dat', usecols=(0, ) , unpack=True)
plt.plot(dati, '-o', label='Gennaio')
dati = np.loadtxt('media.dat', usecols=(2, ) , unpack=True)
plt.plot(dati, '-o', label='Febbraio')
dati = np.loadtxt('media.dat', usecols=(4, ) , unpack=True)
plt.plot(dati, '-o', label='Marzo')
dati = np.loadtxt('media.dat', usecols=(6, ) , unpack=True)
plt.plot(dati, '-o', label='Aprile')
dati = np.loadtxt('media.dat', usecols=(8, ) , unpack=True)
plt.plot(dati, '-o', label='Maggio')
dati = np.loadtxt('media.dat', usecols=(10, ) , unpack=True)
plt.plot(dati, '-o', label='Giugno')
dati = np.loadtxt('media.dat', usecols=(12, ) , unpack=True)
plt.plot(dati, '-o', label='Luglio')
dati = np.loadtxt('media.dat', usecols=(14, ) , unpack=True)
plt.plot(dati, '-o', label='Agosto')
dati = np.loadtxt('media.dat', usecols=(16, ) , unpack=True)
plt.plot(dati, '-o', label='Settembre')
dati = np.loadtxt('media.dat', usecols=(18, ) , unpack=True)
plt.plot(dati, '-o', label='Ottobre')
dati = np.loadtxt('media.dat', usecols=(20, ) , unpack=True)
plt.plot(dati, '-<', label='Novembre')
dati = np.loadtxt('media.dat', usecols=(22, ) , unpack=True)
plt.plot(dati, '-<', label='Dicembre')

plt.legend()
plt.savefig('medie.png')    

plt.figure(2)
plt.title('Voti relativo ai mesi')
plt.xlabel('Anno')
plt.ylabel('Voto')

plt.xticks((0, 1, 2, 3), ("2021", "2011", "2001", "1991"))
plt.xlim(0, 4.5)

dati = np.loadtxt('media.dat', usecols=(1, ) , unpack=True)
plt.plot(dati, '-o', label='Gennaio')
dati = np.loadtxt('media.dat', usecols=(3, ) , unpack=True)
plt.plot(dati, '-o', label='Febbraio')
dati = np.loadtxt('media.dat', usecols=(5, ) , unpack=True)
plt.plot(dati, '-o', label='Marzo')
dati = np.loadtxt('media.dat', usecols=(7, ) , unpack=True)
plt.plot(dati, '-o', label='Aprile')
dati = np.loadtxt('media.dat', usecols=(9, ) , unpack=True)
plt.plot(dati, '-o', label='Maggio')
dati = np.loadtxt('media.dat', usecols=(11, ) , unpack=True)
plt.plot(dati, '-o', label='Giugno')
dati = np.loadtxt('media.dat', usecols=(13, ) , unpack=True)
plt.plot(dati, '-o', label='Luglio')
dati = np.loadtxt('media.dat', usecols=(15, ) , unpack=True)
plt.plot(dati, '-o', label='Agosto')
dati = np.loadtxt('media.dat', usecols=(17, ) , unpack=True)
plt.plot(dati, '-o', label='Settembre')
dati = np.loadtxt('media.dat', usecols=(19, ) , unpack=True)
plt.plot(dati, '-o', label='Ottobre')
dati = np.loadtxt('media.dat', usecols=(21, ) , unpack=True)
plt.plot(dati, '-<', label='Novembre')
dati = np.loadtxt('media.dat', usecols=(23, ) , unpack=True)
plt.plot(dati, '-<', label='Dicembre')

plt.legend()
plt.savefig('voti.png')
plt.show()






