/* Enzo Galbo
 * 3/4/2015
 * Steve Klein
 * This is a javafx program that allows the user to left click
 * to create a point and then right click on the circle to remove it.
 */
package homework6;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javafx.scene.paint.Color;

public class Homework6 extends Application {
  @Override // Override the start method in the Application class
  public void start(Stage primaryStage) {
    // Create a pane and set its properties
    Pane pane = new Pane();

    pane.setOnMouseClicked((MouseEvent e) -> {    
      if (e.getButton() == MouseButton.PRIMARY) {
      Circle circle = new Circle(e.getX(),e.getY(),10);
      circle.setFill(Color.WHITE);
      circle.setStroke(Color.BLACK);
      pane.getChildren().addAll(circle);
      }
      if (e.getButton() == MouseButton.SECONDARY) {
            pane.getChildren().remove(e.getTarget());
        }
    });

    
    // Create a scene and place it in the stage
    Scene scene = new Scene(pane, 300, 300);
    primaryStage.setTitle("Homework 6"); // Set the stage title
    primaryStage.setScene(scene); // Place the scene in the stage
    primaryStage.show(); // Display the stage
  }

  /**
   * The main method is only needed for the IDE with limited
   * JavaFX support. Not needed for running from the command line.
     * @param args
   */
  public static void main(String[] args) {
    launch(args);
  }
} 