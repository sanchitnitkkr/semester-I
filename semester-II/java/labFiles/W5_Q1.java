package labFiles;

interface CircleInterface {
    public float area();

    public static float area(float radius) {
        return radius * radius * (22 / 7);
    }
}

interface RectangleInterface {
    public float area();

    public static float area(float length, float breadth) {
        return length * breadth;
    }

}

class Circle implements CircleInterface {
    float radius;

    Circle(float r) {
        this.radius = r;
    };

    public float area() {
        return CircleInterface.area(this.radius);
    }
}

class Rectangle implements RectangleInterface {
    float length, breadth;

    Rectangle(float length, float breadth) {
        this.breadth = breadth;
        this.length = length;
    };

    public float area() {
        return RectangleInterface.area(length, breadth);
    }
}

public class W5_Q1 {

}
