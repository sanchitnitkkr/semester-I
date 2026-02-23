package labFiles;

class Employee {
    private int salary = 40_000;

    Employee() {
        this.setSalary(salary);
    }

    Employee(int salary) {
        this.setSalary(salary);
    }

    int getSalary() {
        return this.salary;
    }

    void setSalary(int updatedSalary) {
        this.salary = updatedSalary;
    }

}

class Marketer extends Employee {
    private int salary = 50_000;

    Marketer() {
        super(50_000);
    }

    void advertise() {
        System.out.println("Act now, while supplies last!");
    }

    int getSalary() {
        return this.salary;
    }

    void setSalary(int updatedSalary) {
        this.salary = updatedSalary;
    }
}

public class W4_Q2 {
    public static void main(String[] args) {
        Marketer marketer = new Marketer();
        marketer.advertise();
    }

}
