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
public class Aluno {
    private int matricula;
    private String nome;
    private Nota nota1;
    private Nota nota2;

    public Aluno() {
        this.nota1 = new Nota();
        this.nota2 = new Nota();
    }
    
    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public float getNota1() {
        return nota1.getValor();
    }
    
    public int getPesoNota1() {
        return nota1.getPeso();
    }

    public void setNota1(float nota1) {
        this.nota1.setValor(nota1);
    }

    public void setPesoNota1(int peso) {
        this.nota1.setPeso(peso);
    }
    
    public float getNota2() {
        return nota2.getValor();
    }
    
    public int getPesoNota2() {
        return nota2.getPeso();
    }

    public void setNota2(float nota1) {
        this.nota2.setValor(nota1);
    }

    public void setPesoNota2(int peso) {
        this.nota2.setPeso(peso);
    }
    
    public float getMedia() {
        return (this.nota1.getValor() * this.nota1.getPeso() + 
                this.nota2.getValor() *this.nota2.getPeso()) /
                (this.nota1.getPeso() + this.nota2.getPeso());
        
    }
    
    
}
