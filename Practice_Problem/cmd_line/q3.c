#include<stdio.h>
#include<stdlib.h>

/*Practice Problem: Write a program that prompts the user for a number n. It then proceeds to read an n*n array of
integers, inputted row by row. After reading the array, it prints the row sums 
(i.e., each row has a sum which is the sum of all the elements in this row),
the column sums (i.e., each column has a sum which
is the sum of all elements in this column), and a diagonal sum 
(which is the sum of all elements on the diagonal)*/

int** array_input(int n){
    int** arr = malloc(n * sizeof(int*));

    if(!arr){
        printf("Initialization fails.\n");
        return NULL;
    }

    for(int i = 0; i < n; ++i){
        arr[i] = malloc(n * sizeof(int));

        if(!arr[i]){
            printf("Initialization failure.\n");
            return NULL;
        }
    }

    for(int i = 0; i < n; ++i){
        printf("Enter row %d: ", i+1);

        for(int j = 0; j < n; ++j)
            scanf("%d", &arr[i][j]);
    }

    return arr;
}

void sum_cal(int** arr, int* row_sum, int* column_sum, int* diagonal_sum, int size){

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            row_sum[i] += arr[i][j];

            column_sum[j] += arr[i][j];

            if(i == j) *diagonal_sum += arr[i][j];
        }
    }
}

int main(){
    printf("Enter a number n which is the size of a n*n array: ");

    int n;

    scanf("%d", &n);

    //Don't use scanf("%d\n", &n) here since there may leave an extra newline
    //which may cause unexpected behavior when scanf("%d", &arr[i][j]);
    //is called in the int** array_input function

    int** arr = array_input(n);

    int row_sum[n], column_sum[n];

    int diagonal_sum = 0;

    for(int i = 0; i < n; ++i){
        row_sum[i] = 0;
        column_sum[i] = 0;
    }

    sum_cal(arr, row_sum, column_sum, &diagonal_sum, n);

    printf("\n");

    printf("Row totals: ");

    for(int i = 0; i < n; ++i)
        printf("%d ", row_sum[i]);

    printf("\n");

    printf("Column totals: ");

    for(int i = 0; i < n; ++i)
        printf("%d ", column_sum[i]);

    printf("\n");

    printf("Diagonal total: %d", diagonal_sum);

    printf("\n");

    for(int i = 0; i < n; ++i)
        free(arr[i]);

    free(arr);

    return 0;
}