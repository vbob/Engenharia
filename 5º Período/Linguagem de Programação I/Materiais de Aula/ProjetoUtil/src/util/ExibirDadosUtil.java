package util;

import javax.swing.JOptionPane;

public class ExibirDadosUtil {
    
    public void exibirTela(String mensagem) {
        JOptionPane.showMessageDialog(null, mensagem, "Dados Vetor", JOptionPane.INFORMATION_MESSAGE);
    }

    public void exibirConsole(String mensagem) {
        System.out.println(mensagem);
    }
    
    public void exibirTela(String mensagem, int valor) {
        mensagem += valor;
        JOptionPane.showMessageDialog(null, mensagem, "Dados Vetor", JOptionPane.INFORMATION_MESSAGE);
    }

    public void exibirConsole(String mensagem, int valor) {
        mensagem += valor;
        System.out.println(mensagem);
    }
    
    public void exibirTela(String mensagem, float valor) {
        mensagem += valor;
        JOptionPane.showMessageDialog(null, mensagem, "Dados Vetor", JOptionPane.INFORMATION_MESSAGE);
    }

    public void exibirConsole(String mensagem, float valor) {
        mensagem += valor;
        System.out.println(mensagem);
    }
    
}
