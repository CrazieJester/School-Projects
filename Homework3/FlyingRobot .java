/* Enzo Galbo
 * 2/17/2015
 * CS 150
 * A flying robot is a type of robot that instead of walking
 * from building to building flies there.  The robot is still
 * not intelligent enough to go directly to the destination
 * but it has a limited fuel capacity and
 * once it runs out of fuel it stops moving.
 * I overrided the amIThere method so that if fuel runs out
 * the robot is set to its location so that the program can
 * eventually end.
 * The fuel amount can be set using the non-default constructor
 * or the setFuelAmount method.
 */
package examples;

public class FlyingRobot extends Robot {

    int fuelAmount;
    boolean fuelDepleted;
    
    public FlyingRobot() {
    }

    public FlyingRobot(Building currentLocation, Building targetLocation, int startingFuel, boolean hasFuel) {
        super(currentLocation, targetLocation);
        fuelAmount = startingFuel;
        fuelDepleted = hasFuel;
    }

    @Override
    public void move() {
        
        if (fuelAmount == 0) {
            fuelDepleted = true;
            System.out.println("I can't fly without fuel!");
        } 
  
        if (fuelDepleted == false) {
            super.move();
            fuelAmount--;
        }
                
    }
    
    @Override
    public boolean amIThere() {
        if (fuelAmount == 0) {
            return true;
        }
        else return (currentLocation == targetLocation);
    }
    
    public int getFuelAmount() {
        return fuelAmount;
    }

    public void setFuelAmount(int fuelAmount) {
        this.fuelAmount = fuelAmount;
    }

    public boolean getFuelDepleted() {
        return fuelDepleted;
    }

    public void setFuelDepleted(boolean fuelDepleted) {
        this.fuelDepleted = fuelDepleted;
    }
    
}
