package TimerExample;

import java.util.*;

public class TimerExample extends TimerTask {
	public void run() {
		System.out.println("Olá Mundo");
	}
	
	public static void main(String[] args) {
		Timer timer = new Timer();
		long dia = 1000;
		timer.scheduleAtFixedRate(new TimerExample(), new Date(), dia);
	}
}
