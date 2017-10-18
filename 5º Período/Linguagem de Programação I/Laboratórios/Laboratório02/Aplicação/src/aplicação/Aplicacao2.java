/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicação;

import conceito.Produto3;

/**
 *
 * @author vbob
 */
public class Aplicacao2 {
    public static void main(String[] args) {
        
        Produto3 pao1 = new Produto3();
        pao1.setEstoque(100);
        System.out.println("---- PAO 1 -----");
        System.out.println("Nome............: " + pao1.getNome());
        System.out.println("Unidade Medida..: " + pao1.getUnidadeMedida());
        System.out.println("Preco...........: " + pao1.getPreco());
        System.out.println("Estoque.........: " + pao1.getEstoque());
        System.out.println("Total...........: " + pao1.totalizar(0.4f));
        
        
        Produto3 pao2 = new Produto3("Pao Frances", "Kg", 6f);
        pao2.setEstoque(100);
        System.out.println("\n---- PAO 2 -----");
        System.out.println("Nome............: " + pao2.getNome());
        System.out.println("Unidade Medida..: " + pao2.getUnidadeMedida());
        System.out.println("Preco...........: " + pao2.getPreco());
        System.out.println("Estoque.........: " + pao2.getEstoque());
        
        System.out.println("Total...........: " + pao2.totalizar(0.4f));
    }
}
