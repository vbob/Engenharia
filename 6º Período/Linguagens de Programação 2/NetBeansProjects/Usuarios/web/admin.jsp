<%-- 
    Document   : admin
    Created on : 27/11/2017, 20:55:02
    Author     : vbob
--%>

<%@page import="Conceitos.Usuarios"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Admin JSP</title>
    </head>
    <body>
       <%
            if(session.getAttribute("idusuario") != null) {
                int idusuario = Integer.parseInt(session.getAttribute("idusuario").toString());
                out.println("idusuario: " + idusuario);
                out.println("<br>nome: " + Usuarios.getNome(idusuario));
                out.println("<br>login: " + Usuarios.getEmail(idusuario));
            } else {
                response.sendRedirect("/login.jsp");
            }
        %>
    </body>
</html>
