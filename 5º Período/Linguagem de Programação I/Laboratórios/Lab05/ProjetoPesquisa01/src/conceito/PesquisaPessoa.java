package conceito;

import java.util.ArrayList;

public class PesquisaPessoa {

    private ArrayList<Pessoa> listaPessoa;
    
    public PesquisaPessoa() {
        this.listaPessoa = new ArrayList();
    }

    public void adicionarPessoa(Pessoa pessoa) {
        this.listaPessoa.add(pessoa);
    }

    public ArrayList<Pessoa> obterListaPessoa() {
        return this.listaPessoa;
    }

    public int obterNumeroTotalPessoa() {
        return this.listaPessoa.size();
    }

    public int obterMaiorIdade() {
        int maior = 0;
        if (this.listaPessoa.size() > 0) {
            maior = this.listaPessoa.get(0).getIdade();
        }

        for (Pessoa pessoaTemp : this.listaPessoa) {
            if (pessoaTemp.getIdade() > maior) {
                maior = pessoaTemp.getIdade();
            }
        }

        return maior;
    }

    public int obterSomaIdade() {
        int soma = 0;
        for (Pessoa pessoaTemp : this.listaPessoa) {
            soma = + pessoaTemp.getIdade();
        }
        return soma;
    }

    public float obterMediaIdade() {
        return this.obterSomaIdade() / this.listaPessoa.size();
    }

    public int obterPessoaPorFaixaIdade2035() {
        int resposta = 0;

       for (Pessoa pessoaTemp : this.listaPessoa) {
            if (pessoaTemp.getIdade() >= 20 && pessoaTemp.getIdade() <= 35) {
                resposta++;
            }
        }

        return resposta;
    }

    public int obterPessoaPorFaixaIdade1835_F_Verde_Louro() {
        int resposta = 0;

        for (Pessoa pessoaTemp : this.listaPessoa) {
            if (pessoaTemp.getSexo() == Sexo.FEMININO) {
                if (pessoaTemp.getIdade() >= 18 && pessoaTemp.getIdade() <= 35) {
                    if (pessoaTemp.getCorOlhos() == CorOlho.VERDE && pessoaTemp.getCorCabelo() == CorCabelo.LOIRO) {
                        resposta++;
                    }
                }
            }
        }

        return resposta;
    }

}
