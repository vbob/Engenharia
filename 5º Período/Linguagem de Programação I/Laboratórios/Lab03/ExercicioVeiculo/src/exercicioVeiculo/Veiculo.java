package exercicioVeiculo;

public class Veiculo {
   private String marca;
   private String modelo;
   private String placa;
   private String chassi;
   private float quilometragemAtual;
   private float quantidadeCombustivel;
   public final int CAPACIDADE_TANQUE = 50;
   public final float MEDIA_CONSUMO_80 = 15;
   public final float MEDIA_CONSUMO_100 = 13;
   public final float MEDIA_CONSUMO_120 = 11;
   public final float MEDIA_CONSUMO_140 = 10;
   
   public Veiculo(String marca, String modelo) {
       this.marca = marca;
       this.modelo = modelo;
   }
   
   public Veiculo(String marca, String modelo, String placa, String chassi) {
       this.marca = marca;
       this.modelo = modelo;
       this.placa = placa;
       this.chassi = chassi;
   }

    /**
     * @return the marca
     */
    public String getMarca() {
        return marca;
    }

    /**
     * @param marca the marca to set
     */
    public void setMarca(String marca) {
        this.marca = marca;
    }

    /**
     * @return the modelo
     */
    public String getModelo() {
        return modelo;
    }

    /**
     * @param modelo the modelo to set
     */
    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    /**
     * @return the placa
     */
    public String getPlaca() {
        return placa;
    }

    /**
     * @param placa the placa to set
     */
    public void setPlaca(String placa) {
        this.placa = placa;
    }

    /**
     * @return the chassi
     */
    public String getChassi() {
        return chassi;
    }

    /**
     * @param chassi the chassi to set
     */
    public void setChassi(String chassi) {
        this.chassi = chassi;
    }
   
   public void zeraQuilometragem() {
       quilometragemAtual =0;
   }
   
   public void esvaziarTanque() {
       quantidadeCombustivel = 0;
   }
   
   public void abastecer(float combustivel) {
       if (combustivel > 0 && quantidadeCombustivel + combustivel < CAPACIDADE_TANQUE)
           quantidadeCombustivel += combustivel;
       else 
           quantidadeCombustivel = CAPACIDADE_TANQUE;
   }
   
   public void andou(float quilometros, float velocidade) {
       float consumo = 0;
       
       if (velocidade < 80)
           consumo = quilometros / MEDIA_CONSUMO_80;
       if (velocidade > 80 && velocidade <= 100)
           consumo = quilometros / MEDIA_CONSUMO_100;
       if (velocidade > 100 && velocidade <= 120)
           consumo = quilometros / MEDIA_CONSUMO_120;
       if (velocidade > 120)
           consumo = quilometros / MEDIA_CONSUMO_140;
       
       quantidadeCombustivel -= consumo;
       quilometragemAtual += quilometros;
   }
   
   public float getQuilometragemAtual() {
       return quilometragemAtual;
   }
   
   public float getQuantidadeCombustivel() {
       return quantidadeCombustivel;
   }
   
}
