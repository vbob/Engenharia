package util;

import javax.swing.JOptionPane;

public class ExibirVetorUtil {
    
    public void mostrarVetorTela(int vetor[]) {
        String mensagem = "";
        for (int x = 0; x < vetor.length; x++) {
            mensagem += vetor[x];
            if (x != vetor.length - 1) {
                mensagem += ", ";
            }
        }
        JOptionPane.showMessageDialog(null, mensagem, "Dados Vetor", JOptionPane.INFORMATION_MESSAGE);
    }

    public void mostrarVetorConsole(int vetor[]) {
        for (int x = 0; x < vetor.length; x++) {
            System.out.print(vetor[x]);
            if (x != vetor.length - 1) {
                System.out.print(", ");
            }
        }
    }
    
}
