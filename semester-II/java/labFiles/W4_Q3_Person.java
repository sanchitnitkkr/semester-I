
package labFiles;

enum Gender {
    MALE("male"),
    FEMALE("female");

    private final String value;

    Gender(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }
}

public class W4_Q3_Person {
    private int age;
    private String name;
    private Gender gender;

    int getAge() {
        return this.age;
    }

    String getName() {
        return this.name;
    }

    public Gender getGender() {
        return gender;
    }

}
