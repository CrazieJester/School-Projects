/* Enzo Galbo
 * 3/4/2015
 * Steve Klein
 * This class is a specific type of Container called a CargoBox.
 * This is designed to hold separate boxes of specific size
 * and thus a box cannot be added at all if there is not enough room for it.
 */
package program2;

public class CargoBox extends Container {

    public CargoBox() {
    }

    public CargoBox(int capacity, int currentAmount) {
        super(capacity, currentAmount);
        if (capacity < 0) {
            this.capacity = 0;
        }
        if (currentAmount < 0) {
            this.currentAmount = 0;
        }
        if (currentAmount > capacity) {
            this.currentAmount = capacity;
        }
    }

    @Override
    public void setCapacity(int capacity) {
        if (capacity >=0) {
            this.capacity = capacity;
        }
        else {
            this.capacity = 0;
        }
    }

    @Override
    public void setCurrentAmount(int currentAmount) {
            this.currentAmount = currentAmount;
        if (currentAmount > capacity) {
            this.currentAmount = capacity;
        }
        if (currentAmount < 0) {
            this.currentAmount = 0;
        }    
  
    }    

    @Override
    public int add(int amount) {
        if (amount > 0) {
            if ((currentAmount + amount) > capacity) {
            return 0;
            }
            else { 
            currentAmount += amount;
            return 1;        
            }
        }
        else {
            return 0;
        }
    }

    @Override
    public int remove(int amount) {
        if (amount > 0) {
            if ((currentAmount - amount)  < 0) {
                return 0;
            }
            else {
                currentAmount -= amount;
                return 1;
            }
        }
        else {
            return 0;
        }
    }
}
