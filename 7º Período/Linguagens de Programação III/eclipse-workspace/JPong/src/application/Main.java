package application;
	
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Path;
import javafx.scene.shape.Rectangle;


public class Main extends Application {
	Rectangle leftPad;
	Rectangle ball;
	BorderPane root;
	Scene scene;
	
	@Override
	public void start(Stage primaryStage) {
		try {
			root = new BorderPane();
			scene = new Scene(root,400,400);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			
			leftPad = new Rectangle(10,10,10,50);
			leftPad.setFill(Color.GREY);
			
			ball = new Rectangle (50,50,20,20);
			ball.setFill(Color.BLACK);
			
			Path path = new Path();
			
			scene.setOnKeyPressed(e-> {
				kbd_onKeyPress(e);
			});			
			
			root.getChildren().addAll(leftPad, ball);
			
			primaryStage.setScene(scene);
			primaryStage.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		launch(args);
	}
	
	public void kbd_onKeyPress(KeyEvent e) {
		if (e.getCode() == KeyCode.DOWN) {
			if (leftPad.getBoundsInParent().intersects(root.getBoundsInParent()))
				leftPad.setTranslateY(leftPad.getTranslateY()+5);
		}
		
		else if (e.getCode() == KeyCode.UP) {
			if (leftPad.getBoundsInParent().intersects(root.getBoundsInParent()))
			leftPad.setTranslateY(leftPad.getTranslateY()-5);
		}
	}
}
