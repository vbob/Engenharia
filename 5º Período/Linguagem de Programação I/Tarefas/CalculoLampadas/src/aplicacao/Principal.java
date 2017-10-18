package aplicacao;

import conceito.Residencia;
import conceito.TipoComodo;

public class Principal {

    public static void main(String[] args) {
        Residencia residencia = new Residencia(20);

        residencia.adicionarComodo(TipoComodo.SALA, 5.57f, 3.0f);
        residencia.adicionarComodo(TipoComodo.SALA_TV, 8.4f, 4.5f);
        residencia.adicionarComodo(TipoComodo.ESCRITORIO, 3, 5);
        residencia.adicionarComodo(TipoComodo.BANHEIRO, 4, 4.9f);
        
        residencia.listarComodos();
        residencia.listarTotal();
    }
}
