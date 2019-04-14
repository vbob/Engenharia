import cv2
import numpy as np
from matplotlib import pyplot as plt
import math
import random as rand
from scipy import stats

rand.seed(5)

def ruidoSaltPepper(image):
    for i in range(image.shape[0]-1, 0, rand.randint(-3,-1)):
        for j in range(image.shape[1]-1, 0, rand.randint(-3,-1)):
            if (rand.randint(0,1) == 1):
                image[i][j] = rand.randint(0,1)*255

def filtrar(image, imagemMedia, imagemModa, imagemMediana):          
    for i in range(image.shape[0]):
            for j in range(image.shape[1]):
                if (image[i][j] == 0 or image[i][j] == 255):
                    vetor = np.full((8), 127)
                    
                    if i-1 >= 0:
                        vetor[0] = image[i-1][j-1] if j-1 >= 0 else 127
                        vetor[1] = image[i-1][j] 
                        vetor[2] = image[i-1][j+1] if j+1 < image.shape[1] else 127

                    vetor[3] = image[i][j-1] if j-1 >= 0 else 127
                    vetor[4] = image[i][j+1] if j+1 < image.shape[1] else 127

                    if i+1 < image.shape[0]:
                        vetor[5] = image[i+1][j-1] if j-1 >= 0 else 127
                        vetor[6] = image[i+1][j] 
                        vetor[7] = image[i+1][j+1] if j+1 < image.shape[1] else 127
            
                    imagemMedia[i][j] = np.average(vetor)
                    imagemMediana[i][j] = np.median(vetor)
                    imagemModa[i][j] = stats.mode(vetor)[0]    


img = cv2.imread('ImagemPeixes.jpg',0)

plt.subplot(231),plt.imshow(img, cmap = 'gray')
plt.title('Entrada'), plt.xticks([]), plt.yticks([])

ruidoSaltPepper(img)

plt.subplot(232),plt.imshow(img, cmap = 'gray')
plt.title('Entrada com Ruido'), plt.xticks([]), plt.yticks([])

imagemMedia = img
imagemMediana = img
imagemModa = img
filtrar(img, imagemMedia, imagemMediana, imagemMedia)

plt.subplot(233),plt.imshow(imagemMedia, cmap = 'gray')
plt.title('Imagem Restaurada com Média'), plt.xticks([]), plt.yticks([])

plt.subplot(234),plt.imshow(imagemMediana, cmap = 'gray')
plt.title('Imagem Restaurada com Mediana'), plt.xticks([]), plt.yticks([])

plt.subplot(235),plt.imshow(imagemModa, cmap = 'gray')
plt.title('Imagem Restaurada com Moda'), plt.xticks([]), plt.yticks([])

plt.show()