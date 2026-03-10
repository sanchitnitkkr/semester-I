package labFiles;

class MyClass1 {
    protected int myProtectedVar2;
}

class MyClass2  extends MyClass1{
    void someMethod(){
        myProtectedVar2 = 2;
    }
}


public class W4_Q1 {
    int myPrivateVar; // Accessible only within the class
    protected int myProtectedVar; // Accessible for child classes
    int defaultVar; // Accessible within the same file and package
    public int publicVar; // Accessible from anywhere

    public static void main(String[] args) {
    }
}
