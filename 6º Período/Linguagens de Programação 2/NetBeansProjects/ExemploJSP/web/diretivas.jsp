<%-- 
    Document   : listart
    Created on : 09/11/2017, 07:39:01
    Author     : vbobarth
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%! String dep = "Departamento de Informatica DAI"; %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%
            String mensagem = "<h3>Curso de Sistemas para Internet</h3>";
        %>
        <%= mensagem %>
        <hr>
        <%= dep %>
    </body>
</html>
