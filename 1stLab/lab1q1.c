// q1. write a c program to swap content of 2 variables using function and pointers. (25-07-2023)

#include <stdio.h>
#include <math.h>

void swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

int main()
{
    int a, b;
    printf("Enter the values for x and y:\n");
    scanf("%d %d", &a, &b);
    printf("\nBefore swapping, the values are : a = %d and b = %d", a, b);
    swap(&a, &b);
    printf("\nAfter swapping, the values are: a = %d and b = %d ", a, b);
    return 0;
}