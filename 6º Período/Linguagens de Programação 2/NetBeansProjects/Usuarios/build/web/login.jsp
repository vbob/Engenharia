<%-- 
    Document   : login
    Created on : 27/11/2017, 21:02:33
    Author     : vbob
--%>

<%@page import="Conceitos.Usuarios"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Login</title>
    </head>
    <body>
        <form method="post" action="verificalogin.jsp">
            <table border="0" align="center">
                <tr>
                    <td align="right">Login:</td>
                    <%
                        if(session.getAttribute("idusuario") != null) {
                            String email = Usuarios.getEmail(Integer.parseInt(session.getAttribute("idusuario").toString()));
                            out.println("<td align='left'><input type='text' name='login' value='"+email+"'></td>");
                        }
                        else {
                              out.println("<td align='left'><input type='text' name='login'></td>");
                        }
                    %>
                    
                </tr>
                <tr>
                    <td align="right">Senha</td>
                    <td align="left"><input type="password" name="senha"></td>
                </tr>
                <tr>
                    <td colspan="2" align="center"><input type="submit" value="Entrar"></td>
                </tr>
            </table>
        </form>
    </body>
</html>
