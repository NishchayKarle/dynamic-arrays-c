#include <stdio.h>
#include "array.h"

int main()
{
    int *arr1 = NULL;
    array_initialize(&arr1, 5, sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        int num = i + 1;
        array_push_back(&arr1, &num);
    }

    unsigned int len = array_length(&arr1);
    for (int i = 0; i < len; i++)
        printf("i: %d, val: %d\n", i, arr1[i]);

    printf("----------\n");
    array_clear(&arr1);
    for (int i = 0; i < 5; i++)
    {
        int num = i + 1;
        array_push_back(&arr1, &num);
    }

    len = array_length(&arr1);
    for (int i = 0; i < len; i++)
        printf("i: %d, val: %d\n", i, arr1[i]);

    printf("----------\n");

    double *arr2 = NULL;
    array_initialize(&arr2, 10, sizeof(double));
    for (int i = 0; i < 10; i++)
    {
        double num = i + 1.5;
        array_push_back(&arr2, &num);
    }

    len = array_length(&arr2);
    for (int i = 0; i < len; i++)
        printf("i: %d, val: %lf\n", i, arr2[i]);

    array_free(&arr1);
    array_free(&arr2);

    return 0;
}