package conceito;

public class Comodo {

    private float largura;
    private float comprimento;
    private int potenciaLampada;
    private TipoComodo tipoComodo;

    public float getLargura() {
        return largura;
    }

    public void setLargura(float largura) {
        this.largura = largura;
    }

    public float getComprimento() {
        return comprimento;
    }

    public void setComprimento(float comprimento) {
        this.comprimento = comprimento;
    }

    public int getPotenciaLampada() {
        return potenciaLampada;
    }

    public void setPotenciaLampada(int potenciaLampada) {
        this.potenciaLampada = potenciaLampada;
    }

    public TipoComodo getTipoComodo() {
        return tipoComodo;
    }

    public void setTipoComodo(TipoComodo tipoComodo) {
        this.tipoComodo = tipoComodo;
    }

    public float obterArea() {
        return this.largura * this.comprimento;
    }

    public float obterPotenciaIluminacao() {
        int potenciaIluminacao = 0;

        switch (this.tipoComodo) {
            case QUARTO:
                potenciaIluminacao = 15;
                break;
            case SALA_TV:
                potenciaIluminacao = 15;
                break;
            case SALA:
                potenciaIluminacao = 18;
                break;
            case COZINHA:
                potenciaIluminacao = 18;
                break;
            case VARANDA:
                potenciaIluminacao = 18;
                break;
            case ESCRITORIO:
                potenciaIluminacao = 20;
                break;
            case BANHEIRO:
                potenciaIluminacao = 20;
                break;
        }
        
        return potenciaIluminacao*this.obterArea();
    }
    
    public int obterQtdLampadas() {
        return (int) Math.ceil(this.obterPotenciaIluminacao()/this.potenciaLampada);
    }

}
