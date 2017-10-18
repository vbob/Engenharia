package exercicioproduto;

public class Aplicacao {

    public static void main(String[] args) {
        Produto pro1, pro2;
        
        pro1 = new Produto();
        pro1.setNome("yyyyyyyyyyyyyyyy");
        pro1.setPreco(100);
        pro1.setMargem(30);
        System.out.println("nome = " + pro1.getNome());
        System.out.println("preco de venda " + pro1.calcularValorVenda());
        
        pro2 = new Produto();
        pro2.setNome("xxxxxxxxxxxxxxxxxx");
        pro2.setPreco(200);
        pro2.setMargem(30);
        System.out.println("nome = " + pro2.getNome());
        System.out.println("preco de venda " + pro2.calcularValorVenda());
    }
    
}
