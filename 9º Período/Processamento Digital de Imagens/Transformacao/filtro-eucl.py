import cv2
import numpy as np
from matplotlib import pyplot as plt
import math

def points_in_circle_np(radius):
    a = np.arange(radius + 1)
    for x, y in zip(*np.where(a[:,np.newaxis]**2 + a**2 <= radius**2)):
        yield from set(((x, y), (x, -y), (-x, y), (-x, -y),))

img = cv2.imread('ImagemPeixes.jpg',0)
fp = np.zeros((np.max(img.shape)*2, np.max(img.shape)*2), dtype=np.int32)

fp[:img.shape[0], :img.shape[1]] = img

fft = np.fft.fft2(fp)
fftshift = np.fft.fftshift(fft)

filtro = np.zeros((np.max(img.shape)*2, np.max(img.shape)*2), dtype=np.int32)
raio = 25

for i in range(filtro.shape[0]):
    for j in range(filtro.shape[1]):
        if (math.sqrt(pow(i, 2) + pow(j, 2)) <= raio):
            filtro[i][j] = 1    

plt.subplot(241),plt.imshow(img, cmap = 'gray')
plt.title('Entrada'), plt.xticks([]), plt.yticks([])

plt.subplot(242),plt.imshow(fp, cmap = 'gray')
plt.title('Imagem Preenchida'), plt.xticks([]), plt.yticks([])

plt.subplot(243),plt.imshow(20*np.log(np.abs(fft)), cmap = 'gray')
plt.title('Espectro'), plt.xticks([]), plt.yticks([])

plt.subplot(244),plt.imshow(20*np.log(np.abs(fftshift)), cmap = 'gray')
plt.title('Espectro Rotacionado'), plt.xticks([]), plt.yticks([])

plt.subplot(245),plt.imshow(filtro, cmap = 'gray')
plt.title('Filtro'), plt.xticks([]), plt.yticks([])

plt.show()
