package aplicacao;

import conceito.Estoque;
import conceito.Mercadoria;

public class Principal {

    public static void main(String[] args) {

        Mercadoria mercadoria;
        Estoque estoque = new Estoque();

        mercadoria = new Mercadoria();
        mercadoria.setNome("Parafuso");
        mercadoria.setPrecoCompra(0.5f);
        mercadoria.setQtdCompra(500);
        mercadoria.setPrecoVenda(0.5f);
        mercadoria.setQtdVenda(4200);
        estoque.adicionarMercadoria(mercadoria);

        mercadoria = new Mercadoria();
        mercadoria.setNome("Tijolo");
        mercadoria.setPrecoCompra(0.10f);
        mercadoria.setQtdCompra(1000);
        mercadoria.setPrecoVenda(0.14f);
        mercadoria.setQtdVenda(3000);
        estoque.adicionarMercadoria(mercadoria);

        mercadoria = new Mercadoria();
        mercadoria.setNome("Furadeira");
        mercadoria.setPrecoCompra(25.0f);
        mercadoria.setQtdCompra(80);
        mercadoria.setPrecoVenda(400f);
        mercadoria.setQtdVenda(70);
        estoque.adicionarMercadoria(mercadoria);

        System.out.println("Compra Total: R$" + estoque.obterValorTotalComprado());
        System.out.println("Venda Total: R$" + estoque.obterValorTotalVendido());
        System.out.println("Lucro Total: R$" + estoque.obterLucroTotal());
        System.out.println("Mercadoria Mais Comprada: " + estoque.obterMercadoriaMaisComprada().getNome());
        System.out.println("Mercadoria Menos Comprada: " + estoque.obterMercadoriaMenosComprada().getNome());
        System.out.println("Mercadoria Mais Vendida: " + estoque.obterMercadoriaMaisVendida().getNome());
        System.out.println("Mercadoria Menos Vendida: " + estoque.obterMercadoriaMenosVendida().getNome());
    }
}
