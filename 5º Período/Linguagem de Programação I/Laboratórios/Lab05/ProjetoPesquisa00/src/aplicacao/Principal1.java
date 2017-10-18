package aplicacao;

import conceito.PesquisaPessoa;
import conceito.Pessoa;
import conceito.CorOlho;
import conceito.CorCabelo;
import conceito.Sexo;

public class Principal1 {
    public static void main(String[] args) {
        
        Pessoa pessoa;
        PesquisaPessoa pesquisa = new PesquisaPessoa();
        int totalPessoas, contador1;
        
        pessoa = new Pessoa();
        pessoa.setSexo(Sexo.FEMININO);
        pessoa.setCorCabelo(CorCabelo.PRETO);
        pessoa.setIdade(10);
        pessoa.setCorOlhos(CorOlho.AZUL);
        pesquisa.adicionarPessoa(pessoa);
                
        pessoa = new Pessoa();
        pessoa.setSexo(Sexo.FEMININO);
        pessoa.setCorCabelo(CorCabelo.LOIRO);
        pessoa.setIdade(30);
        pessoa.setCorOlhos(CorOlho.VERDE);
        pesquisa.adicionarPessoa(pessoa);
                
        pessoa = new Pessoa();
        pessoa.setSexo(Sexo.FEMININO);
        pessoa.setCorCabelo(CorCabelo.LOIRO);
        pessoa.setIdade(19);
        pessoa.setCorOlhos(CorOlho.VERDE);
        pesquisa.adicionarPessoa(pessoa);
                
        pessoa = new Pessoa();
        pessoa.setSexo(Sexo.MASCULINO);
        pessoa.setCorCabelo(CorCabelo.LOIRO);
        pessoa.setIdade(50);
        pessoa.setCorOlhos(CorOlho.VERDE);
        pesquisa.adicionarPessoa(pessoa);
        
        System.out.println("Maior Idade: " + pesquisa.obterMaiorIdade());
        System.out.println("Média de Idade: " + pesquisa.obterMediaIdade());
        
        totalPessoas = pesquisa.obterNumeroTotalPessoa();
        contador1 = pesquisa.obterPessoaPorFaixaIdade2035();
        
        System.out.println("Idade entre 20 e 35: " + contador1 + " - " + (contador1*100/totalPessoas) + "%");
        
        contador1 = pesquisa.obterPessoaPorFaixaIdade1835_F_Verde_Louro();
        
        System.out.println("Feminino, Idade entre 18 e 35, Olhos Verdes e Cabelos Loiros: " + contador1 + " - " + (contador1*100/totalPessoas) + "%");
        
        
    }
}
