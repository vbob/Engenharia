package application;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application{
	Clock clock = new Clock();
	
	@Override
	 public void start(Stage stage) throws Exception {
	  Scene scene = new Scene(clock, 200,200);
	  stage.setScene(scene);
	  stage.show();
	 }
	
	public static void main(String[] args) {
		Application.launch(args);
	}
}
