/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicacao;

import javax.swing.JOptionPane;
import negocio.Retangulo;

/**
 *
 * @author vbob
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Retangulo ret1;
        ret1 = new Retangulo();
        
        float larg, comp;
        String sLarg, sComp;
        
        sLarg = JOptionPane.showInputDialog("Forneça a largura do retângulo");
        sComp = JOptionPane.showInputDialog("Forneça o comprimento do retângulo");
        
        larg = Float.parseFloat(sLarg);
        comp = Float.parseFloat(sComp);
        
        ret1.largura = larg;
        ret1.comprimento = comp;
        
        JOptionPane.showMessageDialog(null, "A área do retângulo é " + ret1.obterArea());
    }
    
}
