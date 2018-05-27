<%-- 
    Document   : verificalogin
    Created on : 27/11/2017, 20:45:56
    Author     : vbob
--%>

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
            Usuarios c = new Usuarios();
            String login = request.getParameter("login");
            String senha = request.getParameter("senha");
            int idusuario = c.verificarUsuario(login, senha);
            if (idusuario > 0) {
                out.println("Login correto. idusuario: " + idusuario);
                Cookie cl = new Cookie("login", login);
                cl.setMaxAge(50*60);
                response.addCookie(cl);
                session.setAttribute("idusuario", Integer.toString(idusuario));
                response.sendRedirect("admin.jsp");
            } else {
                out.println("Login incorreto");
            }
        %>
    </body>
</html>
