package labFiles;

public class Temp {
    public static void squareHollowPattern(int rows, int columns) {
        for (int i = 0; i < rows; i++) {
            String temp = "";
            for (int j = 0; j < columns; j++) {
                if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
                    temp += "* ";
                } else {
                    temp += " ";
                }
            }
            System.out.println(temp);
        }
    }

    public static void main(String[] args) {
        squareHollowPattern(6, 5);
    }
}