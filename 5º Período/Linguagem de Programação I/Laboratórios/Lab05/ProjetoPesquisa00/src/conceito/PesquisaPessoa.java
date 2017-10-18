package conceito;

public class PesquisaPessoa {

    private Pessoa listaPessoa[];
    private int numPessoa;

    public PesquisaPessoa() {
        this.numPessoa = 0;
        this.listaPessoa = new Pessoa[100];
    }

    public void adicionarPessoa(Pessoa pessoa) {
        if (this.numPessoa < 100) {
            this.listaPessoa[this.numPessoa] = pessoa;
            this.numPessoa++;
        } else {
            System.out.println("Capacidade de armazenamento chegou ao limite");
        }
    }

    public Pessoa[] obterListaPessoa() {
        return this.listaPessoa;
    }

    public int obterNumeroTotalPessoa() {
        return this.numPessoa;
    }

    public int obterMaiorIdade() {
        int maior = 0;
        if (this.numPessoa > 0) {
            maior = this.listaPessoa[0].getIdade();
        }

        for (int x = 0; x < this.numPessoa; x++) {
            if (this.listaPessoa[x].getIdade() > maior) {
                maior = this.listaPessoa[x].getIdade();
            }
        }

        return maior;
    }

    public int obterSomaIdade() {
        int soma = 0;
        for (int x = 0; x < this.numPessoa; x++) {
            soma = +this.listaPessoa[x].getIdade();
        }
        return soma;
    }

    public float obterMediaIdade() {
        return this.obterSomaIdade() / this.numPessoa;
    }

    public int obterPessoaPorFaixaIdade2035() {
        int resposta = 0;

        for (int x = 0; x < this.numPessoa; x++) {
            if (this.listaPessoa[x].getIdade() >= 20 && this.listaPessoa[x].getIdade() <= 35) {
                resposta++;
            }
        }

        return resposta;
    }

    public int obterPessoaPorFaixaIdade1835_F_Verde_Louro() {
        int resposta = 0;

        for (int x = 0; x < this.numPessoa; x++) {
            if (this.listaPessoa[x].getSexo() == Sexo.FEMININO) {
                if (this.listaPessoa[x].getIdade() >= 18 && this.listaPessoa[x].getIdade() <= 35) {
                    if (this.listaPessoa[x].getCorOlhos() == CorOlho.VERDE && this.listaPessoa[x].getCorCabelo() == CorCabelo.LOIRO) {
                        resposta++;
                    }
                }
            }
        }

        return resposta;
    }

}
