import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq, ifft

t = np.linspace( 0, 10, 1000)
y = np.cos(2 * np.pi * t)

file = open('datos.dat', 'w')

for i in range(1000):
	#print(t[i],y[i])
    file.write(f"{t[i]},{y[i]}\n")


file.close()