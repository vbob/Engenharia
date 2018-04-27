package application;

import java.awt.Dimension;
import java.awt.Toolkit;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

import javafx.animation.Interpolator;
import javafx.animation.RotateTransition;
import javafx.animation.ScaleTransition;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.embed.swing.SwingFXUtils;
import javafx.scene.Scene;
import javafx.scene.SnapshotParameters;
import javafx.scene.image.WritableImage;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.stage.StageStyle;
import javafx.util.Duration;

public class Main extends Application implements Runnable {

 final Rectangle rect = new Rectangle (0, 0, 40, 40);
 RotateTransition rt;
 ScaleTransition stBig;
 KeyCode direction = KeyCode.RIGHT;
 Text pause; 
 Stage stage;
 Pane pane;

 @Override
 public void start(Stage stage) throws Exception {
     this.stage = stage;

     //Remove the title bar
     stage.initStyle(StageStyle.UNDECORATED);
     //Get the current screen resolution
     Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
     pane = new Pane();

     rt = new RotateTransition(Duration.millis(3000), rect);
     rt.setByAngle(360);
     rt.setInterpolator(Interpolator.LINEAR);
     rt.setCycleCount(Timeline.INDEFINITE);
     rt.setAutoReverse(false);

     pause = new Text(screenSize.getWidth()/2, screenSize.getHeight()/2, "Paused");
     pause.setFill(Color.RED);
     pause.setVisible(false);
     stBig = new ScaleTransition(Duration.millis(1000), pause);
     stBig.setFromX(0);
     stBig.setFromY(0);
     stBig.setToX(10);
     stBig.setToY(20);

     pane.getChildren().addAll(rect,pause);
     //Set the scene as the size of the entire resolution
     Scene scene = new Scene(pane,screenSize.getWidth(),screenSize.getHeight());

     scene.setOnKeyPressed(e ->{
         scene_onKeyPressed(e);
     });

     stage.setScene(scene);
     stage.show();

            Thread t = new Thread(this);
     t.setDaemon(true);
     t.start();
     rt.play();
 }

 private void scene_onKeyPressed(KeyEvent e) {
  direction = e.getCode();
  switch(direction) {
  case RIGHT:
      if (pause.isVisible()) pause.setVisible(false);
      rt.stop(); rt.setByAngle(360); rt.play();
       break;
  case LEFT:
      if (pause.isVisible()) pause.setVisible(false);
      rt.stop(); rt.setByAngle(-360); rt.play();
      break;
  case UP:
      if (pause.isVisible()) pause.setVisible(false);
      rt.stop(); rt.setByAngle(-360); rt.play();
      break;
  case DOWN:
      if (pause.isVisible()) pause.setVisible(false);
      rt.stop(); rt.setByAngle(360); rt.play();
      break;
  case ESCAPE:
      //terminates the program
      System.exit(0);
  default:
      //Any other key pressed pauses the animation
      rt.stop();
      pause.setVisible(true);
      stBig.play();    
      break;
  }  
 }

 @Override
 public void run() {
     while (true) {
        try {
      Thread.sleep(20);
  } catch (InterruptedException e) {
      e.printStackTrace();
  }
        
        

  switch(direction) {
      case RIGHT:
          if (rect.getTranslateX()>stage.getWidth()+40) rect.setTranslateX(-35);
   rect.setTranslateX(rect.getTranslateX()+5);
   break;
      case LEFT:
          if (rect.getTranslateX()<0-40) rect.setTranslateX(stage.getWidth()+40);
   rect.setTranslateX(rect.getTranslateX()-5);
   break;
      case UP:
          if (rect.getTranslateY()<0-40) rect.setTranslateY(stage.getHeight()+40);
   rect.setTranslateY(rect.getTranslateY()-5);
   break;
      case DOWN:
          if (rect.getTranslateY()>stage.getHeight()+40) rect.setTranslateY(-35);
   rect.setTranslateY(rect.getTranslateY()+5);
   break;
      case P:
          saveAsPng();
   break;
      default:
          break;
   }
  }
 }

  public void saveAsPng() {
	  Platform.runLater( new Runnable() {
      	@Override
			public void run() {
      		WritableImage image = pane.snapshot(new SnapshotParameters(), null);

      	    File file = new File("game.png");

      	    try {
      	      ImageIO.write(SwingFXUtils.fromFXImage(image, null), "png", file);
      	    } catch (IOException e) {
      	      e.printStackTrace();
      	    }
			}
		});
    
  }
  
  public static void main(String[] args) {
	Application.launch(args);
  }
}