<%-- 
    Document   : listarusuarios
    Created on : 27/11/2017, 21:23:03
    Author     : vbob
--%>

<%@page import="java.util.ArrayList"%>
<%@page import="Conceitos.Usuarios"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%
          ArrayList<Usuarios> usuarios = Usuarios.getAllUsers();
          if (usuarios.size() > 0) {
              out.println("<table border='1px'>");
              out.println("<tr>");
              out.println("<th>");
              out.println("Id");
              out.println("</th>");
              out.println("<th>");
              out.println("Nome");
              out.println("</th>");
              out.println("<th>");
              out.println("Login");
              out.println("</th>");
              for(Usuarios usuario : usuarios) {
                out.println("<tr>");
                out.println("<td>");
                out.println(usuario.getId());
                out.println("</td>");   
                out.println("<td>");
                out.println(usuario.getNome_usuario());
                out.println("</td>");   
                out.println("<td>");
                out.println(usuario.getLogin_usuario());
                out.println("</td>");   
                out.println("</tr>");   
              }
              out.println("</table>");
          } else {
              out.println("Nenhum usuário adicionado");
          }
        %>
    </body>
</html>
