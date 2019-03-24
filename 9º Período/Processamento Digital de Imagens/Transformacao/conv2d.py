import scipy.signal as signal
import cv2
import numpy as np
import math

def conv2(img, w):
    r1 = int((w.shape[0]-1)/2)
    r2 = int((w.shape[1]-1)/2)
    if (len(img.shape)>2):
        imagem_intermediaria = np.zeros((img.shape[0] +  w.shape[0]-1, img.shape[1] + w.shape[1]-1, img.shape[2]), np.uint8)
    else: 
        imagem_intermediaria = np.zeros((img.shape[0] +  w.shape[0]-1, img.shape[1] + w.shape[1]-1), np.uint8)

    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            for k in range(w.shape[1]):
                imagem_intermediaria[w.shape[0]-2+i][w.shape[1]-2+j][k] = img[i][j][k]

    saida = np.zeros_like(img, np.uint8)

    for l in range(img.shape[0]):
        for c in range(img.shape[1]):
            a = r1
            for s in range(w.shape[0]):
                b = r2
                for t in range(w.shape[1]):
                    for k in range(w.shape[1]):
                        saida[l][c][k] = saida[l][c][k] + w[s][t]*imagem_intermediaria[l+a+r1][c+b+r2][k]
                    b-=1
                a-=1

    return np.array(saida, np.uint8)

filtro = np.array([[1,  2,  1],
                   [2, -8,  2],
                   [1,  2,  1]], np.uint8)

imagem = cv2.imread('./ImagemFlor.jpg')


cv2.namedWindow('image', cv2.WINDOW_NORMAL)
cv2.imshow('image',imagem)

cv2.namedWindow('filtrada', cv2.WINDOW_NORMAL)
cv2.imshow('filtrada',conv2(imagem, filtro))

cv2.waitKey(0)
cv2.destroyAllWindows()