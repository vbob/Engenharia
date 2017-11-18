package negocios;

import java.sql.Connection;
import java.sql.DriverManager;

public class Conexao {
    public static String status;
    public static Connection connection;
    
    public static Connection obterConexao() {
        try {
            Class.forName("com.mysql.jdbc.Driver").newInstance();
            String url = "jdbc:mysql://127.0.0.1:3306/engenharia?user=root&password=7mbt9vur";
            connection = DriverManager.getConnection(url);
            status = "Conexão Aberta";
        } catch (Exception e) {
            status = e.getMessage();
        }
        
        return connection;
    }
}
