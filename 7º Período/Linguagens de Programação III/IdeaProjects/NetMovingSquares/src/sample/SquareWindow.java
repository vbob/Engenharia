package sample;

import javafx.animation.FadeTransition;
import javafx.application.Platform;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.util.Duration;


public class SquareWindow extends Pane implements Runnable{
    final Rectangle rect1 = new Rectangle (0, 0, 40, 40);
    final Rectangle rect2 = new Rectangle (100, 100, 40, 40);

    FadeTransition ft;

    public SquareWindow() {
        Thread t = new Thread(this);
        t.setDaemon(true);
        t.start();

        ft = new FadeTransition(Duration.millis(2000), rect2);
        ft.setFromValue(1.0);
        ft.setToValue(0);
        ft.setCycleCount(1);

        getChildren().add(rect1);
        getChildren().add(rect2);
    }

    public void moveSquare(String where)  {
        switch (where) {
            case "RIGHT":
                rect1.setTranslateX(rect1.getTranslateX()+5);
                break;
            case "LEFT":
                rect1.setTranslateX(rect1.getTranslateX()-5);
                break;
            case "UP":
                rect1.setTranslateY(rect1.getTranslateY()-5);
                break;
            case "DOWN":
                rect1.setTranslateY(rect1.getTranslateY()+5);
                break;
            default:
                break;
        }

        if (rect1.getBoundsInParent().intersects(rect2.getBoundsInParent())) {
            rect2.setFill(Color.RED);
            rect2.setTranslateZ(-1);
            ft.play();
        }
    }

    public void moveSquare2(String where)  {
        switch (where) {
            case "RIGHT":
                rect2.setTranslateX(rect2.getTranslateX()+5);
                break;
            case "LEFT":
                rect2.setTranslateX(rect2.getTranslateX()-5);
                break;
            case "UP":
                rect2.setTranslateY(rect2.getTranslateY()-5);
                break;
            case "DOWN":
                rect2.setTranslateY(rect2.getTranslateY()+5);
                break;
            default:
                break;
        }

        if (rect1.getBoundsInParent().intersects(rect2.getBoundsInParent())) {
            rect2.setFill(Color.RED);
            rect2.setTranslateZ(-1);
            ft.play();
        }
    }

    @Override
    public void run() {
        Platform.runLater(() -> {  });
    }
}
