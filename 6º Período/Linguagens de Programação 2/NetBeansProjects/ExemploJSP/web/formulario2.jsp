<%-- 
    Document   : formulario1
    Created on : 09/11/2017, 08:16:45
    Author     : vbobarth
--%>

<%@page contentType="text/html" pageEncoding="iso-8859-1"%>
<!DOCTYPE html>
<html>
    <body>
        <table border="0" align="center">
            <tr>
                <td>
                    <%
                        String nome = "";
                        nome = request.getParameter("nome");
                    %>
                    <form action="listarPessoaEmail.jsp" method="POST">
                        Email:<br><input type="text" name="email" value="" /><br>
                        <input type="hidden" name="nome1" value = "<%= nome %>"/>
                        <br><input type="submit" name="listar" value="Listar" /><br>
                    </form>
                </td>
            </tr>
        </table>
    </body>
</html>
