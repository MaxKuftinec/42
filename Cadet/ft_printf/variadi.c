#include <stdio.h>
#include <stdarg.h>

int foo(char *p, ...)
{
    va_list x;
    char flagnum = 0;
    
    va_start(x, p);
    p--;
    while (*++p)
    { 
        if ('%' == *p)
        {
            if (flagnum++, 100 == p[sizeof(char)])
                ft_putnbr((p++, va_arg(x, int)));
            else if (99 == p[sizeof(char)])
                write((p++, 1), &(char){va_arg(x, int)}, sizeof(char));
            else if ('%' == p[sizeof(char)])
                write((p++, 1), &(char){'%'}, sizeof(char));
            else if ('p' == p[sizeof(char)])
                dectohex((p++, va_arg(x, size_t)));
        }
        else
            write(1, p, 1);
    }
    return (va_end(x), flagnum);
}

int main()
{
    printf("%d\n", foo("%d%d%d%d", 1, 2, 3, 4));

    return 0;
}
