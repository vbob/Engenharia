
package Controles;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Conexao {
    public static String status = "";
    public static Connection obterConexao(){
        Connection con = null;
        try{
            Class.forName("com.mysql.jdbc.Driver").newInstance();
            String url = "jdbc:mysql://localhost:3306/engenharia?user=root&password=7mbt9vur";
            con = DriverManager.getConnection(url);
            status = "Conexão Aberta com Sucesso";
            }catch (SQLException e){
                status = e.getLocalizedMessage();
            }catch (ClassNotFoundException e){
                status = e.getMessage();
            }catch (Exception e){
                status = e.getMessage();
            }
        return con;
    }
}
