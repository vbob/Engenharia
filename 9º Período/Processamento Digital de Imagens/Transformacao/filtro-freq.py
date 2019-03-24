import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('ImagemLua.jpg',0)
img = np.pad(img, img.shape[0])
f = np.fft.fft2(img)

filtro = np.zeros_like(f, np.uint8)
x = len(filtro)
y = len(filtro[0])

filtro[int(x/2)][int(y/2)] = 1
filtro[int(x/2)+1][int(y/2)] = 1
filtro[int(x/2)][int(y/2)+1] = 1
filtro[int(x/2)+1][int(y/2)+1] = 1

g = filtro * f

fshift = np.fft.fftshift(f)

ifshift = np.fft.ifftshift(np.fft.fftshift(g))
f2 = np.fft.ifft2(ifshift)

magnitude_spectrum = 20*np.log(np.abs(fshift))
magnitude_spectrum2 = 20*np.log(np.abs(np.fft.fftshift(g)))
f2 = np.abs(f2)

plt.subplot(141),plt.imshow(img, cmap = 'gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])

plt.subplot(142),plt.imshow(magnitude_spectrum, cmap = 'gray')
plt.title('Magnitude Spectrum'), plt.xticks([]), plt.yticks([])

plt.subplot(143),plt.imshow(f2, cmap = 'gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])

plt.subplot(144),plt.imshow(magnitude_spectrum2, cmap = 'gray')
plt.title('Magnitude Spectrum'), plt.xticks([]), plt.yticks([])

plt.show()