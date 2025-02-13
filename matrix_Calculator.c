#include <stdio.h>
#include <stdlib.h>

/*Start Helper Functions Section*/
void displayAsciiArt();
void scanReal(float *x);
void scanInteger(int *x);
void getMatrixSize(int *rows, int *cols);
float **allocateMatrix(int rows, int cols);
void fillMatrix(float **matrix, int rows, int cols, char matName);
void displayMatrix(float **matrix, int rows, int cols);
void freeMatrix(float ***matrix, int rows);
float **getMinor(float **matrix, int row, int col, int n);
/*End Helper Functions Section*/

/*Start Matrix Operations Section*/
float **matrixAddition(float **mat1, float **mat2, int rows, int cols);
float **matrixSubtraction(float **mat1, float **mat2, int rows, int cols);
float **matrixMultiplication(float **mat1, float **mat2, int n, int m, int p);
float **scalarMultiplication(float **mat, float k, int rows, int cols);
float computeDeterminant(float **matrix, int n);
float **computeTransposeMatrix(float **matrix, int rows, int cols);
float **computeCofactorMatrix(float **matrix, int n);
/*End Matrix Operations Section*/

/*Start Menus Section*/
void matrixAdditionMenu();
void matrixSubtractionMenu();
void matrixMultiplicationMenu();
void scalarMultiplicationMenu();
void computeDeterminantMenu();
void computeTransposeMatrixMenu();
void computeCofactorMatrixMenu();
void computeAdjugateMatrixMenu();
void computeInverseMatrixMenu();
void mainMenu();

/*End Menus Section*/

int main() {
  displayAsciiArt();
  mainMenu();
  return 0;
}

/*Srart Helper Functions Section*/
void displayAsciiArt() {
  printf(" __  __       _        _                         \n");
  printf("|  \\/  | __ _| |_ _ __(_)_  __                   \n");
  printf("| |\\/| |/ _` | __| '__| \\ \\/ /                   \n");
  printf("| |  | | (_| | |_| |  | |>  <                    \n");
  printf("|_|__|_|\\__,_|\\__|_|  |_/_/\\_\\   _               \n");
  printf(" / ___|__ _| | ___ _   _| | __ _| |_ ___  _ __   \n");
  printf("| |   / _` | |/ __| | | | |/ _` | __/ _ \\| '__|  \n");
  printf("| |__| (_| | | (__| |_| | | (_| | || (_) | |     \n");
  printf(" \\____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|     \n");
}

void scanReal(float *x) {
  while (scanf("%f", x) != 1) {
    printf("Invalid input. Please enter a number: ");
    while (getchar() != '\n');
  }
}

void scanInteger(int *x) {
  while (scanf("%d", x) != 1) {
    printf("Invalid input. Please enter an integer: ");
    while (getchar() != '\n');
  }
}

void getMatrixSize(int *rows, int *cols) {
  printf("Enter the number of rows: ");
  scanInteger(rows);
  while ((*rows) <= 0) {
    printf("The number of rows must be greater than 0: ");
    scanInteger(rows);
  }

  printf("Enter the number of columns: ");
  scanInteger(cols);
  while ((*cols) <= 0) {
    printf("The number of columns must be greater than 0: ");
    scanInteger(cols);
  }
}

float **allocateMatrix(int rows, int cols) {
  float **matrix = (float **)malloc(rows * sizeof(float *));
  if (matrix == NULL) {
    return NULL;
  }

  for (int i = 0; i < rows; i++) {
    matrix[i] = (float *)malloc(cols * sizeof(float));
    if (matrix[i] == NULL) {
      // Free all previously allocated memory before returning NULL
      for (int j = 0; j < i; j++) {
        free(matrix[j]);
      }
      free(matrix);
      matrix = NULL;
      return NULL;
    }
  }

  return matrix;
}

void fillMatrix(float **matrix, int rows, int cols, char matName) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c[%d][%d] : ", matName, i + 1, j + 1);
      scanReal(&matrix[i][j]);
    }
  }
}

void displayMatrix(float **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%.1f\t", matrix[i][j]);
    }
    printf("\n");
  }
}

void freeMatrix(float ***matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free((*matrix)[i]);
  }
  free(*matrix);
  (*matrix) = NULL;
}

// Function to extract a minor matrix by removing a specified row and column
float **getMinor(float **matrix, int row, int col, int n) {
  float **minor = allocateMatrix(n - 1, n - 1);
  if (minor == NULL) {
    return NULL;
  }

  int r = 0;
  for (int i = 0; i < n; i++) {
    if (i == row) continue;  // Skip the specified row
    int c = 0;
    for (int j = 0; j < n; j++) {
      if (j == col) continue;  // Skip the specified column
      minor[r][c] = matrix[i][j];
      c++;
    }
    r++;
  }
  return minor;
}
/*End Helper Functions Section*/

/*Start Matrix Operations Section*/
float **matrixAddition(float **mat1, float **mat2, int rows, int cols) {
  float **mat3 = allocateMatrix(rows, cols);
  if (mat3 == NULL) {
    return NULL;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      mat3[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
  return mat3;
}

float **matrixSubtraction(float **mat1, float **mat2, int rows, int cols) {
  float **mat3 = allocateMatrix(rows, cols);
  if (mat3 == NULL) {
    return NULL;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      mat3[i][j] = mat1[i][j] - mat2[i][j];
    }
  }
  return mat3;
}

float **matrixMultiplication(float **mat1, float **mat2, int n, int m, int p) {
  float **mat3 = allocateMatrix(n, p);
  if (mat3 == NULL) {
    return NULL;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      mat3[i][j] = 0;
      for (int k = 0; k < m; k++) {
        mat3[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }

  return mat3;
}

float **scalarMultiplication(float **mat, float k, int rows, int cols) {
  float **result = allocateMatrix(rows, cols);
  if (result == NULL) {
    return NULL;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = mat[i][j] * k;
    }
  }

  return result;
}

float computeDeterminant(float **matrix, int n) {
  if (n == 1) {
    return matrix[0][0];
  }
  if (n == 2) {
    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
  }

  float determinant = 0;

  for (int col = 0; col < n; col++) {
    float **minor = getMinor(matrix, 0, col, n);
    if (minor == NULL) {
      printf("Memory allocation failed!\n");
      mainMenu();
    }
    float cofactor = (col % 2 == 0 ? 1 : -1) * matrix[0][col] * computeDeterminant(minor, n - 1);
    determinant += cofactor;
    freeMatrix(&minor, n - 1);
  }

  return determinant;
}

float **computeTransposeMatrix(float **matrix, int rows, int cols) {
  float **transMat = allocateMatrix(cols, rows);
  if (transMat == NULL) {
    return NULL;
  }

  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      transMat[i][j] = matrix[j][i];
    }
  }

  return transMat;
}

float **computeCofactorMatrix(float **matrix, int n) {
  float **C = allocateMatrix(n, n);
  if (C == NULL) {
    return NULL;
  }

  if (n == 1) {
    C[0][0] = 1;
    return C;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      float **minor = getMinor(matrix, i, j, n);
      if (minor == NULL) {
        freeMatrix(&C, n);
        return NULL;
      }
      C[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * computeDeterminant(minor, n - 1);
      freeMatrix(&minor, n - 1);
    }
  }

  return C;
}

/*End Matrix Operations Section*/

/*Start Menus Section*/
void mainMenu() {
  int choice;

  while (1) {
    printf("\n\t    MAIN MENU\n");
    printf("================================\n");
    printf("[1] Matrix Addition.\n");
    printf("[2] Matrix Subtraction.\n");
    printf("[3] Matrix Multiplication.\n");
    printf("[4] Scalar Multiplication.\n");
    printf("[5] Compute Determinant.\n");
    printf("[6] Compute Transpose Matrix.\n");
    printf("[7] Compute Cofactor Matrix.\n");
    printf("[8] Compute Adjugate Matrix.\n");
    printf("[9] Compute Inverse Matrix.\n");
    printf("[0] Exit.\n");
    printf("================================\n");
    printf("Enter your choice: ");
    scanInteger(&choice);
    while (choice < 0 || choice > 9) {
      printf("Error: please enter a valid option from the menu!: ");
      scanInteger(&choice);
    }

    switch (choice) {
      case 1:
        matrixAdditionMenu();
        break;
      case 2:
        matrixSubtractionMenu();
        break;
      case 3:
        matrixMultiplicationMenu();
        break;
      case 4:
        scalarMultiplicationMenu();
        break;
      case 5:
        computeDeterminantMenu();
        break;
      case 6:
        computeTransposeMatrixMenu();
        break;
      case 7:
        computeCofactorMatrixMenu();
        break;
      case 8:
        computeAdjugateMatrixMenu();
        break;
      case 9:
        computeInverseMatrixMenu();
        break;
      case 0:
        exit(0);
        break;
    }
  }
}

void matrixAdditionMenu() {
  int rows, cols;
  printf("\n**** Add Two Matrices ****\n");
  printf("A(n x m) + B(n x m)\n");
  getMatrixSize(&rows, &cols);
  float **A = allocateMatrix(rows, cols);
  if (A == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  printf("Fill the matrix A:\n");
  fillMatrix(A, rows, cols, 'A');

  float **B = allocateMatrix(rows, cols);
  if (B == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  printf("Fill the matrix B:\n");
  fillMatrix(B, rows, cols, 'B');

  float **C = matrixAddition(A, B, rows, cols);
  if (C == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  freeMatrix(&A, rows);
  freeMatrix(&B, rows);
  printf("The result:\n");
  displayMatrix(C, rows, cols);
  freeMatrix(&C, rows);
}

void matrixSubtractionMenu() {
  int rows, cols;
  printf("\n**** Subtract Two Matrices ****\n");
  printf("A(n x m) - B(n x m)\n");
  getMatrixSize(&rows, &cols);
  float **A = allocateMatrix(rows, cols);
  if (A == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  printf("Fill the matrix A:\n");
  fillMatrix(A, rows, cols, 'A');

  float **B = allocateMatrix(rows, cols);
  if (B == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  printf("Fill the matrix B:\n");
  fillMatrix(B, rows, cols, 'B');

  float **C = matrixSubtraction(A, B, rows, cols);
  if (C == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  freeMatrix(&A, rows);
  freeMatrix(&B, rows);
  printf("The result:\n");
  displayMatrix(C, rows, cols);
  freeMatrix(&C, rows);
}

void matrixMultiplicationMenu() {
  int n, m, p;
  printf("\n**** Multiply Two Matrices ****\n");
  printf("A(n x m) x B(m x p)\n");

  printf("Enter n (the number of rows of Matrix A): ");
  scanInteger(&n);
  while (n <= 0) {
    printf("n must be greater than 0: ");
    scanInteger(&n);
  }

  printf("Enter m (the number of columns of Matrix A and the number of rows of matrix B): ");
  scanInteger(&m);
  while (m <= 0) {
    printf("m must be greater than 0: ");
    scanInteger(&m);
  }

  printf("Enter p (the number of columns of Matrix B): ");
  scanInteger(&p);
  while (p <= 0) {
    printf("p must be greater than 0: ");
    scanInteger(&p);
  }

  float **A = allocateMatrix(n, m);
  if (A == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  printf("Fill the matrix A:\n");
  fillMatrix(A, n, m, 'A');

  float **B = allocateMatrix(m, p);
  if (B == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  printf("Fill the matrix B:\n");
  fillMatrix(B, m, p, 'B');

  float **C = matrixMultiplication(A, B, n, m, p);
  if (C == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  freeMatrix(&A, n);
  freeMatrix(&B, m);
  printf("The result:\n");
  displayMatrix(C, n, p);
  freeMatrix(&C, n);
}

void scalarMultiplicationMenu() {
  int rows, cols;
  float k;
  printf("\n**** Scalar Multiplication ****\n");
  printf("A(n x m) x K\n");
  getMatrixSize(&rows, &cols);
  float **A = allocateMatrix(rows, cols);
  if (A == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  printf("Fill the matrix A:\n");
  fillMatrix(A, rows, cols, 'A');

  printf("Enter the Scalar K: ");
  scanReal(&k);

  float **result = scalarMultiplication(A, k, rows, cols);
  if (result == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  freeMatrix(&A, rows);
  printf("The result:\n");
  displayMatrix(result, rows, cols);
  freeMatrix(&result, rows);
}

void computeDeterminantMenu() {
  int n;
  printf("\n**** Calculate Determinant ****\n");
  printf("Det( A(n x n) )\n");
  printf("Enter n (the size of the matrix A): ");
  scanInteger(&n);
  while (n <= 0) {
    printf("n must be greater than 0: ");
    scanInteger(&n);
  }

  float **A = allocateMatrix(n, n);
  if (A == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  printf("Fill the matrix A:\n");
  fillMatrix(A, n, n, 'A');

  float det = computeDeterminant(A, n);
  printf("Det( A ) = %.2f\n", det);
  freeMatrix(&A, n);
}

void computeTransposeMatrixMenu() {
  int rows, cols;
  printf("\n**** Calculate Transpose Matrix ****\n");
  printf("Transpose( A(n x m) )\n");
  getMatrixSize(&rows, &cols);
  float **A = allocateMatrix(rows, cols);
  if (A == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  printf("Fill the matrix A:\n");
  fillMatrix(A, rows, cols, 'A');

  float **trans = computeTransposeMatrix(A, rows, cols);
  if (trans == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  freeMatrix(&A, rows);
  printf("The result:\n");
  displayMatrix(trans, cols, rows);
  freeMatrix(&trans, cols);
}

void computeCofactorMatrixMenu() {
  int n;
  printf("\n**** Calculate Cofactor Matrix ****\n");
  printf("Cofactor( A(n x n) )\n");
  printf("Enter n (the size of the matrix A): ");
  scanInteger(&n);
  while (n <= 0) {
    printf("n must be greater than 0: ");
    scanInteger(&n);
  }

  float **A = allocateMatrix(n, n);
  if (A == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  printf("Fill the matrix A:\n");
  fillMatrix(A, n, n, 'A');

  float **C = computeCofactorMatrix(A, n);
  if (C == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  freeMatrix(&A, n);
  printf("The result:\n");
  displayMatrix(C, n, n);
  freeMatrix(&C, n);
}

void computeAdjugateMatrixMenu() {
  int n;
  printf("\n**** Calculate Adjugate Matrix ****\n");
  printf("Adjugate( A(n x n) )\n");
  printf("Enter n (the size of the matrix A): ");
  scanInteger(&n);
  while (n <= 0) {
    printf("n must be greater than 0: ");
    scanInteger(&n);
  }

  float **A = allocateMatrix(n, n);
  if (A == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  printf("Fill the matrix A:\n");
  fillMatrix(A, n, n, 'A');

  float **cofactor = computeCofactorMatrix(A, n);
  if (cofactor == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  float **adjugate = computeTransposeMatrix(cofactor, n, n);
  if (adjugate == NULL) {
    printf("Memory allocation failed!\n");
    freeMatrix(&cofactor, n);
    return;
  }

  freeMatrix(&A, n);
  freeMatrix(&cofactor, n);
  printf("The result:\n");
  displayMatrix(adjugate, n, n);
  freeMatrix(&adjugate, n);
}

void computeInverseMatrixMenu() {
  int n;
  printf("\n**** Calculate Inverse Matrix ****\n");
  printf("Inverse( A(n x n) )\n");
  printf("Enter n (the size of the matrix A): ");
  scanInteger(&n);
  while (n <= 0) {
    printf("n must be greater than 0: ");
    scanInteger(&n);
  }

  float **A = allocateMatrix(n, n);
  if (A == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  printf("Fill the matrix A:\n");
  fillMatrix(A, n, n, 'A');

  float det = computeDeterminant(A, n);
  if (det == 0) {
    printf("A is singular (non-invertible).\n");
    freeMatrix(&A, n);
    return;
  }

  float **cofactor = computeCofactorMatrix(A, n);
  if (!cofactor) {
    printf("Memory allocation failed!\n");
    freeMatrix(&A, n);
    return;
  }

  float **transpose = computeTransposeMatrix(cofactor, n, n);
  if (!transpose) {
    printf("Memory allocation failed!\n");
    freeMatrix(&A, n);
    freeMatrix(&cofactor, n);
    return;
  }

  float **Inv = scalarMultiplication(transpose, 1.0f / det, n, n);
  if (!Inv) {
    printf("Memory allocation failed!\n");
    freeMatrix(&A, n);
    freeMatrix(&cofactor, n);
    freeMatrix(&transpose, n);
    return;
  }

  freeMatrix(&A, n);
  freeMatrix(&cofactor, n);
  freeMatrix(&transpose, n);
  printf("The result:\n");
  displayMatrix(Inv, n, n);
  freeMatrix(&Inv, n);
}
/*End Menus Section*/