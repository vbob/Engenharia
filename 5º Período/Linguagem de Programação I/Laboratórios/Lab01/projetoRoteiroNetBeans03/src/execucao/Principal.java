/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package execucao;

import conceito.Retangulo;
import javax.swing.JOptionPane;

/**
 *
 * @author vbob
 */
public class Principal {
    public static void main(String[] args) {
        Retangulo ret = new Retangulo();
        
        ret.setComprimento(Float.parseFloat(JOptionPane.showInputDialog("Digite o Comprimento")));
        ret.setLargura(Float.parseFloat(JOptionPane.showInputDialog("Digite a Largura")));
        
        JOptionPane.showMessageDialog(null, "A área é " + ret.obterArea());
              
    }
}
