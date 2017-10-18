package conceito;

import java.util.ArrayList;

public class Estoque {

    ArrayList<Mercadoria> listaMercadorias;

    public Estoque() {
        this.listaMercadorias = new ArrayList();
    }

    public void adicionarMercadoria(Mercadoria mercadoria) {
        this.listaMercadorias.add(mercadoria);
    }

    public float obterValorTotalComprado() {
        float total = 0;

        for (Mercadoria mercadoriaTemp : this.listaMercadorias) {
            total += mercadoriaTemp.getPrecoCompra()*mercadoriaTemp.getQtdCompra();
        }

        return total;
    }

    public float obterValorTotalVendido() {
        float total = 0;

        for (Mercadoria mercadoriaTemp : this.listaMercadorias) {
            total += mercadoriaTemp.getPrecoVenda()*mercadoriaTemp.getQtdVenda();
        }

        return total;
    }

    public float obterLucroTotal() {
        return this.obterValorTotalVendido() - this.obterValorTotalComprado();
    }

    public Mercadoria obterMercadoriaMaisComprada() {
        Mercadoria mercadoriaMaisComprada = new Mercadoria();
        int qtdMaisComprada = 0;

        for (Mercadoria mercadoriaTemp : this.listaMercadorias) {
            if (mercadoriaTemp.getQtdCompra() > qtdMaisComprada) {
                qtdMaisComprada = mercadoriaTemp.getQtdCompra();
                mercadoriaMaisComprada = mercadoriaTemp;
            }
        }

        return mercadoriaMaisComprada;
    }

    public Mercadoria obterMercadoriaMenosComprada() {
        Mercadoria mercadoriaMenosComprada = new Mercadoria();
        int qtdMenosComprada = 0;
        
        if (this.listaMercadorias.size() > 0) {
            qtdMenosComprada = this.listaMercadorias.get(0).getQtdCompra();
        }

        for (Mercadoria mercadoriaTemp : this.listaMercadorias) {
            if (mercadoriaTemp.getQtdCompra() < qtdMenosComprada) {
                qtdMenosComprada = mercadoriaTemp.getQtdCompra();
                mercadoriaMenosComprada = mercadoriaTemp;
            }
        }

        return mercadoriaMenosComprada;
    }
    
        public Mercadoria obterMercadoriaMaisVendida() {
        Mercadoria mercadoriaMaisVendida = new Mercadoria();
        int qtdMaisVendida = 0;

        for (Mercadoria mercadoriaTemp : listaMercadorias) {
            if (mercadoriaTemp.getQtdVenda() > qtdMaisVendida) {
                qtdMaisVendida= mercadoriaTemp.getQtdVenda();
                mercadoriaMaisVendida = mercadoriaTemp;
            }
        }

        return mercadoriaMaisVendida;
    }

    public Mercadoria obterMercadoriaMenosVendida() {
        Mercadoria mercadoriaMenosVendida = new Mercadoria();
        int qtdMenosVendida = 0;
        
        if (this.listaMercadorias.size() > 0) {
            qtdMenosVendida = this.listaMercadorias.get(0).getQtdVenda();
        }

        for (Mercadoria mercadoriaTemp : this.listaMercadorias) {
            if (mercadoriaTemp.getQtdVenda() < qtdMenosVendida) {
                qtdMenosVendida = mercadoriaTemp.getQtdCompra();
                mercadoriaMenosVendida = mercadoriaTemp;
            }
        }

        return mercadoriaMenosVendida;
    }
}
