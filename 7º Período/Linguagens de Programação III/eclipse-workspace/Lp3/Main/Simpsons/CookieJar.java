package Simpsons;

import java.util.ArrayList;

public class CookieJar {
	int MAX_COOKIES = 30;
	private ArrayList<Integer> contents = new ArrayList<Integer>();
	
	public synchronized void getCookie(String who) {
		while(contents.size() == 10) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
		notifyAll();
		System.out.println(who + " ate cookie " + contents.get(0));
		contents.remove(contents.get(0));
		System.out.println("JAR: " + this.contents);
	}
	
	public synchronized void putCookie(String who, int value) {
		while(contents.size() >= MAX_COOKIES) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
		contents.add(value);
		System.out.println(who + " put cookie " + value + " in the jar");
		System.out.println("JAR: " + this.contents);
		notifyAll();
	}
}
