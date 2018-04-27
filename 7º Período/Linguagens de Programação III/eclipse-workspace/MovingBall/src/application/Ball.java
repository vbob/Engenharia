package application;

import javafx.application.Platform;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

public class Ball extends Pane implements Runnable {
	Circle circle = new Circle();
	int posX = -50;
	
	public Ball() {
		paint();
		Thread t = new Thread(this);
		t.setDaemon(true);
		t.start();
	}
	
	public void paint() {
		circle.setFill(Color.web("#70A6CC"));	
		circle.setRadius(50);
		posX += 5;
		circle.setCenterX(posX);
		circle.setCenterY(50);
		
		if (circle.getCenterX() > getWidth()+50)
			posX = -50;
		
		getChildren().clear();
		getChildren().add(circle);
	}
	
	@Override
	public void run() {
		while (true) {
			try {
				Thread.sleep(16);
			} catch (Exception e) {
				e.printStackTrace();
			}
			
			Platform.runLater(new Runnable() {
				@Override 
				public void run() {
					paint();
				}
			});
			
		}
		
	}
}
