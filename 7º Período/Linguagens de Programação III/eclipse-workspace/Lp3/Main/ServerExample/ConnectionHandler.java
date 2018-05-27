package ServerExample;

import java.io.*;
import java.net.*;

public class ConnectionHandler implements Runnable {
	private Socket connection;
	
	public ConnectionHandler(Socket conn) {
		this.connection = conn;
	}
	
	public void run() {
		try {
			BufferedReader reader = new BufferedReader(
					new InputStreamReader(
							this.connection.getInputStream()));
			
			PrintWriter writer = new PrintWriter(
					new OutputStreamWriter(
							this.connection.getOutputStream()));
			
			String clientName = reader.readLine();
			
			writer.println("Vitor says: Hello " + clientName);
			writer.flush();
			
		} catch (IOException ioe) {}
	}
}
