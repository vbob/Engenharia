package JavaFXTest;

import javafx.application.Application;
import javafx.scene.control.Button;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class MyJavaFX extends Application {
	@Override
	public void start(Stage primaryStage) {
		Button btOK = new Button("OK");
		Scene scene = new Scene(btOK, 200, 250);
		primaryStage.setTitle("MyJavaFX");
		primaryStage.setScene(scene);
		primaryStage.show();
		
		Stage stage = new Stage();
		stage.setTitle("Second Stage");
		stage.setScene(new Scene(new Button("New Stage")));
		stage.show();
	}
	
	public static void main(String[] args) {
        Application.launch(args);
    }
}
