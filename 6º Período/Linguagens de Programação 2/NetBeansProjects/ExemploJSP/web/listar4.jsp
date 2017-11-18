<%-- 
    Document   : listar4
    Created on : 09/11/2017, 07:58:19
    Author     : vbobarth
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Aula JSP</title>
    </head>
    <body>
        <% 
            String message = "<h3>Sistema Internet - DAI</h3>";
            out.println(message);
        %>
        <% 
            String tab = "";
            tab += "<table border=1>";
            tab += "<tr bgcolor=whitesmoke>";
            tab += "<th>Código</th>";
            tab += "<th>Produto</th>";
            tab += "</tr>";
            
            for (int i = 1; i <=10; i++) {
                tab += "<tr bgcolor=white>";
                tab += "<td align=right>"+i+"</td>";
                tab += "<td> P"+i+"</td>";
                tab += "</tr>";
            }
            
            tab += "</table>";
            out.println(tab);
        %>
    </body>
</html>
