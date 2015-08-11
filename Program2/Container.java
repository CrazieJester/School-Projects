/* Enzo Galbo
 * 3/4/2015
 * Steve Klein
 * This class is an abstract class describing the broad topic
 * of containers.  This can be subclassed to implement specific containers,
 * in this case the "Tank" and "CargBox."
 * These classes together are not a program but will provide instance
 * variables and also methods that can be invoked and used in a program.
 */
package program2;

public abstract class Container {
    
    protected int capacity;
    protected int currentAmount;

    public Container() {
    }

    public Container(int capacity, int currentAmount) {
        this.capacity = capacity;
        this.currentAmount = currentAmount;
    }
    
    public abstract int add(int amount);
    
    public abstract int remove(int amount);
    
    public boolean isFull() {
        return currentAmount >= capacity;
    }
    
    public boolean isEmpty() {
        return currentAmount <= 0;
    }

    public int getCapacity() {
        return capacity;
    }

    public int getCurrentAmount() {
        return currentAmount;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public void setCurrentAmount(int currentAmount) {
        this.currentAmount = currentAmount;
    }
    
    
    
}
