package packageA;

import labFiles.W4_Q1;

public class W4_Q1_Subclass_In_Another_Package extends W4_Q1 {
    public void main() {
        this.myProtectedVar = 35; // Valid
        this.publicVar = 36; // Valid
        // this.defaultVar = 23; // Invalid
        // this.privateVar = 34; // Invalid
    }
}
