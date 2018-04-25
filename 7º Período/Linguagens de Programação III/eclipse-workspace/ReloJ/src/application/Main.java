package application;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import javafx.stage.Stage;

public class Main extends Application {
	public void start(Stage primaryStage) {
		Pane pane = new Pane();
	
		Circle outer_circle = new Circle();
		outer_circle.centerXProperty().bind(pane.widthProperty().divide(2));
		outer_circle.centerYProperty().bind(pane.heightProperty().divide(2));	
		outer_circle.setStyle("-fx-stroke: #77A2FF; -fx-stroke-width: 3px;");
		outer_circle.radiusProperty().bind(pane.heightProperty().divide(2).subtract(20));
		outer_circle.setFill(Color.WHITE);
		pane.getChildren().add(outer_circle);
		
		Circle inner_circle = new Circle();
		inner_circle.centerXProperty().bind(pane.widthProperty().divide(2));
		inner_circle.centerYProperty().bind(pane.heightProperty().divide(2));
		inner_circle.setStyle("-fx-stroke: #77A2FF; -fx-stroke-width: 3px;");
		inner_circle.setRadius(1);
		inner_circle.setFill(Color.web("#77A2FF"));
		pane.getChildren().add(inner_circle);
		
		Text tTop = new Text("12");
		tTop.xProperty().bind(pane.widthProperty().divide(2).subtract(10));
		tTop.setY(40);
		tTop.setFont(Font.font(15));
		pane.getChildren().add(tTop);		
		
		Text tBottom = new Text("6");
		tBottom.xProperty().bind(pane.widthProperty().divide(2).subtract(5));
		tBottom.yProperty().bind(pane.heightProperty().subtract(30));;
		tBottom.setFont(Font.font(15));
		pane.getChildren().add(tBottom);
		
		Text tLeft = new Text("9");
		tLeft.yProperty().bind(pane.heightProperty().divide(2).add(5));
		tLeft.setX(30);
		tLeft.setFont(Font.font(15));
		pane.getChildren().add(tLeft);	
		
		Text tRight = new Text("3");
		tRight.yProperty().bind(pane.heightProperty().divide(2).add(5));
		tRight.setX(160);
		tRight.setFont(Font.font(15));
		pane.getChildren().add(tRight);
		
		/*double mLength = clockRadius * 0.65;
	    double xMinute = centerX + mLength * 
	      Math.sin(minute * (2 * Math.PI / 60));
	    double minuteY = centerY - mLength * 
	      Math.cos(minute * (2 * Math.PI / 60));*/
		
	    Line sLine = new Line();
	    sLine.setStartX(100);
	    sLine.setStartY(100);
	    sLine.setEndX(100);
	    sLine.setEndY(30);
	    sLine.setStroke(Color.RED);
	    sLine.setStyle("-fx-stroke: #FF5476; -fx-stroke-width: 2px;");
	    pane.getChildren().add(sLine);
		
	    Line mLine = new Line();
	    mLine.setStartX(100);
	    mLine.setStartY(100);
	    mLine.setEndX(165);
	    mLine.setEndY(100);
	    mLine.setStroke(Color.BLACK);
	    mLine.setStyle("-fx-stroke: #7A7A7A; -fx-stroke-width: 2px;");
	    pane.getChildren().add(mLine);
	    
	    Line hLine = new Line();
	    hLine.setStartX(100);
	    hLine.setStartY(100);
	    hLine.setEndX(100);
	    hLine.setEndY(145);
	    hLine.setStroke(Color.BLACK);
	    hLine.setStyle("-fx-stroke: #262626; -fx-stroke-width: 2px;");
	    pane.getChildren().add(hLine);
	    
		Scene scene = new Scene(pane, 200, 200);
		
		primaryStage.setTitle("vBob Reloj");
		primaryStage.setScene(scene);
		primaryStage.setResizable(false);
		primaryStage.show();
	}
	
	public static void main(String[] args) {
		Application.launch(args);
	}
}
