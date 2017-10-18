package conceito;

import java.util.ArrayList;

public class Residencia {
    ArrayList<Comodo> listaComodos = new ArrayList();
    
    int potenciaLampada;
    
    public Residencia() {
        this.potenciaLampada = 20;
    }
    
    public Residencia(int potenciaLampada) {
        this.potenciaLampada = potenciaLampada;
    }
   
    public void adicionarComodo(TipoComodo tipoComodo, float largura, float comprimento) {
        Comodo comodo = new Comodo();
        comodo.setTipoComodo(tipoComodo);
        comodo.setLargura(largura);
        comodo.setComprimento(comprimento);
        comodo.setPotenciaLampada(this.potenciaLampada);
        this.listaComodos.add(comodo);
    }
    
    public void listarComodos() {
        for (Comodo comodoTemp : this.listaComodos) {
            System.out.println("\nTipo do Comodo: " + comodoTemp.getTipoComodo());
            System.out.println("Área: " + comodoTemp.obterArea() + "m²");
            System.out.println("Potência de Iluminação Necessária: " + comodoTemp.obterPotenciaIluminacao() + " W");
            System.out.println("Quantidade de Lâmpadas Necessárias: " + comodoTemp.obterQtdLampadas());
        }
    }
    
    public void listarTotal() {
        int lampadas = 0;
        float potencia = 0;
        
        for (Comodo comodoTemp : this.listaComodos) {
            lampadas += comodoTemp.obterQtdLampadas();
            potencia += comodoTemp.obterPotenciaIluminacao();
        }
        
        System.out.println("\nTotal de Lâmpadas: " + lampadas);
        System.out.println("Potência Total: " + potencia + " W");
    }
    
}
