/* Enzo Galbo
 * 3/4/2015
 * Steve Klein
 * This class is a specific type of Container called a Tank
 * that is designed to carry fluids which can be added
 * more dynamically than in CargoBox.
 */
package program2;

public class Tank extends Container {
    
    private String contentType;

    public Tank() {
    }

    public Tank(String contentType) {
        this.contentType = contentType;
    }

    public Tank(String contentType, int capacity, int currentAmount) {
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
        this.contentType = contentType;
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
            int amountAdded = (capacity - currentAmount);
            currentAmount += amount;
            if (currentAmount >= capacity) {
                currentAmount = capacity; 
                return amountAdded;
            }
            return amount;
        }
        else {
            return 0;
        }    
    }

    @Override
    public int remove(int amount) {
        if (amount > 0) {
            int amountRemoved = currentAmount;
            currentAmount -= amount;
            if (currentAmount < 0) {
                currentAmount = 0;
                return amountRemoved;
            }
            return amount;
        }
        else {
            return 0;
        }
    }
    
    public void drain() {
        currentAmount = 0;
    }

    public String getContentType() {
        return contentType;
    }

    public void setContentType(String contentType) {
        this.contentType = contentType;
    }

}
