/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicacao;

import java.util.Scanner;

/**
 *
 * @author vbob
 */
public class Principal {
    int num1, num2, soma;
    
    void lerDados(){
        Scanner entrada = new Scanner(System.in);
        System.out.println("Forneça o primeiro valor: ");
        num1 = entrada.nextInt();
        
        System.out.println("Forneça o segundo valor: ");
        num2 = entrada.nextInt();
    }
    
    int somar() {
        return num1+num2;
    }
    
    void mostrarResultado() {
        System.out.println("O resultado da soma é: " + somar());
    }
    
    
    public static void main(String[] args) {
        Principal principal = new Principal();
        principal.lerDados();
        principal.mostrarResultado();
    }
    
}
