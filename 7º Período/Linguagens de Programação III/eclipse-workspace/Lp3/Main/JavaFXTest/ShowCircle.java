package JavaFXTest;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class ShowCircle extends Application {
	public void start(Stage primaryStage) {
		Pane pane = new Pane();
		
		Circle circle = new Circle();
		circle.centerXProperty().bind(pane.widthProperty().divide(2));
		circle.centerYProperty().bind(pane.heightProperty().divide(2));
		
		circle.setStyle("-fx-stroke: red; -fx-stroke-width: 10px;");
		
		circle.radiusProperty().bind(pane.heightProperty().divide(4));
		circle.setFill(Color.WHITE);
		
		pane.getChildren().add(circle);
		
		Scene scene = new Scene(pane, 200, 200);
		
		primaryStage.setTitle("Circle in a pane");
		primaryStage.setScene(scene);
		 //primaryStage.setResizable(false);
		primaryStage.show();
	}
	
	public static void main(String[] args) {
		Application.launch(args);
	}
}
