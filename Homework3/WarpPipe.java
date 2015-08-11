/* Enzo Galbo
 * 2/17/2015
 * CS 150
 * A warp pipe is a building type that leads you to the goal.
 * This is a building you could set on a part of the map that is
 * hard to get out of to provide a shortcut, or a place with a low
 * probability of reaching to add chance for the robot to skip ahead.
 * This is a reference to Mario where you could find hidden pipes
 * that skip you ahead in worlds.
 */
package examples;

public class WarpPipe extends Building {

    public WarpPipe() {
    }

    public WarpPipe(String name) {
        super(name);
    }
    
    @Override
    public void setAdjacencies(Building[] adjacencies) {
        Building[] warpAdjacencies;
        warpAdjacencies = new Building[1];
        warpAdjacencies[0] = Robot.targetLocation;
    }
    

}

