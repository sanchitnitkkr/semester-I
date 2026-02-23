package labFiles;
public class W4_Q1_Subclass extends W4_Q1 {
    public void main() {
        this.myProtectedVar = 3; // Valid
        this.defaultVar = 4; // Valid
        this.myPrivateVar = 2; // Invalid
        this.publicVar = 6; // Valid
    }
}
