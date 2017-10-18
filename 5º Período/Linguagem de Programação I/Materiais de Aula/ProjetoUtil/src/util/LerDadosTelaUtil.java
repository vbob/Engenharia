package util;

import javax.swing.JOptionPane;

public class LerDadosTelaUtil {

    public int lerInt(String mensagem) {
        String sInt;
        int valor = 0;
        boolean leu = false;
        do {
            sInt = JOptionPane.showInputDialog(mensagem);
            try {
                valor = Integer.parseInt(sInt);
                leu = true;
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, "Valor fornecido nao e valido - "
                        + ex.getMessage(), "Erro de digitacao", JOptionPane.ERROR_MESSAGE);
            }
        } while (!leu);
        return valor;
    }

    public float lerFloat(String mensagem) {
        String sFloat;
        float valor = 0;
        boolean leu = false;
        do {
            sFloat = JOptionPane.showInputDialog(mensagem);
            try {
                valor = Float.parseFloat(sFloat);
                leu = true;
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, "Valor fornecido nao e valido - "
                        + ex.getMessage(), "Erro de digitacao", JOptionPane.ERROR_MESSAGE);
            }
        } while (!leu);
        return valor;
    }

    public double lerDouble(String mensagem) {
        String sDouble;
        double valor = 0;
        boolean leu = false;
        do {
            sDouble = JOptionPane.showInputDialog(mensagem);
            try {
                valor = Double.parseDouble(sDouble);
                leu = true;
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, "Valor fornecido nao e valido - "
                        + ex.getMessage(), "Erro de digitacao", JOptionPane.ERROR_MESSAGE);
            }
        } while (!leu);
        return valor;
    }

    public void lerVetor(int vetor[]) {
        for (int x = 0; x < vetor.length; x++) {
            vetor[x] = this.lerInt("Forneca o valor do elemento [" + x + "]");
        }
    }

}
