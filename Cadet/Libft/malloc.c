#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int *)malloc(10 * sizeof(int));
    for (size_t i = 0; i < 10; i++)
        p[i] = i;
    free(p);
    int *q = (int *)calloc(10, sizeof(int));
    for(int i = 0; i < 10; i++)
        printf("%d\n", q[i]);
    free(q);
    printf("%p\n", p);
    printf("%p\n", q);
    return (0);
}