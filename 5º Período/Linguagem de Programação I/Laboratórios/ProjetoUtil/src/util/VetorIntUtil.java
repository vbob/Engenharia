package util;

public class VetorIntUtil {

    public void preencherRandomicamente(int vetor[], int escala) {
        for (int x = 0; x < vetor.length; x++) {
            vetor[x] = (int) (Math.random() * escala);
        }
    }

    public int totalizarVetor(int vetor[]) {
        int total = 0;
        for (int valor : vetor) {
            total += valor;
        }
        return total;
    }

    public int buscarSequencial(int vetor[], int elemento) {
        int pos = -1, x = 0;
        boolean achou = false;
        while (!achou && x < vetor.length) {
            if (elemento == vetor[x]) {
                achou = true;
                pos = x;
            }
            x++;
        }
        return pos;
    }

    public int buscarBinaria(int vetor[], int elemento) {
        int pos = -1, inicio, fim, meio;

        inicio = 0;
        fim = vetor.length - 1;
        while (pos == -1 && inicio <= fim) {
            meio = (inicio + fim) / 2;
            if (elemento == vetor[meio]) {
                pos = meio;
            } else {
                if (vetor[meio] < elemento) {
                    inicio = meio + 1;
                } else {
                    fim = meio - 1;
                }
            }
        }
        return pos;
    }

    public void trocarElementos(int vetor[], int i, int j) {
        int aux;
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }

    public void ordenarBolha(int vetor[]) {
        for (int i = 0; i < vetor.length; i++) {
            for (int j = i + 1; j < vetor.length; j++) {
                if (vetor[i] > vetor[j]) {
                    this.trocarElementos(vetor, i, j);
                }
            }
        }
    }

    public void ordenarSelecao(int vetor[]) {
        int iMenor;

        for (int i = 0; i < vetor.length - 1; i++) {
            iMenor = i;
            for (int j = i + 1; j < vetor.length; j++) {
                if (vetor[j] < vetor[iMenor]) {
                    iMenor = j;
                }
            }
            this.trocarElementos(vetor, iMenor, i);
        }
    }
}
