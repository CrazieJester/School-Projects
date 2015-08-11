/*
 * Enzo Galbo
 * 1/25/2015
 * CS 150
 * Steven Klein
 * Define candle object with various methods
 */
package homework;

public class Candle {

    private double height;
    private double width;
    private boolean isLit;
    
    public static final double DEFAULT_HEIGHT = 12.0;
    public static final double DEFAULT_WIDTH = 3.0;
    public static final double MINIMUM_HEIGHT = 0.0;
    public static final double MINIMUM_WIDTH = 0.1;
    
    public Candle() {
        height = DEFAULT_HEIGHT;
        width = DEFAULT_WIDTH;
        isLit = false;    
    }
    
    public Candle(double newHeight, double newWidth) {
        if (newHeight > MINIMUM_HEIGHT) {
        height = newHeight;
        }
        else {
            System.out.println("Height must be above " + MINIMUM_HEIGHT);
            System.exit(0);
        }
        if (newWidth > MINIMUM_WIDTH) {
        width = newWidth;
        }
        else {
            System.out.println("Width must be above " + MINIMUM_WIDTH);
            System.exit(0);
        }
    }

    @Override
    public String toString() {
        return "Candle" + " height = " + height + ", width = " + width + ", isLit = " + isLit;
    }
    
    public double calculateBurnRate() {
       double burnRate = (DEFAULT_WIDTH / width);
       return burnRate;
    }
    
    public boolean burn(double time) {
        double candleBurned = 0;
        double candleRemaining = 0;
        isLit = true;
        if (time >= 0.0) {
        candleBurned = time*(DEFAULT_WIDTH / width);
        candleRemaining = height - candleBurned;
        }
        else {
                System.out.println("Time must be greater than or equal to 0.");
                System.exit(0);
                }
        if (candleRemaining > 0.0) {
            height = candleRemaining;
            isLit = true;
        }
        else {
            height =  MINIMUM_HEIGHT;
            isLit = false;
        }
            return isLit;
    }
    
    public void setHeight(double newHeight) {
        if (newHeight > MINIMUM_HEIGHT) {
        height = newHeight;
        }
        else {
            System.out.println("Height must be above " + MINIMUM_HEIGHT);
            System.exit(0);
        }
    }
    
    public void setWidth(double newWidth) {
        if (newWidth > MINIMUM_WIDTH) {
        width = newWidth;
        }
        else {
            System.out.println("Width must be above " + MINIMUM_WIDTH);
            System.exit(0);
        }
    }
    
    public void setIsLit(boolean isLit) {
        this.isLit = isLit;
    }
    
    public double getHeight() {
        return height;
    }
    
    public double getWidth() {
        return width;
    }
   
    public boolean getIsLit() {
        return isLit;
    }
}
