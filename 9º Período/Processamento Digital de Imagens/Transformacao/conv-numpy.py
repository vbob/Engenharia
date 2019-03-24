'''
Created on Jul 13, 2015
@author: kashefy
'''
import numpy as np
import cv2
import math

if __name__ == '__main__':

    x = cv2.imread('./ImagemPeixes.jpg', 0)

    cv2.namedWindow('image', cv2.WINDOW_AUTOSIZE)
    cv2.imshow('image',x)

    w_1 = np.array([[-1, -2, -1],
                    [0, 0, 0],
                    [1, 2, 1]])

    f1 = cv2.filter2D(x, -1, w_1)

    w_2 = np.array([[-1, 0, 1],
                    [-2, 0, 2],
                    [-1, 0, 1]])

    f2 = cv2.filter2D(x, -1, w_2)

    w_3 = np.array([[-2, -2, 0],
                    [-2, 0, 2],
                    [0, 2, 2]])

    f3 = cv2.filter2D(x, -1, w_3)
    
    cv2.namedWindow('filtro1', cv2.WINDOW_AUTOSIZE)
    cv2.imshow('filtro1', f1)

    cv2.namedWindow('filtro2', cv2.WINDOW_AUTOSIZE)
    cv2.imshow('filtro2', f2)

    saida = np.zeros_like(f1, np.uint8)

    for x in range(f1.shape[0]):
        for y in range(f1.shape[1]):
            saida[x][y] = abs(f1[x][y]) + abs(f2[x][y])

    cv2.namedWindow('saida', cv2.WINDOW_AUTOSIZE)
    cv2.imshow('saida', saida)

    cv2.namedWindow('saida_filtro2', cv2.WINDOW_AUTOSIZE)
    cv2.imshow('saida_filtro2', f3)

    saida_filtro2 = np.subtract(saida, f3) 

    cv2.namedWindow('diferenca_saidas', cv2.WINDOW_AUTOSIZE)
    cv2.imshow('diferenca_saidas', saida_filtro2)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

    pass