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
/*End Matrix Operations Section*/

/*Start Menus Section*/
void addTwoMatricesMenu();
void subtractTwoMatricesMenu();
void multiplyTwoMatricesMenu();
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
                while (getchar() != '\n'); // Clear input buffer
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
        printf("Memory allocation failed!\n");
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
        printf("Memory allocation failed!\n");
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
        printf("Memory allocation failed!\n");
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
        printf("5. Find Determinant.\n");
        printf("6. Find Transpose Matrix.\n");
        printf("7. Find Inverse Matrix.\n");
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
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
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
/*End Menus Section*/