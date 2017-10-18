package util;

import java.util.Scanner;

public class LerDadosConsoleUtil {

    private final Scanner TECLADO;

    public LerDadosConsoleUtil(){
        this.TECLADO = new Scanner(System.in);
    }
    
    public int lerInt(String mensagem) {
        int valor = 0;
        boolean leu = false;
        do {
            try {
                valor = TECLADO.nextInt();
                leu = true;
            } catch (Exception ex) {
                System.out.println("Valor fornecido nao e valido - " + ex.getMessage());
            }
        } while (!leu);
        return valor;
    }

    public float lerFloat(String mensagem) {
        float valor = 0;
        boolean leu = false;
        do {
            try {
                valor = TECLADO.nextFloat();
                leu = true;
            } catch (Exception ex) {
                System.out.println("Valor fornecido nao e valido - " + ex.getMessage());
            }
        } while (!leu);
        return valor;
    }

    public double lerDouble(String mensagem) {
        double valor = 0;
        boolean leu = false;
        do {
            try {
                valor = TECLADO.nextDouble();
                leu = true;
            } catch (Exception ex) {
                System.out.println("Valor fornecido nao e valido - " + ex.getMessage());
            }
        } while (!leu);
        return valor;
    }

    public void lerVetor(int vetor[]) {
        for (int x = 0; x < vetor.length; x++) {
            vetor[x] = this.lerInt("Forneca o valor do elemento [" + x + "]");
        }
    }

    public void lerVetor(float vetor[]) {
        for (int x = 0; x < vetor.length; x++) {
            vetor[x] = this.lerFloat("Forneca o valor do elemento [" + x + "]");
        }
    }

    public void lerVetor(double vetor[]) {
        for (int x = 0; x < vetor.length; x++) {
            vetor[x] = this.lerDouble("Forneca o valor do elemento [" + x + "]");
        }
    }
}
