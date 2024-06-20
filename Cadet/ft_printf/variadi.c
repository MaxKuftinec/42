#include <stdio.h>
#include <stdarg.h>

int sum(int n, ...)
{
    va_list x;
    int sum = 0;
    va_start(x, n);
    for(int i = 0; i < n; i++)
        sum += va_arg(x, int);
    return (va_end(x), sum);
}

int main()
{
    printf("%d\n", sum(3, 42, 13, 123 ,123 ,123));
    return 0;
}
