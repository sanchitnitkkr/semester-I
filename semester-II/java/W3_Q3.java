class Box {
    int length, breadth, height;

    Box(int length, int breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    Box(int length, int breadth, int height) {
        this.length = length;
        this.breadth = breadth;
        this.height = height;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }

        Box other = (Box) obj;

        System.out.println(this.height + " " + other.height);

        boolean lengthEqual = this.length == other.length;
        boolean breadthEqual = this.breadth == other.breadth;
        boolean heightEqual = this.height == other.height;

        return lengthEqual && breadthEqual && heightEqual;
    }
}

public class W3_Q3 {
    public static void main(String[] args) {
        Box b1 = new Box(5, 3);
        Box b2 = new Box(10, 20);
        Box b3 = new Box(5, 3, 10);

        System.out.println(b1.equals(b3));
    }
}
