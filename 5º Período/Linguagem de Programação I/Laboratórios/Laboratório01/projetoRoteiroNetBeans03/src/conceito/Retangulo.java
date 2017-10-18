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
public class Retangulo {
    private float largura;
    private float comprimento;

    /**
     * @return the largura
     */
    public float getLargura() {
        return largura;
    }

    /**
     * @param largura the largura to set
     */
    public void setLargura(float largura) {
        this.largura = largura;
    }

    /**
     * @return the comprimento
     */
    public float getComprimento() {
        return comprimento;
    }

    /**
     * @param comprimento the comprimento to set
     */
    public void setComprimento(float comprimento) {
        this.comprimento = comprimento;
    }
    
    public float obterArea() {
        return this.largura * this.comprimento;
    }
}
