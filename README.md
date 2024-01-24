# dynamic-arrays-c

# Usage:
```C
    int *arr1 = NULL;
    array_initialize(&arr1, 5, sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        int num = i + 1;
        array_push_back(&arr1, &num);
    }
```

```C
    double *arr2 = NULL;
    array_initialize(&arr2, 10, sizeof(double));

    for (int i = 0; i < 10; i++)
    {
        double num = i + 1.5;
        array_push_back(&arr2, &num);
    }
```