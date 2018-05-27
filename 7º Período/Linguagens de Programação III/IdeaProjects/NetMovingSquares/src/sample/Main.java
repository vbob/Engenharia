package sample;

import javafx.application.Application;
import javafx.scene.input.KeyCode;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.stage.Stage;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;


public class Main extends Application {
    static SquareWindow squareWindow = new SquareWindow();
    static ArrayList<String> movesToSend = new ArrayList<String>();
    static ServerSocket s;
    @Override
    public void start(Stage stage) throws Exception {
        stage.setTitle("Controlling an object movement by the keyboard");


        Scene scene = new Scene(squareWindow, 500, 375);

        scene.setOnKeyPressed(evt -> {
            scene_onKeyPressed(evt);
        });

        stage.setScene(scene);
        stage.show();
    }

    private void scene_onKeyPressed(KeyEvent evt) {
        if (evt.getCode() == KeyCode.RIGHT) {
            squareWindow.moveSquare("RIGHT");
            movesToSend.add("RIGHT");
        }
        else if (evt.getCode() == KeyCode.LEFT) {
            squareWindow.moveSquare("LEFT");
            movesToSend.add("LEFT");
        }
        else if (evt.getCode() == KeyCode.UP)   {
            squareWindow.moveSquare("UP");
            movesToSend.add("UP");
        }
        else if (evt.getCode() == KeyCode.DOWN)  {
            squareWindow.moveSquare("DOWN");
            movesToSend.add("DOWN");
        }
    }

    public static void main(String[] args) {
        new Thread(() -> {
            Application.launch(args);
        }).start();


        new Thread(() -> {
            try {
                s = new ServerSocket(9000);
                String str;

                System.out.println("Server Started");

                while (true) {
                    Socket c = s.accept();
                    InputStream i = c.getInputStream();
                    OutputStream o = c.getOutputStream();

                    do {
                        byte[] received = new byte[100];
                        i.read(received);
                        o.write(received);

                        str = new String(received);
                        System.out.println("client: " + str.trim());

                        squareWindow.moveSquare2(str.trim());
                    } while (!str.trim().equals("bye"));

                    c.close();

                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }
}
