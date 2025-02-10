#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Srart Helper Functions Section*/
void displayAsciiArt();
void getMatrixSize(int *rows, int *cols);
float **allocateMatrix(int rows, int cols);
void fillMatrix(float **mat, int rows, int cols);
void displayMatrix(float **mat, int rows, int cols);
void freeMatrix(float ***mat, int rows);
/*End Helper Functions Section*/

/*Start Matrix Operations Section*/

/*End Matrix Operations Section*/

/*Start Menus Section*/

void mainMenu();

/*End Menus Section*/

int main()
{
    displayAsciiArt();
    mainMenu();
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
            return NULL;
        }
    }

    return mat;
}

void fillMatrix(float **mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("A[%d][%d] : ", i + 1, j + 1);
            scanf("%f", &mat[i][j]);
        }
    }
}

void displayMatrix(float **mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
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
        printf("4. Multiply a Matrix By a Constant.\n");
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
            /* code */
            break;
        case 3:
            /* code */
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

/*End Menus Section*/