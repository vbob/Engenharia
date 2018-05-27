public class Main {
	public static void main(String args[]) {
		Thread pt3 = new Thread(new PrintThread1("CC"));
		Thread pt1 = new Thread(new PrintThread1("AA"));
		Thread pt2 = new Thread(new PrintThread1("BB"));
		
		//pt1.setDaemon(true);
		//pt2.setDaemon(true);
		pt1.start();
		pt2.start();
		pt3.start();
	}
}
