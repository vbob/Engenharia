/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package conceito;

import javax.swing.JOptionPane;

/**
 *
 * @author vbob
 */
public class Agencia {
    private int codigo;
    private String nome;
    private Banco banco;
    private String endereco;
    
    public Agencia(int codigo, String nome, String endereco, Banco banco) {
        this.setCodigo(codigo);
        this.setNome(nome);
        this.setEndereco(endereco);
        this.setBanco(banco);
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        if (codigo > 0) {
            this.codigo = codigo;
        } else {
            JOptionPane.showMessageDialog(null, "Código deve ser maior que zero");
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        if (nome!=null && nome.length() > 0) {
            this.nome = nome;
        } else {
            JOptionPane.showMessageDialog(null, "Nome não pode ser nulo");
        }
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
         if (endereco!=null && endereco.length() > 0) {
            this.endereco = endereco;
        } else {
            JOptionPane.showMessageDialog(null, "Endereço não pode ser nulo");
        }
    }

    public Banco getBanco() {
        return banco;
    }

    public void setBanco(Banco banco) {
        if (banco != null){        
            this.banco = banco;
        } else {
            JOptionPane.showMessageDialog(null, "Banco não pode ser nulo");
        }
    }
    
    
}
