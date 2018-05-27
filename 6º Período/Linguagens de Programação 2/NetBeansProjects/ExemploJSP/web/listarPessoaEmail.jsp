<%-- 
    Document   : salvarUsuario
    Created on : 09/11/2017, 08:19:03
    Author     : vbobarth
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    </head>
    <body>
        <%
            out.println("Nome: " + request.getParameter("nome1")+"<br>");
            out.println("Email " + request.getParameter("email"));
        %>
    </body>
</html>
