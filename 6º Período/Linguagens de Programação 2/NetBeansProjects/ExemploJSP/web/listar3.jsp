<%-- 
    Document   : listar3
    Created on : 09/11/2017, 07:55:56
    Author     : vbobarth
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Aula de JSP</title>
    </head>
    <body>
        <%@include file="index.html"%>
        <hr>
        <% String message = "<h3>Curso Internet - DAI</h3>";
           out.println(message);
        %>
    </body>
</html>
