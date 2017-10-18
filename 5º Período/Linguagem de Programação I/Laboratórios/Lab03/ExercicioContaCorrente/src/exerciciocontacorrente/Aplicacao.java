package exerciciocontacorrente;

public class Aplicacao {

    public static void main(String[] args) {
        ContaCorrente cc = new ContaCorrente();
        cc.setBanco(1);
        cc.setAgencia(232);
        cc.setConta(5023);
        cc.setLimite(100);
        cc.depositar(200);
        
        System.out.println("Saldo: " + cc.getSaldo());
        
        cc.sacar(250);
        
        System.out.println("Saldo: " + cc.getSaldo());
        System.out.println("Disponivel: " + cc.getDisponivel());
        
        
    }
    
}
