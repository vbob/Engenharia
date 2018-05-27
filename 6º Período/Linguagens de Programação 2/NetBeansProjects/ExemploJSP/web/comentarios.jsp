<%-- 
    Document   : comentarios
    Created on : 09/11/2017, 07:50:15
    Author     : vbobarth
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Comentários na Página</title>
    </head>
    <body>
        <h1>Lista de Produtos</h1>
        <!-- 
        Esta página gera uma lista simples de produtos
        -->
        <% // Lista simples de produtos
            for (int i = 1; i <=10; i++)
                out.println("P" + i + "<br>");
            
            /*
            for (int i=1; i<=10; i++) {
                String produtos = "P" + i + "<br>";
                out.println(produto);
            }
            */
        %>
    </body>
</html>
