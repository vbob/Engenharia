<%-- 
    Document   : decisao1
    Created on : 09/11/2017, 08:08:40
    Author     : vbobarth
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.Date"%>
<!DOCTYPE html>
<html>  
    <body>
        <% 
            String msg = "";
            Date agora = new Date();
            int hora = agora.getHours();
            if ((hora >= 5) && (hora < 12))
                msg = "Bom Dia";
            else if ((hora >= 12) && (hora < 18))
                msg = "Boa Tarde";
            else if ((hora>=18) && (hora < 24))
                msg = "Boa Noite";
            else
                msg = "Boa Madrugada";
            out.println(msg);
        %>
    </body>
</html>
