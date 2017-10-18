package exercicioVeiculo;

import javax.swing.JOptionPane;

public class Aplicacao01 {

    public static void main(String[] args) {
        Veiculo vcl;
        
        vcl = new Veiculo("Fiat", "Palio");
        
        vcl.setPlaca("XZY 7070");
        vcl.setChassi("ZZZ234567MT26787");
        
        vcl.zeraQuilometragem();
        vcl.esvaziarTanque();
        
        vcl.abastecer(40);
        vcl.andou(150, 140);
        
        String resultado = "O veículo " + vcl.getMarca() + " " + vcl.getModelo() +
                           "\nPlaca " + vcl.getPlaca() + " e Chassi " + vcl.getChassi() +
                           "\nEstá com " + vcl.getQuilometragemAtual() + " Km" +
                           "\nE está com " + vcl.getQuantidadeCombustivel() + " Litros de Combustível";
        
        JOptionPane.showMessageDialog(null, resultado, "Resultado", JOptionPane.INFORMATION_MESSAGE);
        
        System.exit(0);
    }
    
}
