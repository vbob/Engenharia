/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicação;

import conceito.Produto2;

/**
 *
 * @author vbob
 */
public class Aplicação {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Produto2 pao;
        
        pao = new Produto2("Pao Frances", "Kg", 6f);
        pao.setEstoque(100);
        
        System.out.println("Nome...........: " + pao.getNome());
        System.out.println("Unidade Medida.: " + pao.getUnidadeMedida());
        System.out.println("Preco..........: " + pao.getPreco());
        System.out.println("Estoque........: " + pao.getEstoque());
        
        System.out.println("Total..........: " + pao.totalizar(0.4f));
    }
    
}
