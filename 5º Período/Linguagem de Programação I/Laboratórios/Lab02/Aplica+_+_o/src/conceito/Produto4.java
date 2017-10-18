/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package conceito;

/**
 *
 * @author vbob
 */
public class Produto4 {
      private String nome;
    private String unidadeMedida;
    private float preco;
    private int estoque;
    
    public Produto4() {
        unidadeMedida = "Kg";
        estoque = 1;
    }
    
    public Produto4(String nome) {
        this();
        this.nome = nome;
    }
    
    public Produto4(String nome, String unidadeMedida) {
        this(nome);
        this.unidadeMedida = unidadeMedida;
    }  
    
    public Produto4(String nome, String unidadeMedida, float preco) {
        this(nome, unidadeMedida);
        this.preco = preco;
    }

    /**
     * @return the nome
     */
    public String getNome() {
        return nome;
    }

    /**
     * @param nome the nome to set
     */
    public void setNome(String nome) {
        this.nome = nome;
    }

    /**
     * @return the unidadeMedida
     */
    public String getUnidadeMedida() {
        return unidadeMedida;
    }

    /**
     * @param unidadeMedida the unidadeMedida to set
     */
    public void setUnidadeMedida(String unidadeMedida) {
        this.unidadeMedida = unidadeMedida;
    }

    /**
     * @return the preco
     */
    public float getPreco() {
        return preco;
    }

    /**
     * @param preco the preco to set
     */
    public void setPreco(float preco) {
        this.preco = preco;
    }

    /**
     * @return the estoque
     */
    public int getEstoque() {
        return estoque;
    }

    /**
     * @param estoque the estoque to set
     */
    public void setEstoque(int estoque) {
        this.estoque = estoque;
    }
    
    public float totalizar(float quantidade) {
        return quantidade*preco;
    }
}
