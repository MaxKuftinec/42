#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *ft_calloc(size_t nitems, size_t size)
{
   void *p = malloc(nitems * size);
   void *q = p;
   while (size * nitems--)
   {
       printf("Check\n");
       *(char *)q++ = 0;
   }
   return (p);
}

int main()
{
    int *p = (int *) malloc(10 * sizeof(int));
    for(int i = 0; i <= 10; i++)
        p[i] = i;
    free(p);
    int *q = (int *) ft_calloc(10, sizeof(int));
    for(int i = 0; i <= 10; i++)
        printf("%d\n", q[i]);
    free(q);
    printf("%p\n", p);
    printf("%p\n", q);
    return 0;
}