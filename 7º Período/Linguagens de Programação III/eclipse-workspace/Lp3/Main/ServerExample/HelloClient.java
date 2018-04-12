package ServerExample;

import java.io.*;
import java.net.Socket;

public class HelloClient {
	public static void main(String[] args) {
		String hostname = "192.168.43.162";
		int port = 7777;
		
		Socket connection = null;
		
		try {
			connection = new Socket(hostname, port);
		} catch(IOException ioe) {
			System.out.println("Connection Failed");
			return;
		}
		
		try {
			BufferedReader reader = new BufferedReader( 
				new InputStreamReader(
						connection.getInputStream()));
			
			PrintWriter writer = new PrintWriter(
				new OutputStreamWriter(
				connection.getOutputStream()));
			
			writer.println("Vitor");
			writer.flush();
			
			String reply = reader.readLine();
			System.out.println("Server Reply: " + reply);
			
		} catch (IOException ioel) {
			
		}
	}
}
