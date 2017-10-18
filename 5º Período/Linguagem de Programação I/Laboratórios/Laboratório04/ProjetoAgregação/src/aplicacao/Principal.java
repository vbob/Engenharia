/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicacao;

import conceito.Aluno;
import conceito.Nota;

/**
 *
 * @author vbob
 */
public class Principal {
    public static void main(String[] args) {
        Aluno aluno = new Aluno();
        
        aluno.setMatricula(1234);
        aluno.setNome("Vitor");
        
        aluno.setNota1(10);
        aluno.setPesoNota1(1);
        
        aluno.setNota2(4);
        aluno.setPesoNota2(5);
        
        System.out.println();
        System.out.println("Matricula: " + aluno.getMatricula());
        System.out.println("Nome: " + aluno.getNome());
        System.out.println("Peso1: " + aluno.getPesoNota1());
        System.out.println("Nota1: " + aluno.getNota1());
        System.out.println("Peso2: " + aluno.getPesoNota2());
        System.out.println("Nota2: " + aluno.getNota2());
        System.out.println("Média: " + aluno.getMedia());
        System.out.println();
    }
}
