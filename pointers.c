#include <stdio.h>
#include <stdlib.h>

/* There is no function overloading in C */
/* There is function overlading in C++ */
/* Return type is not a function signature */

void allocate(int ** p)
{
    *p = (int*)malloc(sizeof(int));
}

void allocate2(int *p)
{
    p = (int*)malloc(sizeof(int));
}

/* Function to demonstrate VLAs - Variable Length Arrays */
void arrayFunction(int x)
{
    int arr[x];
}

int* sum(){int *x = NULL; return x;}    /* Function returning pointer to an int */
int (*sum2);                            /* Pointer to a function */
void funcX(int x, int*(*y)()){}         /* Function taking an int and a function pointer as parameters */

int main()
{

    funcX(2, sum);      /* 2nd argument is a pointer to function sum */
    arrayFunction(10);

    int x = 5;
    int * y = &x;
    int ** z = &y;
    int *** k = &z;

    printf("%d\n", x);
    printf("%d\n", *y);
    printf("%d\n", **z);
    printf("%d\n", ***k);

    int *p = NULL;
    allocate(&p);
    if(p == NULL)
        printf("p is still NULL\n");
    else
        printf("p is not NULL\n");
    *p = 42;
    free(p);
    p = NULL;

    /* There is memory leak here.  */
    allocate2(p);
    if(p == NULL)
        printf("p is still NULL\n");
   

    /* 2D Matrix Allocations with malloc */
    int row = 5, column = 5;
    int * matrix2D = (int *) malloc(row * column * sizeof(int));
    free(matrix2D);

    return 0;
}
