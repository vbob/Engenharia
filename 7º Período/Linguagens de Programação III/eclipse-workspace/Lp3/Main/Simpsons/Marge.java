package Simpsons;

public class Marge implements Runnable {
	CookieJar jar;
	
	public Marge(CookieJar jar) {
		this.jar = jar;
	}
	
	public void bake(int cookieNumber) {
		jar.putCookie("Marge", cookieNumber);
	}
	
	public void run() {
		for (int i = 1; i <= 50; i++) bake(i);
	}
}
