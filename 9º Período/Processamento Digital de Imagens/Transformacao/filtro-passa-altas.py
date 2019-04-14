import cv2
import numpy as np
from matplotlib import pyplot as plt
import math

img = cv2.imread('ImagemPeixes.jpg',0)
fp = np.zeros((np.max(img.shape)*2, np.max(img.shape)*2), dtype=np.int32)

fp[:img.shape[0], :img.shape[1]] = img

fft = np.fft.fft2(fp)
fftshift = np.fft.fftshift(fft)

filtro = np.zeros((np.max(img.shape)*2, np.max(img.shape)*2), dtype=np.int)
raio = 600
intensidade = 1

centroH = int(filtro.shape[0]/2)
centroV = int(filtro.shape[1]/2)

for i in range(filtro.shape[0]):
    for j in range(filtro.shape[1]):
        if (math.sqrt(pow(i-centroH, 2) + pow(j-centroV, 2)) > raio):
                raioAtual = math.sqrt(pow(i-centroH, 2) + pow(j-centroV, 2))
                ## filtro[i][j] = 10*math.exp(-(raioAtual)/800)
                filtro[i][j] = intensidade
                

fft_filtrada = filtro * fftshift
fftshift_filtrada = np.fft.ifftshift(fft_filtrada)
img_filtrada = np.fft.ifft2(fftshift_filtrada)

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

plt.subplot(246),plt.imshow(20*np.log(np.abs(fft_filtrada)), cmap = 'gray')
plt.title('Frequências Filtradas Rotacionadas'), plt.xticks([]), plt.yticks([])

plt.subplot(247),plt.imshow(20*np.log(np.abs(fftshift_filtrada)), cmap = 'gray')
plt.title('Frequências Filtradas'), plt.xticks([]), plt.yticks([])

plt.subplot(248),plt.imshow(np.abs(img_filtrada), cmap = 'gray')
plt.title('Imagem Filtrada'), plt.xticks([]), plt.yticks([])

plt.show()
