<%-- 
    Document   : incluirUsuario
    Created on : 09/11/2017, 08:16:45
    Author     : vbobarth
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <body>
        <table border="0" align="center">
            <tr>
                <td>
                    <form action="salvarUsuario.jsp" method="POST">
                        Nome:<br><input type="text" name="nome" value="" /><br>
                        Login:<br><input type="text" name="login" value="" /><br>
                        Senha:<br><input type="password" name="senha" value="" /><br>
                        <br><input type="submit" name="inclur" value="Incluir" /><br>
                    </form>
                </td>
            </tr>
        </table>
    </body>
</html>
