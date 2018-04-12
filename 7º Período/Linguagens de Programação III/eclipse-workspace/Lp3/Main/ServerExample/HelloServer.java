package ServerExample;

import java.io.*;
import java.net.*;

public class HelloServer {
	public static void main(String[] args) {
		int port = 7777;
		ServerSocket server;
		try {
			server = new ServerSocket(port);
		} catch (IOException ioe) {
			System.out.println("Couldnt run server on port " + port);
			return;
		}
		
		while(true) {
			try {
				Socket connection = server.accept();
				ConnectionHandler handler = new ConnectionHandler(connection);
				new Thread(handler).start();
			} catch (IOException ioe1) { }
		}	
	}
	
}
