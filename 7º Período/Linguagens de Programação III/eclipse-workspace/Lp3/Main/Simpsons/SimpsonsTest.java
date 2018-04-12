package Simpsons;

public class SimpsonsTest {
	public static void main(String[] args) {
		CookieJar jar = new CookieJar();
		
		Consumer homer = new Homer(jar);
		Consumer bart = new Bart(jar);
		Marge marge = new Marge(jar);
		
		new Thread(homer).start();
		new Thread(bart).start();
		new Thread(marge).start();
	}
}
