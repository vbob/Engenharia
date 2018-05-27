
public class PrintThread1 extends Thread {
	
	String name;
	public PrintThread1(String name) {
		this.name = name;
	}
	
	public static synchronized void print(String nome) {
		for (int i = 1; i < 10; i++) {
			try {
				sleep((long) (Math.random() * 100));
			} catch (InterruptedException ie) { }
			System.out.print(nome);
		}
	}
	
	public void run() {
		print(this.name);
	}

}
