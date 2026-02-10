
class Complex {
    float real;
    float imaginary;

    Complex(float real, float imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public Complex sum(Complex c2) {
        return this.sum(c2);
    };

    public static Complex sum(Complex c1, Complex c2) {
        float realRes = c1.real + c2.real;
        float imgRes = c1.imaginary + c2.imaginary;

        Complex c3 = new Complex(realRes, imgRes);
        return c3;
    }

    public Complex product(Complex c2) {
        return this.product(c2);
    };

    public static Complex product(Complex c1, Complex c2) {
        float realRes = (c1.real * c2.real) + (c1.imaginary * c2.imaginary);
        float imgRes = (c1.real * c2.imaginary) + (c1.imaginary * c2.real);

        Complex c3 = new Complex(realRes, imgRes);
        return c3;
    };

    public Complex difference(Complex c2) {
        return this.difference(c2);
    };

    public static Complex difference(Complex c1, Complex c2) {
        float realRes = c1.real - c2.real;
        float imgRes = c1.imaginary - c2.imaginary;

        Complex c3 = new Complex(realRes, imgRes);
        return c3;
    };

    public String print() {
        return this.real + this.imaginary < 0 ? " - " : " + " + this.imaginary;
    }

}

public class W3_Q2 {
    public static void main(String[] args) {
        Complex c1 = new Complex(5, 2);
        Complex c2 = new Complex(-3, 2);

        System.out.println("Sum: :" + c1.sum(c2).print());
        System.out.println("Product: :" + c1.product(c2).print());
        System.out.println("Difference: :" + c1.difference(c2).print());
    }
}
