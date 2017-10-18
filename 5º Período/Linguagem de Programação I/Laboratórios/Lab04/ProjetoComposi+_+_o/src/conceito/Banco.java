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
class Banco {
    private int codigo;
    private String nome;

    public Banco(int codigo, String nome) {
        this.setCodigo(codigo);
        this.setNome(nome);
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
}
