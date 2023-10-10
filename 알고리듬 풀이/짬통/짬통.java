import java.util.Random;

public class MatrixOperations {
    public static void main(String[] args) {
        // 랜덤한 행과 열을 가진 행렬을 생성
        int rows = new Random().nextInt(4) + 2; // 2에서 5까지의 난수
        int cols = new Random().nextInt(4) + 2;

        int[][] matrixA = createRandomMatrix(rows, cols);
        int[][] matrixB = createRandomMatrix(rows, cols);


        // 생성된 행렬 출력
        System.out.println("Matrix A:");
        printMatrix(matrixA, rows, cols);

        System.out.println("\nMatrix B:");
        printMatrix(matrixB, rows, cols);
        
        calculateMatrix(matrixA, matrixB, rows, cols);
    }

    // 랜덤한 값으로 채워진 행렬을 생성
    public static int[][] createRandomMatrix(int m, int n) {
        Random random = new Random();
        int[][] matrix = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = random.nextInt(10); // 0에서 9 사이의 
            }
        }
        return matrix;
    }
    
    // 두 행렬의 값을 계산하여 결과 행렬을 반환
    public static void calculateMatrix(int[][] a, int[][] b, int m, int n) {
       int[][] evenMatrix =  new int[10][10];
       int[][] oddMatrix =  new int[10][10];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] % 2 == 0 && b[i][j] % 2 == 0) {
                   evenMatrix[i][j] = a[i][j] + b[i][j];
                   oddMatrix[i][j] =0;
                }
                else if (a[i][j] % 2 == 1 && b[i][j] % 2 == 1) {
                   oddMatrix[i][j] = a[i][j] + b[i][j];
                   evenMatrix[i][j] = 0;
                }
                else if (a[i][j] % 2 == 0 && b[i][j] % 2 == 1) {
                   evenMatrix[i][j] = a[i][j];
                   oddMatrix[i][j] = b[i][j];
                }
                else if (a[i][j] % 2 == 1 && b[i][j] % 2 == 0) {
                   oddMatrix[i][j] =  a[i][j];
                   evenMatrix[i][j] = b[i][j];
                }
        }
      
        }
        System.out.println("\nEven Matrix:");
        printMatrix(evenMatrix, m, n); 
        System.out.println("\nOdd Matrix:");
        printMatrix(oddMatrix, m, n);
    }


    // 행렬을 출력
    public static void printMatrix(int[][] matrix, int m, int n)  {
        for( int i = 0; i< m; i++) {
            // System.out.print("\n");
            for(int j = 0; j< n; j++) {
               System.out.print(matrix[i][j] + " ");
            }
        }
    }
}