/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import Modelos.Amigo;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author vbobarth
 */
public class listar extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet listar</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet listar at " + request.getContextPath() + "</h1>");
            out.println("</body>");
            out.println("</html>");
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        doPost(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
                String id = request.getParameter("id");
                String nome = request.getParameter("nome");
		String email = request.getParameter("email");
                String telefone = request.getParameter("telefone");
		String sexo = request.getParameter("sexo");
                if (sexo == null)
                        sexo = "";
                
                
                Amigo amigo = new Amigo(id, nome, telefone, sexo, email);
                ArrayList<Amigo> amigos = amigo.Pesquisar();
                
                PrintWriter out = response.getWriter();
		
                
                for (Amigo amigoTemp: amigos) {
                    out.println("<tr>");
                    out.println("<td>");
                    out.println(amigoTemp.getId());
                    out.println("</td>");
                    out.println("<td>");
                    out.println(amigoTemp.getNome());
                    out.println("</td>");
                    out.println("<td>");
                    out.println(amigoTemp.getTelefone());
                    out.println("</td>");
                    out.println("<td>");
                    out.println(amigoTemp.getEmail());
                    out.println("</td>");
                    out.println("<td>");
                    out.println(amigoTemp.getSexo());
                    out.println("</td>");
                    out.println("</tr>");
                }
                
		response.setContentType("text/html");
                                
		out.close();
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
