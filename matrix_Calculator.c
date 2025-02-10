#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Start Helper Functions Section*/
void displayAsciiArt();
void getMatrixSize(int *rows, int *cols);
float **allocateMatrix(int rows, int cols);
void fillMatrix(float **mat, int rows, int cols, char matName);
void displayMatrix(float **mat, int rows, int cols);
void freeMatrix(float ***mat, int rows);
/*End Helper Functions Section*/

/*Start Matrix Operations Section*/
float **addTwoMatrices(float **mat1, float **mat2, int rows, int cols);
float **subtractTwoMatrices(float **mat1, float **mat2, int rows, int cols);
float **multiplyTwoMatrices(float **mat1, float **mat2, int n, int m, int p);
float **multiplyMatrixByScalar(float **mat, float k, int rows, int cols);
double calculateDeterminant(float **matrix, int n);
float **calculateTransposeMatrix(float **mat, int rows, int cols);
/*End Matrix Operations Section*/

/*Start Menus Section*/
void addTwoMatricesMenu();
void subtractTwoMatricesMenu();
void multiplyTwoMatricesMenu();
void multiplyMatrixByScalarMenu();
void calculateDeterminantMenu();
void calculateTransposeMatrixMenu();
void mainMenu();

/*End Menus Section*/

int main()
{
    displayAsciiArt();
    mainMenu();
    return 0;
}

/*Srart Helper Functions Section*/
void displayAsciiArt()
{
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

void getMatrixSize(int *rows, int *cols)
{
    printf("Enter the number of rows: ");
    scanf("%d", rows);
    while ((*rows) <= 0)
    {
        printf("The number of rows must be greater than 0: ");
        scanf("%d", rows);
    }

    printf("Enter the number of columns: ");
    scanf("%d", cols);
    while ((*cols) <= 0)
    {
        printf("The number of columns must be greater than 0: ");
        scanf("%d", cols);
    }
}

float **allocateMatrix(int rows, int cols)
{
    float **mat = (float **)malloc(rows * sizeof(float *));
    if (mat == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < rows; i++)
    {
        mat[i] = (float *)malloc(cols * sizeof(float));
        if (mat[i] == NULL)
        {
            // Free all previously allocated memory before returning NULL
            for (int j = 0; j < i; j++)
            {
                free(mat[j]);
            }
            free(mat);
            mat = NULL;
            return NULL;
        }
    }

    return mat;
}

void fillMatrix(float **mat, int rows, int cols, char matName)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c[%d][%d] : ", matName, i + 1, j + 1);
            if (scanf("%f", &mat[i][j]) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                j--; // Retry input for the same element
                while (getchar() != '\n')
                    ; // Clear input buffer
            }
        }
    }
}

void displayMatrix(float **mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%.1f\t", mat[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(float ***mat, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free((*mat)[i]);
    }
    free(*mat);
    (*mat) = NULL;
}
/*End Helper Functions Section*/

/*Start Matrix Operations Section*/
float **addTwoMatrices(float **mat1, float **mat2, int rows, int cols)
{
    float **mat3 = allocateMatrix(rows, cols);
    if (mat3 == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return mat3;
}

float **subtractTwoMatrices(float **mat1, float **mat2, int rows, int cols)
{
    float **mat3 = allocateMatrix(rows, cols);
    if (mat3 == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return mat3;
}

float **multiplyTwoMatrices(float **mat1, float **mat2, int n, int m, int p)
{
    float **mat3 = allocateMatrix(n, p);
    if (mat3 == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            mat3[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return mat3;
}

float **multiplyMatrixByScalar(float **mat, float k, int rows, int cols)
{
    float **result = allocateMatrix(rows, cols);
    if (result == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = mat[i][j] * k;
        }
    }

    return result;
}

double calculateDeterminant(float **matrix, int n)
{
    if (n == 1)
    {
        return matrix[0][0]; // Base case: If the matrix is 1×1, return the only element
    }
    if (n == 2)
    {
        // If the matrix is 2×2, use the direct formula
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    float determinant = 0;

    for (int col = 0; col < n; col++)
    {
        // Create a submatrix (Minor) by removing the first row and the current column
        float **subMatrix = (float **)malloc((n - 1) * sizeof(float *));
        for (int i = 0; i < n - 1; i++)
        {
            subMatrix[i] = (float *)malloc((n - 1) * sizeof(float));
        }

        // Fill the submatrix by excluding the first row and the selected column
        for (int i = 1; i < n; i++)
        {
            int subCol = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == col)
                    continue; // Skip the selected column
                subMatrix[i - 1][subCol] = matrix[i][j];
                subCol++;
            }
        }

        // Apply Laplace expansion along the first row
        float cofactor = (col % 2 == 0 ? 1 : -1) * matrix[0][col] * calculateDeterminant(subMatrix, n - 1);
        determinant += cofactor;

        // Free allocated memory for the submatrix
        for (int i = 0; i < n - 1; i++)
        {
            free(subMatrix[i]);
        }
        free(subMatrix);
    }

    return determinant;
}

float **calculateTransposeMatrix(float **mat, int rows, int cols)
{
    float **transMat = allocateMatrix(cols, rows);
    if (transMat == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            transMat[i][j] = mat[j][i];
        }
    }

    return transMat;
}
/*End Matrix Operations Section*/

/*Start Menus Section*/
void mainMenu()
{
    int choice;

    while (true)
    {
        printf("\n**** Main Menu ****\n");
        printf("1. Add Two Matrices.\n");
        printf("2. Subtract Two Matrices.\n");
        printf("3. Multiply Two Matrices\n");
        printf("4. Multiply a Matrix By a Scalar.\n");
        printf("5. Calculate Determinant.\n");
        printf("6. Calculate Transpose Matrix.\n");
        printf("7. Calculate Inverse Matrix.\n");
        printf("8. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (choice < 1 || choice > 8)
        {
            printf("Error: please enter a valid option from the menu!: ");
            scanf("%d", &choice);
        }

        switch (choice)
        {
        case 1:
            addTwoMatricesMenu();
            break;
        case 2:
            subtractTwoMatricesMenu();
            break;
        case 3:
            multiplyTwoMatricesMenu();
            break;
        case 4:
            multiplyMatrixByScalarMenu();
            break;
        case 5:
            calculateDeterminantMenu();
            break;
        case 6:
            calculateTransposeMatrixMenu();
            break;
        case 7:
            /* code */
            break;
        case 8:
            exit(0);
            break;
        }
    }
}

void addTwoMatricesMenu()
{
    int rows, cols;
    printf("\n**** Add Two Matrices ****\n");
    printf("A(n x m) + B(n x m)\n");
    getMatrixSize(&rows, &cols);
    float **A = allocateMatrix(rows, cols);
    if (A == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Fill the matrix A:\n");
    fillMatrix(A, rows, cols, 'A');

    float **B = allocateMatrix(rows, cols);
    if (B == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Fill the matrix B:\n");
    fillMatrix(B, rows, cols, 'B');

    float **C = addTwoMatrices(A, B, rows, cols);
    if (C == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    freeMatrix(&A, rows);
    freeMatrix(&B, rows);
    printf("The result:\n");
    displayMatrix(C, rows, cols);
    freeMatrix(&C, rows);
}

void subtractTwoMatricesMenu()
{
    int rows, cols;
    printf("\n**** Subtract Two Matrices ****\n");
    printf("A(n x m) - B(n x m)\n");
    getMatrixSize(&rows, &cols);
    float **A = allocateMatrix(rows, cols);
    if (A == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Fill the matrix A:\n");
    fillMatrix(A, rows, cols, 'A');

    float **B = allocateMatrix(rows, cols);
    if (B == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Fill the matrix B:\n");
    fillMatrix(B, rows, cols, 'B');

    float **C = subtractTwoMatrices(A, B, rows, cols);
    if (C == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    freeMatrix(&A, rows);
    freeMatrix(&B, rows);
    printf("The result:\n");
    displayMatrix(C, rows, cols);
    freeMatrix(&C, rows);
}

void multiplyTwoMatricesMenu()
{
    int n, m, p;
    printf("\n**** Multiply Two Matrices ****\n");
    printf("A(n x m) x B(m x p)\n");

    printf("Enter n (the number of rows of Matrix A): ");
    scanf("%d", &n);
    while (n <= 0)
    {
        printf("n must be greater than 0: ");
        scanf("%d", &n);
    }

    printf("Enter m (the number of columns of Matrix A and the number of rows of matrix B): ");
    scanf("%d", &m);
    while (m <= 0)
    {
        printf("m must be greater than 0: ");
        scanf("%d", &m);
    }

    printf("Enter p (the number of columns of Matrix B): ");
    scanf("%d", &p);
    while (p <= 0)
    {
        printf("p must be greater than 0: ");
        scanf("%d", &p);
    }

    float **A = allocateMatrix(n, m);
    if (A == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Fill the matrix A:\n");
    fillMatrix(A, n, m, 'A');

    float **B = allocateMatrix(m, p);
    if (B == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Fill the matrix B:\n");
    fillMatrix(B, m, p, 'B');

    float **C = multiplyTwoMatrices(A, B, n, m, p);
    if (C == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    freeMatrix(&A, n);
    freeMatrix(&B, m);
    printf("The result:\n");
    displayMatrix(C, n, p);
    freeMatrix(&C, n);
}

void multiplyMatrixByScalarMenu()
{
    int rows, cols;
    float k;
    printf("\n**** Subtract Two Matrices ****\n");
    printf("A(n x m) x K\n");
    getMatrixSize(&rows, &cols);
    float **A = allocateMatrix(rows, cols);
    if (A == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Fill the matrix A:\n");
    fillMatrix(A, rows, cols, 'A');

    printf("Enter the Scalar K: ");
    while (scanf("%f", &k) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n')
            ;
    }

    float **result = multiplyMatrixByScalar(A, k, rows, cols);
    if (result == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    freeMatrix(&A, rows);
    printf("The result:\n");
    displayMatrix(result, rows, cols);
    freeMatrix(&result, rows);
}

void calculateDeterminantMenu()
{
    int n;
    printf("\n**** Calculate Determinant ****\n");
    printf("Det( A(n x n) )\n");
    printf("Enter n (the size of the matrix A): ");
    scanf("%d", &n);
    while (n <= 0)
    {
        printf("n must be greater than 0: ");
        scanf("%d", &n);
    }

    float **A = allocateMatrix(n, n);
    if (A == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Fill the matrix A:\n");
    fillMatrix(A, n, n, 'A');

    double det = calculateDeterminant(A, n);
    printf("Det( A ) = %.2f\n", det);
    freeMatrix(&A, n);
}

void calculateTransposeMatrixMenu()
{
    int rows, cols;
    printf("\n**** Calculate Transpose Matrix ****\n");
    printf("Transpose( A(n x m) )\n");
    getMatrixSize(&rows, &cols);
    float **A = allocateMatrix(rows, cols);
    if (A == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Fill the matrix A:\n");
    fillMatrix(A, rows, cols, 'A');

    float **transmat = calculateTransposeMatrix(A, rows, cols);
    if (transmat == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    freeMatrix(&A, rows);
    printf("The result:\n");
    displayMatrix(transmat, cols, rows);
    freeMatrix(&transmat, cols);
}
/*End Menus Section*/