# dynamic-arrays-c

# Include header:
```C
#include "array.h"
```

# Usage:
```C
int *arr1 = NULL;
array_initialize(&arr1, 5, sizeof(int));

for (int i = 0; i < 10; i++)
{
    int num = i + 1;
    array_push_back(&arr1, &num);
}

while (1)
{
    int len = array_length(&arr1);
    if (len == 0)
        break;
    printf("val: %d\n", arr1[len - 1]);
    array_pop_back(&arr1);
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