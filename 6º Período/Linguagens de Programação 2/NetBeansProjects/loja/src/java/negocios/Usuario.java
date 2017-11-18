package negocios;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;

public class Usuario {
    
    public int verificarUsuario(String login, String senha) {
        int idUsuario = 0;
        
        String query =  "select idusuario from usuarios where login='"+login+"' and senha='"+senha+"';";
        Connection connection = Conexao.obterConexao();     
        
        try {
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(query);
            if (resultSet.next()) {
                idUsuario = resultSet.getInt("idusuario");
            }
        } catch (Exception e) {
            System.out.println(e);
        }
        
        return idUsuario;
    }
}
