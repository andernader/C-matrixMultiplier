#include <stdio.h>

int main(){
    int ar1_row, ar1_col;
    int ar2_row, ar2_col;
    char temp;
    char againChar;

    printf("                          Matrix Multiplier\n");
    printf("                    Ammar Mullaoglu - %s\n", __DATE__);
    for(int i = 0; i < 75; i++){
        printf("_");
    }
    printf("\n\n\n");

    program_start:
    printf("Enter the matrices's dimensions in the forum row*col ex. 2*3 :\n");

    scanf1:
    printf("Matrix A = ");

    if(scanf("%d%c%d", &ar1_row, &temp, &ar1_col) != 3 || temp != '*'){
        printf("\nInvalid input! Try again!\n");
        while(getchar() != '\n');
        goto scanf1;
    }
    while(getchar() != '\n');

    scanf2:
    printf("Matrix B = ");
    if(scanf("%d%c%d", &ar2_row, &temp, &ar2_col) != 3 || temp != '*'){
        printf("\nInvalid input! Try again!\n");
        while(getchar() != '\n');
        goto scanf2;
    }
    while(getchar() != '\n');

    if(ar1_col != ar2_row){
        printf("\nInvalid input! The columns number in Matrix A must equal the rows number in Matrix B!\n");
        goto scanf1;
    }

    int ar1[ar1_row][ar1_col];
    int ar2[ar2_row][ar2_col];
    int result[ar1_row][ar2_col];

    //continue here!
    printf("\nEnter Matrix A's elements :\n");
    for(int i = 0; i < ar1_row; i++){
        for(int j = 0; j < ar1_col; j++)
            arrACheck:
            if(scanf("%d", &ar1[i][j]) != 1){
                printf("Invalid input! Enter arrays values starting from arr[%d][%d] again!\n", i, j);
                while(getchar() != '\n');
                goto arrACheck;
            }
    }
    while(getchar() != '\n');

    printf("\nEnter Matrix B's elements :\n");
    for(int i = 0; i < ar2_row; i++){
        for(int j = 0; j < ar2_col; j++)
            arrBCheck:
            if(scanf("%d", &ar2[i][j]) != 1){
                printf("Invalid input! Enter arrays values starting from arr[%d][%d] again!\n", i, j);
                while(getchar() != '\n');
                goto arrBCheck;
            }
    }
    while(getchar() != '\n');
    /////////////////////////////////////////////////////////////////////////////
    printf("\nResult Matrix: \n");
    for(int i = 0; i < ar1_row; i++){
        for(int j = 0; j < ar2_col; j++){
            result[i][j] = 0;
            for(int k = 0; k < ar1_col; k++){
                result[i][j] += ar1[i][k] * ar2[k][j];
            }
            printf("%02d ", result[i][j]);
        }
        printf("\n");
    }

    again:
    printf("\nStart again? y or n : ");
    if(scanf("%c", &againChar) != 1){
        printf("Invalid input! Enter y or n only!\n");
        while(getchar() != '\n');
        goto again;
    }

    if(againChar != 'y' && againChar != 'n'){
        printf("Invalid input! Enter y or n only!\n");
        while(getchar() != '\n');
        goto again;
    }

    while(getchar() != '\n');

    if(againChar == 'y'){
        printf("\n\n");
        goto program_start;
    }

    return 0;
}
