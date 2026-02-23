package labFiles;

class Bike {
    private int speed;

    // Call by reference
    static void changeSpeed(Bike b1, Bike b2) {
        int temp = b1.speed;
        b1.speed = b2.speed;
        b2.speed = temp;
    }

    void changeSpeed(int newSpeed) {
        this.speed = newSpeed;
    }

    int getSpeed() {
        return this.speed;
    }
}

public class W2_Q7 {
    public static void main(String[] args) {
        Bike b1 = new Bike();
        Bike b2 = new Bike();

        Bike.changeSpeed(b1, b2);
        // // Call by value
        // int temp = b1.getSpeed();
        // b1.changeSpeed(b2.getSpeed());
        // b2.changeSpeed(temp);
    }
}

