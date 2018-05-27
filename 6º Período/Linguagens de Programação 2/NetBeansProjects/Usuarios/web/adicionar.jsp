<%-- 
    Document   : adicionar
    Created on : 27/11/2017, 21:44:12
    Author     : vbob
--%>

<%@page import="java.util.ArrayList"%>
<%@page import="Conceitos.Usuarios"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title></title>
    </head>
    <body>
        <%
            String nome = request.getParameter("nome");
            String login = request.getParameter("login");
            String senha = request.getParameter("senha");
            ArrayList<Usuarios> usuarios = Usuarios.getAllUsers();
            boolean jaExiste = false;
            for (Usuarios usuario : usuarios) {
                if (usuario.getLogin_usuario().equals(login))
                    jaExiste = true;
            }
            if (!jaExiste && !login.isEmpty()) {
                Usuarios.addUsuario(nome, login, senha);
                response.sendRedirect("listarusuarios.jsp");
            } else if (login.isEmpty()) {
                out.println("Usuário inválido");
            }
            else {
                out.println("Usuário já cadastrado");
            }
            
        %>
    </body>
</html>
