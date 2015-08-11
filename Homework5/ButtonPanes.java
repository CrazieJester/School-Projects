/* Enzo Galbo
 * 3/4/2015
 * Steve Klein
 * This is a Javafx program that shows how different types of panes work.
 * This is done by declaring different types of panes and displaying buttons
 * then showing examples of things you can do with buttons in panes
 * such as rotating them.
 */
package Homework5;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Homework5 extends Application {
  @Override // Override the start method in the Application class
  public void start(Stage primaryStage) {
    
    Pane pane = new Pane();
    FlowPane flowPane = new FlowPane();
    StackPane stackPane = new StackPane();
    BorderPane borderPane = new BorderPane();
    HBox hBox = new HBox();
    VBox vBox = new VBox();

    Button[] flowPaneButtons = new Button[5];
    createButtonArray(flowPaneButtons);
    Button[] stackPaneButtons = new Button[5];
    createButtonArray(stackPaneButtons);
    Button[] hBoxButtons = new Button[5];
    createButtonArray(hBoxButtons);
    Button[] vBoxButtons = new Button[5];
    createButtonArray(vBoxButtons);
    
    Button btHello = new Button("Hello");
    btHello.setRotate(Math.random()*360);
 
    pane.getChildren().add(btHello);

    borderPane.setTop(flowPane);
    borderPane.setBottom(hBox);
    borderPane.setLeft(stackPane);
    borderPane.setRight(vBox);
    borderPane.setCenter(btHello);
    
    flowPane.getChildren().addAll(flowPaneButtons);
    stackPane.getChildren().addAll(stackPaneButtons);
    hBox.getChildren().addAll(hBoxButtons);
    vBox.getChildren().addAll(vBoxButtons);

    // Create a scene and place it in the stage
    Scene scene = new Scene(borderPane, 500, 500);
    primaryStage.setTitle("Buttons"); // Set the stage title
    primaryStage.setScene(scene); // Place the scene in the stage
    primaryStage.show(); // Display the stage
  }

    public void createButtonArray(Button[] buttonArray) {
        Dictionary myDictionary = new Dictionary();
        for (int i = 0; i < 5; i++) {
        String temp = myDictionary.getRandomWord();
        buttonArray[i] = new Button();
        buttonArray[i].setText(temp);
        double rotationDegrees = Math.random() * 360;
        buttonArray[i].setRotate(rotationDegrees);    
    }
}

  public static void main(String[] args) {
    launch(args);
  }
}