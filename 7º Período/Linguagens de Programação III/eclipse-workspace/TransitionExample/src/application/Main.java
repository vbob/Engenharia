package application;

import javafx.animation.PathTransition;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.HLineTo;
import javafx.scene.shape.MoveTo;
import javafx.scene.shape.Path;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.VLineTo;
import javafx.stage.Stage;
import javafx.util.Duration;

public class Main extends Application {

 public static void main(String[] args) {
  launch(args);
 }

 @Override
 public void start(Stage stage) throws Exception {
                stage.setTitle("Transition Sample");
                Group root = new Group();
                Scene scene = new Scene(root, 500, 375);  

  final Rectangle rectPath = new Rectangle (0, 0, 40, 40);
  rectPath.setArcHeight(10); 
  rectPath.setArcWidth(10); 
  rectPath.setFill(Color.ORANGE); 

  Path path = new Path(); 
  path.getElements().add(new MoveTo(20,20)); 
  path.getElements().add(new HLineTo(400));
  path.getElements().add(new VLineTo(100));
  path.getElements().add(new HLineTo(20));
  path.getElements().add(new VLineTo(20));

  PathTransition pathTransition = new PathTransition(); 
  pathTransition.setDuration(Duration.millis(5000));
  pathTransition.setPath(path); 
  pathTransition.setNode(rectPath);
  pathTransition.setCycleCount(Timeline.INDEFINITE);
  pathTransition.setAutoReverse(true);


        root.getChildren().add(rectPath);

        stage.setScene(scene);
        stage.show();

        pathTransition.play();

 }
}