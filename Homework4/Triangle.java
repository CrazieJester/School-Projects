/*
 * Enzo Galbo
 * CS 150
 * 2/22/2015
 * Steve Klein
 * Defines triangle object and some methods
 */
package program;

public class Triangle extends GeometricObject1 {
    
    final double DEFAULT_SIDE = 1;

    double side1;
    double side2;
    double side3;

    public Triangle() {
    }

    public Triangle(double side1, double side2, double side3) {
        if (isInputValid(side1, side2, side3) == true) {
            this.side1 = side1;
            this.side2 = side2;
            this.side3 = side3;
        }
        else {
            this.side1 = DEFAULT_SIDE;
            this.side2 = DEFAULT_SIDE;
            this.side3 = DEFAULT_SIDE;
        }
    }

    private boolean isInputValid(double s1, double s2, double s3) {
        if ((s1 + s2 > s3) && (s1 + s3 > s2) && (s2 + s3 > s1)) {
            return true;
        }
        else {
            return false;
        }
    }
    
    public double getSide1() {
        return side1;
    }

    public double getSide2() {
        return side2;
    }

    public double getSide3() {
        return side3;
    }

    public void setSide1(double side1) {
        this.side1 = side1;
    }

    public void setSide2(double side2) {
        this.side2 = side2;
    }

    public void setSide3(double side3) {
        this.side3 = side3;
    }
    
    public double getArea() {
        double p = (side1 + side2 + side3)/2;
        double x = p*(p-side1)*(p-side2)*(p-side3);
        double area = Math.sqrt(x);
        return area;
    }
    
    public double getPerimeter() {
        double perimeter = (side1 + side2 + side3);
        return perimeter;
    }

    @Override
    public String toString() {
        return "Triangle: " + "side1 = " + side1 + ", side2 = " + side2 + ", side3 = " + side3;
    }
    
    
}
