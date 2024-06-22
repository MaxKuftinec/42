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

/*
int foo(char *p, ...)
{
    va_list x;
    int i = 0;
    int num_of_flag = 0;
    int sum = 0;
    
    while(p[i])
        if (p[i++] = '%')
            num_of_flag++;
    printf("%d\n", num_of_flag);
    va_start(x, p);
    for(int i = 0; i < num_of_flag; i++)
        sum += va_arg(x, int);
    return (va_end(x), sum);
}

int main()
{
    printf("%d\n", foo("%d%d%d%d", 1, 2, 3, 4));

    return 0;
}
*/
