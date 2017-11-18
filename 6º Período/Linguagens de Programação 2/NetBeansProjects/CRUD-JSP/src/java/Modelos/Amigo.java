package Modelos;

import Controles.Conexao;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

public class Amigo {

    private String id;
    private String nome;
    private String telefone;
    private String sexo;
    private String email;
    private String status;

    public Amigo(String id) {
        this.id = id;
    }

    public Amigo(String id, String nome, String telefone, String sexo, String email) {
        if (!id.isEmpty()) {
            this.id = id;
        }

        if (!nome.isEmpty()) {
            this.nome = nome;
        }

        if (!telefone.isEmpty()) {
            this.telefone = telefone;
        }

        if (!email.isEmpty()) {
            this.email = email;
        }

        if (!sexo.isEmpty()) {
            this.sexo = sexo;
        }
    }

    public Amigo(String nome, String telefone, String sexo, String email) {
        this.nome = nome;
        this.telefone = telefone;
        this.email = email;
        this.sexo = sexo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public String getSexo() {
        return sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getStatus() {
        return status;
    }

    public String getId() {
        return id;
    }

    public void Adicionar() {
        String query = "INSERT INTO amigo (nome, telefone, email, sexo)"
                + "VALUES (?, ?, ?, ?);";
        try {
            PreparedStatement statement = Conexao.obterConexao().prepareStatement(query);

            statement.setString(1, this.nome);
            statement.setString(2, this.telefone);
            statement.setString(3, this.email);
            statement.setString(4, this.sexo.toString());

            statement.execute();

            this.status = "Amigo Adicionado com Sucesso";
        } catch (Exception e) {
            this.status = "Erro ao Adicionar Amigo: " + e;
        }
    }

    public void Remover() {
        if (this.id != null) {
            String query = "DELETE FROM amigo "
                    + "WHERE id_amigo =  " + this.id + ";";

            try {
                Statement statement = Conexao.obterConexao().createStatement();

                statement.executeUpdate(query);

                this.status = "Amigo Removido com Sucesso";
            } catch (Exception e) {
                this.status = "Erro ao Remover Amigo: " + e;
            }
        } else {
            this.status = "É necessário definir um ID";
        }
    }

    public void Editar() {
        String query = "UPDATE amigo SET ";

        if (this.telefone != null) {
            query += "telefone = '" + this.telefone + "' ";
            if (!this.email.isEmpty() && !this.nome.isEmpty() && this.sexo != null) {
                query += ", ";
            }
        }

        if (this.email != null) {
            query += "email = '" + this.email + "' ";
            if (!this.nome.isEmpty() && this.sexo != null) {
                query += ", ";
            }
        }

        if (this.nome != null) {
            query += "nome = '" + this.nome + "' ";
            if (this.sexo != null) {
                query += ", ";
            }
        }

        if (this.sexo != null) {
            query += "sexo = '" + this.sexo + "' ";
        }

        query += "WHERE id_amigo = " + this.id;

        query += ";";

        try {
            Statement statement = Conexao.obterConexao().createStatement();

            statement.executeUpdate(query);

            this.status = "Amigo Editado com Sucesso";
        } catch (Exception e) {
            this.status = "Erro ao Editar Amigo: " + e;
        }
    }

    public ArrayList<Amigo> Pesquisar() {
        String query = "SELECT * FROM amigo ";

        ArrayList<Amigo> listaAmigos = new ArrayList<Amigo>();

        if (this.id != null || this.telefone != null || this.email != null || this.nome != null || this.sexo != null) {
            query += "WHERE ";
        }

        if (this.id != null) {
            query += "id_amigo = " + this.id + " ";
            if (this.telefone != null && this.email != null && this.nome != null && this.sexo != null) {
                query += "AND ";
            }
        }

        if (this.telefone != null) {
            query += "telefone = '" + this.telefone + "' ";
            if (this.email != null && this.nome != null && this.sexo != null) {
                query += "AND ";
            }
        }

        if (this.email != null) {
            query += "email = '" + this.email + "' ";
            if (this.nome != null && this.sexo != null) {
                query += "AND ";
            }
        }

        if (this.nome != null) {
            query += "nome = '" + this.nome + "' ";
            if (this.sexo != null) {
                query += "AND ";
            }
        }

        if (this.sexo != null) {
            query += "sexo = '" + this.sexo + "' ";
        }

        query += ";";

        try {
            Statement statement = Conexao.obterConexao().createStatement();
            ResultSet results = statement.executeQuery(query);

            while (results.next()) {
                Amigo amigoTemp = new Amigo(results.getString("id_amigo"),
                        results.getString("nome"),
                        results.getString("telefone"),
                        results.getString("sexo"),
                        results.getString("email"));

                listaAmigos.add(amigoTemp);
            }

            this.status = "Amigos Pesquisados com Sucesso";
        } catch (Exception e) {
            this.status = "Erro ao Procurar Amigos: " + e;
        }

        return listaAmigos;
    }
}
