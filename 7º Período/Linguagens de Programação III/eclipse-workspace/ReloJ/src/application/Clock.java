package application;

import java.time.LocalDateTime;
import java.util.Date;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Clock extends Pane implements Runnable {
	public Clock() {
		paint();
		Thread t = new Thread(this);
		t.setDaemon(true);
		t.start();
	}
	
	public void paint() {
		getChildren().clear();
		
		Circle outer_circle = new Circle();
		outer_circle.centerXProperty().bind(widthProperty().divide(2));
		outer_circle.centerYProperty().bind(heightProperty().divide(2));	
		outer_circle.setStyle("-fx-stroke: #77A2FF; -fx-stroke-width: 3px;");
		outer_circle.radiusProperty().bind(heightProperty().divide(2).subtract(20));
		outer_circle.setFill(Color.WHITE);
		getChildren().add(outer_circle);
		
		Circle inner_circle = new Circle();
		inner_circle.centerXProperty().bind(widthProperty().divide(2));
		inner_circle.centerYProperty().bind(heightProperty().divide(2));
		inner_circle.setStyle("-fx-stroke: #77A2FF; -fx-stroke-width: 3px;");
		inner_circle.setRadius(1);
		inner_circle.setFill(Color.web("#77A2FF"));
		getChildren().add(inner_circle);
		
		Text tTop = new Text("12");
		tTop.xProperty().bind(widthProperty().divide(2).subtract(10));
		tTop.setY(40);
		tTop.setFont(Font.font(15));
		getChildren().add(tTop);		
		
		Text tBottom = new Text("6");
		tBottom.xProperty().bind(widthProperty().divide(2).subtract(5));
		tBottom.yProperty().bind(heightProperty().subtract(30));;
		tBottom.setFont(Font.font(15));
		getChildren().add(tBottom);
		
		Text tLeft = new Text("9");
		tLeft.yProperty().bind(heightProperty().divide(2).add(5));
		tLeft.setX(30);
		tLeft.setFont(Font.font(15));
		getChildren().add(tLeft);	
		
		Text tRight = new Text("3");
		tRight.yProperty().bind(heightProperty().divide(2).add(5));
		tRight.setX(160);
		tRight.setFont(Font.font(15));
		getChildren().add(tRight);
		
		/*double mLength = clockRadius * 0.65;
	    double xMinute = centerX + mLength * 
	      Math.sin(minute * (2 * Math.PI / 60));
	    double minuteY = centerY - mLength * 
	      Math.cos(minute * (2 * Math.PI / 60));*/
		
		double horas = LocalDateTime.now().getHour();
		double minutos = LocalDateTime.now().getMinute();
		double segundos = LocalDateTime.now().getSecond();
		
		//double horas = 0;
		//double minutos = 0;
		//double segundos = 0;
		
		var anguloHora = Math.toRadians((360*horas/12));
		var anguloMinuto = Math.toRadians((360*minutos/60));
		var anguloSegundo = Math.toRadians((360*segundos/60));
		System.out.println(horas);
		System.out.println(minutos);
		System.out.println(segundos);
	    Line sLine = new Line();
	    
	    sLine.setStartX(100);
	    sLine.setStartY(100);
	    sLine.setEndX(100+(60*Math.sin(anguloSegundo)));
	    sLine.setEndY(100-(60*Math.cos(anguloSegundo)));
	    sLine.setStroke(Color.RED);
	    sLine.setStyle("-fx-stroke: #FF5476; -fx-stroke-width: 2px;");
	    getChildren().add(sLine);
		
	    Line mLine = new Line();
	    mLine.setStartX(100);
	    mLine.setStartY(100);
	    mLine.setEndX(100+(55*Math.sin(anguloMinuto)));
	    mLine.setEndY(100-(55*Math.cos(anguloMinuto)));
	    mLine.setStroke(Color.BLACK);
	    mLine.setStyle("-fx-stroke: #7A7A7A; -fx-stroke-width: 2px;");
	    getChildren().add(mLine);
	    
	    Line hLine = new Line();
	    hLine.setStartX(100);
	    hLine.setStartY(100);
	    hLine.setEndX(100+(40*Math.sin(anguloHora)));
	    hLine.setEndY(100-(40*Math.cos(anguloHora)));
	    hLine.setStroke(Color.BLACK);
	    hLine.setStyle("-fx-stroke: #262626; -fx-stroke-width: 2px;");
	    getChildren().add(hLine);
	}

	@Override
	public void run() {
		while(true) {
			try {
				Thread.sleep(1000);
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
