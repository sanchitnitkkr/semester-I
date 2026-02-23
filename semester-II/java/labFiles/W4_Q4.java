package labFiles;

abstract class Shape {
    abstract int area();
}

abstract class Rectangle extends Shape {
    public static int area(int len, int breadth) {
        return len * breadth;
    }
}

abstract class Circle extends Shape {
    public static int area(int radius) {
        return radius * radius;
    }
}

abstract class Triangle extends Shape {
    public static int area(int base, int height) {
        return (base * height) / 2;
    }
}

public class W4_Q4 {
    public static void main(String[] args) {
        Rectangle.area(5,10);
        Circle.area(10);
        Triangle.area(10,5);
    }
}