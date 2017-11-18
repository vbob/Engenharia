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
            int mesAtual = (agora.getMonth()+1);
            String mes;
            switch(mesAtual) {
                case 1: mes="Janeiro"; break;
                case 2: mes="Fevereiro"; break;
                case 3: mes="Março"; break;
                case 4: mes="Abril"; break;
                case 5: mes="Maio"; break;
                case 6: mes="Junho"; break;
                case 7: mes="Julho"; break;
                case 8: mes="Agosto"; break;
                case 9: mes="Setembro"; break;
                case 10: mes="Outubro"; break;
                case 11: mes="Novembro"; break;
                default: mes="Dezembro"; break;
            }
            out.println("Mês Autal: " + mes);
        %>
    </body>
</html>
