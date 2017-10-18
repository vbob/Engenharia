/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicação;

import conceito.Produto4;

/**
 *
 * @author vbob
 */
public class Aplicacao3 {
    
    public static void main(String[] args) {
        Produto4 pao1 = new Produto4();
        pao1.setEstoque(100);
        System.out.println("---- PAO 1 -----");
        System.out.println("Nome............: " + pao1.getNome());
        System.out.println("Unidade Medida..: " + pao1.getUnidadeMedida());
        System.out.println("Preco...........: " + pao1.getPreco());
        System.out.println("Estoque.........: " + pao1.getEstoque());
        System.out.println("Total...........: " + pao1.totalizar(0.4f));


        Produto4 pao3 = new Produto4("Pao Frances", "Un");
        pao3.setEstoque(100);
        System.out.println("\n---- PAO 3 -----");
        System.out.println("Nome............: " + pao3.getNome());
        System.out.println("Unidade Medida..: " + pao3.getUnidadeMedida());
        System.out.println("Preco...........: " + pao3.getPreco());
        System.out.println("Estoque.........: " + pao3.getEstoque());
        
        System.out.println("Total...........: " + pao3.totalizar(0.4f));        
        
        Produto4 pao2 = new Produto4("Pao Frances", "Pc", 6f);
        pao2.setEstoque(100);
        System.out.println("\n---- PAO 2 -----");
        System.out.println("Nome............: " + pao2.getNome());
        System.out.println("Unidade Medida..: " + pao2.getUnidadeMedida());
        System.out.println("Preco...........: " + pao2.getPreco());
        System.out.println("Estoque.........: " + pao2.getEstoque());
        
        System.out.println("Total...........: " + pao2.totalizar(0.4f));
    }
}
