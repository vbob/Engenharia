<%-- 
    Document   : verificarLogin
    Created on : 16/11/2017, 08:18:17
    Author     : vbobarth
--%>

<%@page import="negocios.Usuario"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <% 
            Usuario usuario = new Usuario();
            String login = request.getParameter("login");
            String senha = request.getParameter("senha");
            int idUsuario = usuario.verificarUsuario(login, senha);
            if (idUsuario > 0) {
                out.println("Login Correto. IdUsuario = " + idUsuario);
            } else {
                out.println("Usuário não Encontrado");
            }
        
        %>
    </body>
</html>
