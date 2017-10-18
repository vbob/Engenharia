package exercicioproduto;

public class Produto {
    private String nome;
    private float preco;
    private float margem;

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
     * @return the preco
     */
    public float getPreco() {
        return preco;
    }

    /**
     * @param preco the preco to set
     */
    public void setPreco(float preco) {
        if (preco >= 0)
            this.preco = preco;
        else 
            this.preco = 0;
    }

    /**
     * @return the margem
     */
    public float getMargem() {
        return margem;
    }

    /**
     * @param margem the margem to set
     */
    public void setMargem(float margem) {
        if (margem >= 0 && margem <= 100)
            this.margem = margem;
        else
            this.margem = 0;
    }
    
    public float calcularValorVenda() {
        return preco + (preco*margem/100);
    }
    
    
    
}
