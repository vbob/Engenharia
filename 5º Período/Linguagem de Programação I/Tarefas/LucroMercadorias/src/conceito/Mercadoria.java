package conceito;

public class Mercadoria {
    private String nome = new String();
    private float precoCompra;
    private int qtdCompra;
    private float precoVenda;
    private int qtdVenda;
    
    public void Mercadoria() {
        setNome("Mercadoria Padrão");
        setPrecoCompra(0.0f);
        setQtdCompra(0);
        setPrecoVenda(0.0f);
        setQtdVenda(0);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public float getPrecoCompra() {
        return precoCompra;
    }

    public void setPrecoCompra(float precoCompra) {
        this.precoCompra = precoCompra;
    }

    public int getQtdCompra() {
        return qtdCompra;
    }

    public void setQtdCompra(int qtdCompra) {
        this.qtdCompra = qtdCompra;
    }

    public float getPrecoVenda() {
        return precoVenda;
    }

    public void setPrecoVenda(float precoVenda) {
        this.precoVenda = precoVenda;
    }

    public int getQtdVenda() {
        return qtdVenda;
    }

    public void setQtdVenda(int qtdVenda) {
        this.qtdVenda = qtdVenda;
    }
    
    
}
