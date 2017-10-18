package exerciciocontacorrente;

public class ContaCorrente {
    private int banco;
    private int agencia;
    private int conta;
    private float saldo;
    private float taxa;
    private float limite;

    public int getBanco() {
        return banco;
    }

    public void setBanco(int banco) {
        this.banco = banco;
    }

    public int getAgencia() {
        return agencia;
    }

    public void setAgencia(int agencia) {
        this.agencia = agencia;
    }

    public int getConta() {
        return conta;
    }

    public void setConta(int conta) {
        this.conta = conta;
    }

    public float getTaxa() {
        return taxa;
    }

    public void setTaxa(float taxa) {
        if (taxa >0 && taxa < 100)
            this.taxa = taxa;
        else
            this.taxa = 0;
    }

    public float getLimite() {
        return limite;
    }

    public void setLimite(float limite) {
        if (limite > 0)
            this.limite = limite;
    }

    public void depositar(float valor) {
        if (valor > 0) 
            this.saldo +=valor;
    }
    
    public float sacar(float saque) {
        if (saldo+limite > saque+(saque*this.taxa/100)) {
            this.saldo -= saque+(saque*this.taxa/100);
            return saque+(saque*this.taxa/100);
        }
        else {
            System.out.println("O valor disponível não é suficiente para realizar este saque");
            return 0;
        }
    }
    
    public float getSaldo() {
        return saldo;
    }
    
    public float getDisponivel() {
        return saldo+limite;
    }
    
    
    
    
}
