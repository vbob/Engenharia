package Simpsons;

public class Consumer implements Runnable {
	CookieJar jar;
	String name;
	
	public Consumer(CookieJar jar, String name) {
		this.jar = jar;
		this.name = name;
	}
	
	public void eat() {
		jar.getCookie(this.name);
	}
	
	public void run() {
		int counter = 0;
		while(true) {
			if (counter < 10) {
				eat();
				counter++;
			}
			else {
				counter = 0;
				Thread.yield();
			}
			
		}
	}
}
