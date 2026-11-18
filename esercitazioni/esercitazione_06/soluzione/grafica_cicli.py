# QUESTA SOLUZIONE È PIÙ COMPATTA MA UTILIZZA COSTRUTTI NON VISTI A LEZIONE
# CONSIDERATALA UNA SOLUZIONE "PER I PIÙ CURIOSI"

import matplotlib.pyplot as plt
import numpy as np

mesi = ["Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"]

plt.figure(1)
plt.title('Temperature medie mensili a Roma')
plt.xlabel('Anno')
plt.ylabel('Temperatura media')

plt.xticks((0, 1, 2, 3), ("2021", "2011", "2001", "1991"))
plt.xlim(0, 4.5)

for i, mese in enumerate(mesi):
    dati = np.loadtxt('media.dat', usecols=(i * 2, ) , unpack=True)
    if i < 10: # questo if fa sì che non ci siano due curve con colori e simboli uguali
        plt.plot(dati, '-o', label=mese)
    else:
        plt.plot(dati, '-<', label=mese)

plt.legend()
plt.savefig('medie.png')    

plt.figure(2)
plt.title('Voti relativo ai mesi')
plt.xlabel('Anno')
plt.ylabel('Voto')

plt.xticks((0, 1, 2, 3), ("2021", "2011", "2001", "1991"))
plt.xlim(0, 4.5)

for i, mese in enumerate(mesi):
    dati = np.loadtxt('media.dat', usecols=(i * 2 + 1, ) , unpack=True)
    if i < 10:
        plt.plot(dati, '-o', label=mese)
    else:
        plt.plot(dati, '-<', label=mese)

plt.legend()
plt.savefig('voti.png')
plt.show()






