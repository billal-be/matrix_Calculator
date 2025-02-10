#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printAsciiArt()
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

void mainMenu()
{
    printAsciiArt();
    int choice;

    while (true)
    {
        printf("1. Add two matrices.\n");
        printf("2. Subtract two matrices.\n");
        printf("3. Multiply two matrices\n");
        printf("4. Multiply a matrix by a constant:\n");
        printf("5. Find Determinant\n");
        printf("6. Find Transpose Matrix\n");
        printf("")
    }
}

int main()
{
    mainMenu();
}
