package sample;

import javafx.application.Application;
import javafx.scene.input.KeyCode;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.stage.Stage;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.ArrayList;


public class ClientMain extends Application {
    SquareWindow squareWindow = new SquareWindow();

    static ArrayList<String> movesToSend = new ArrayList<String>();

    @Override
    public void start(Stage stage) throws Exception {
        stage.setTitle("CLIENTE");

        Scene scene = new Scene(squareWindow, 500, 375);

        scene.setOnKeyPressed(evt -> {
            scene_onKeyPressed(evt);
        });

        stage.setScene(scene);
        stage.show();
    }

    private void scene_onKeyPressed(KeyEvent evt) {
        if (evt.getCode() == KeyCode.RIGHT) {
            squareWindow.moveSquare2("RIGHT");
            movesToSend.add("RIGHT");
        }
        else if (evt.getCode() == KeyCode.LEFT) {
            squareWindow.moveSquare2("LEFT");
            movesToSend.add("LEFT");
        }
        else if (evt.getCode() == KeyCode.UP)   {
            squareWindow.moveSquare2("UP");
            movesToSend.add("UP");
        }
        else if (evt.getCode() == KeyCode.DOWN)  {
            squareWindow.moveSquare2("DOWN");
            movesToSend.add("DOWN");
        }

    }

    public static void main(String[] args) {
        new Thread(() -> {
            Application.launch(args);
        }).start();

        try {
            Socket s = new Socket("localhost", 9000);
            System.out.println("Client Started");

            while (true) {
                InputStream i = s.getInputStream();
                OutputStream o = s.getOutputStream();
                if (movesToSend.size() > 0) {
                    String str = movesToSend.remove(0);
                    byte[] line = str.getBytes();
                    o.write(line);
                    i.read(line);
                    str = new String(line);
                    System.out.println(str.trim());
                }
            }


        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
