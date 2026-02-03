import java.util.Scanner;

public class Q5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m1, n1, m2, n2;
        System.out.println("Enter dimensions of first matrix");
        System.out.println("Rows: ");
        m1 = sc.nextInt();
        System.out.println("Columns: ");
        n1 = sc.nextInt();

        System.out.println("Enter dimensions of second matrix");
        System.out.println("Rows: ");
        m2 = sc.nextInt();
        System.out.println("Columns: ");
        n2 = sc.nextInt();

        Matrix mat1 = new Matrix(m1, n1);
        Matrix mat2 = new Matrix(m2, n2);

        int[][] res = mat1.multiply(mat2);
        Matrix.printMatrix(res);
        sc.close();

    }
}

class Matrix {
    int arr[][];
    int rows = 0;
    int columns = 0;

    Matrix(int m, int n) {
        this.rows = m;
        this.columns = n;
        this.arr = new int[m][n];
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("Enter arr[" + i + "][" + j + "]: ");
                int element = sc.nextInt();
                arr[i][j] = element;
            }
        }
    }

    public static void printMatrix(int arr[][]) {
        int rows = arr.length;
        int columns = arr[0].length;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    /*
     * Mat1 : Mat2 :
     * 1 2 5 6
     * 3 4 7 8
     * 
     * Result
     * mat1[0][0] * mat2[00] + mat1[01] * mat2[10] mat1[0][0] * mat2[0][1] +
     * mat1[0][1] * mat2[1][0]
     * mat1[1][0] * mat2[00] + mat1[11] * mat2[01] mat1[1][1] * mat2[0][1] +
     * mat1[1][1] * mat2[1][1]
     * 
     */
    public int[][] multiply(Matrix mat2) {
        int m1 = this.rows;
        int n1 = this.columns;
        int m2 = mat2.rows;
        int n2 = mat2.columns;

        int[][] result = new int[m1][n2];

        if (n1 != m2) {
            return result;
        }

        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n2; j++) {
                int sum = 0;
                int k = 0;

                while (k < n1) {
                    sum += this.arr[i][k] * mat2.arr[k][j];
                    k++;
                }

                result[i][j] = sum;
            }
        }

        return result;
    }
}
