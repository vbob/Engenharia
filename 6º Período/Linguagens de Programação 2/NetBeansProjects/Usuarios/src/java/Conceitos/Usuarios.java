package Conceitos;

import Controles.Conexao;
import java.sql.*;
import java.util.ArrayList;

public class Usuarios {
    private int id;
    private String nome_usuario;
    private String login_usuario;
       
    public Usuarios(int id, String nome_usuario, String login_usuario) {
        this.id = id;
        this.nome_usuario = nome_usuario;
        this.login_usuario = login_usuario;
    }
    
    public Usuarios() {
        
    }
    
    
    public int verificarUsuario(String login, String senha) {
        int idusuario = 0;
        String q = "";
        q+= "SELECT idusuario FROM usuarios ";
        q+= "WHERE login='" + login + "'and senha='"+senha+"'";
        Connection con = Conexao.obterConexao();
        try {
            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery(q);
            if (rs.next()) {
                idusuario = rs.getInt("idusuario");
            }
        } catch (Exception e) {
        }
        return idusuario;
    }
    
    public static String getEmail(int idusuario) {
        String email = "";
        String q = "";
        q+= "SELECT login FROM usuarios ";
        q+= "WHERE idusuario=" + idusuario;
        Connection con = Conexao.obterConexao();
        try {
            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery(q);
            if (rs.next()) {
                email = rs.getString("login");
            }
        } catch (Exception e) {
        }
        return email;
    }

    public static String getNome(int idusuario) {
        String nome = "";
        String q = "";
        q+= "SELECT nome FROM usuarios ";
        q+= "WHERE idusuario=" + idusuario;
        Connection con = Conexao.obterConexao();
        try {
            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery(q);
            if (rs.next()) {
                nome = rs.getString("nome");
            }
        } catch (Exception e) {
        }
        return nome;
    }
    
    public static void addUsuario(String nome, String email, String senha) {
        String q = "INSERT INTO usuarios (nome, login, senha)";
        q+= "VALUES ('" + nome +"','"+email +"','" + senha + "')";
        Connection con = Conexao.obterConexao();
        try {
            Statement st = con.createStatement();
            st.executeUpdate(q);

        } catch (Exception e) {
        }
    }
    
    public static ArrayList<Usuarios> getAllUsers() {
        String q = "SELECT * FROM usuarios;";
        Connection con = Conexao.obterConexao();
        ArrayList<Usuarios> usuarios = new ArrayList<>();
        try {
            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery(q);
            
            while (rs.next()) {
                usuarios.add(new Usuarios(rs.getInt("idusuario"), rs.getString("nome"), rs.getString("login")));
            }
        } catch (SQLException e) {
        }
        return usuarios;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome_usuario() {
        return nome_usuario;
    }

    public void setNome_usuario(String nome_usuario) {
        this.nome_usuario = nome_usuario;
    }

    public String getLogin_usuario() {
        return login_usuario;
    }

    public void setLogin_usuario(String login_usuario) {
        this.login_usuario = login_usuario;
    }
    
}
