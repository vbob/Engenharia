package conceito;

public class Pessoa {

    private Sexo sexo;
    private CorOlho corOlhos;
    private CorCabelo corCabelo;
    private int idade;

    public Pessoa() {
        this.sexo = Sexo.MASCULINO;
        this.corCabelo = CorCabelo.CASTANHO;
        this.corOlhos = CorOlho.CASTANHO;
    }

    public Pessoa(Sexo sexo, CorCabelo corCabelo, CorOlho corOlho, int idade) {
        this.setSexo(sexo);
        this.setCorOlhos(corOlho);
        this.setCorCabelo(corCabelo);
        this.setIdade(idade);
    }

    public Sexo getSexo() {
        return sexo;
    }

    public void setSexo(Sexo sexo) {
        this.sexo = sexo;
    }

    public CorOlho getCorOlhos() {
        return corOlhos;
    }

    public void setCorOlhos(CorOlho corOlhos) {
        this.corOlhos = corOlhos;
    }

    public CorCabelo getCorCabelo() {
        return corCabelo;
    }

    public void setCorCabelo(CorCabelo corCabelo) {
        this.corCabelo = corCabelo;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

}
