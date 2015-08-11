/*
 * Enzo Galbo
 * 4/10/2015
 * Steven Klein
 * CS 150
 * This is a program that reads 10 files consisting of 20 doubles
 * each and creates polylines for each file using these doubles.
 * It allows the user to switch between polylines using the next
 * and previous buttons and lists the current file in the title.
 */
package program3;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Polyline;
import javafx.stage.Stage;

public class Program3 extends Application {

    
    public final int NUM_OF_FILES = 10; // constant based on how many files 
                                        // are created since it is referenced
                                        // multiple times
    
    public int currentScene = 0;        // global variable that starts scene at
                                        // 0 and allows it to be incremented
                                        // and decremented

    @Override
    public void start(Stage primaryStage) {

        
        
        // creates array of polylines and populate them with coordinate
        // data from each temp.dat file using populatePolylineArray method
        Polyline[] polylineArray = new Polyline[NUM_OF_FILES];
        for (int i = 0; i < polylineArray.length; i++) {
            polylineArray[i] = populatePolylineArray(i);
        }

        // creates buttons used in each scene since every button can only
        // have one parent, then set text.
        Button[] btPreviousArray = new Button[NUM_OF_FILES];
        Button[] btNextArray = new Button[NUM_OF_FILES];
        for (int i = 0; i < btPreviousArray.length; i++) {
            btPreviousArray[i] = new Button();
            btPreviousArray[i].setText("Previous");
            btNextArray[i] = new Button();
            btNextArray[i].setText("Next");
        }

        // creates array of hboxes, then allocate each button to a specific
        // index of the array and set x coordinate.
        HBox[] hBoxArray = new HBox[NUM_OF_FILES];
        for (int i = 0; i < hBoxArray.length; i++) {
            hBoxArray[i] = new HBox(10);
            hBoxArray[i].getChildren().addAll(btPreviousArray[i]);
            hBoxArray[i].getChildren().addAll(btNextArray[i]);
            hBoxArray[i].setLayoutX(225);
        }
        
        // creates array of panes that each scene will display and add
        // the requested polyline and buttons
        Pane[] paneArray = new Pane[NUM_OF_FILES];
        for (int i = 0; i < paneArray.length; i++) {
            paneArray[i] = new Pane();
            paneArray[i].getChildren().add(polylineArray[i]);
            paneArray[i].getChildren().add(hBoxArray[i]);
        }
        
        // creates array of scenes with specific panes as the root node so they
        // can easily be swapped through using the previous and next buttons
        Scene[] sceneArray = new Scene[NUM_OF_FILES];
        for (int i = 0; i < sceneArray.length; i++) {
            sceneArray[i] = new Scene(paneArray[i], 550, 550);
        }

        // set up the mouse event code for each previous and next button
        // in the button array
        for (int i = 0; i < NUM_OF_FILES; i++) {
            btPreviousArray[i].setOnMouseClicked((MouseEvent e) -> {
                currentScene--;
                if (currentScene == -1) {
                    currentScene = 9;
                }
                primaryStage.setScene(sceneArray[currentScene]);
                primaryStage.setTitle("Line Image #" + (currentScene + 1));
            });

            btNextArray[i].setOnMouseClicked((MouseEvent e) -> {
                currentScene++;
                if (currentScene == 10) {
                    currentScene = 0;
                }
                primaryStage.setScene(sceneArray[currentScene]);
                primaryStage.setTitle("Line Image #" + (currentScene + 1));
            });
        }
        
        // sets default title and scene, currentScene + 1 used to simulate
        // more common counting methods
        primaryStage.setTitle("Line Image #" + (currentScene + 1));
        primaryStage.setScene(sceneArray[0]);
        primaryStage.show();
    }

        // method used to populate each polyline of the polyline array
        // with its 10 sets of x,y coordinates read from each temp.dat file
    public Polyline populatePolylineArray(int fileNumber) {
        double[] coords = new double[20];
        Polyline polyline = new Polyline();
        try {
            DataInputStream fin = new DataInputStream(new FileInputStream("binaryfiles/temp" + fileNumber + ".dat"));
            for (int i = 0; i < 20; i++) {
                try {
                    coords[i] = fin.readDouble();
                } catch (IOException e) {
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("Error, the file could not be found.");
        }

        try {
            polyline.getPoints().addAll(new Double[]{
                coords[0], coords[1],
                coords[2], coords[3],
                coords[4], coords[5],
                coords[6], coords[7],
                coords[8], coords[9],
                coords[10], coords[11],
                coords[12], coords[13],
                coords[14], coords[15],
                coords[16], coords[17],
                coords[18], coords[19]
            });
        } catch (NullPointerException e) {
        // should go 0 to 19 but just in case NullPointerException occurs
        }
        return polyline;
    }
    
    public static void main(String[] args) {
        launch(args);
    }
}
