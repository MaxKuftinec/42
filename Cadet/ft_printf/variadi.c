#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0 && n != -2147483648)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		ft_putchar(48 + n);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(48 + ((unsigned int)n % 10));
	}
}

void dectohex(size_t nb, char ascii)
{    
    if (!ascii)
    {
        if (!nb)
            return (void)write(1, "(NULL)", sizeof("(NULL)"));
        else
        {
            write(1, "0x", 2 * sizeof(char));
            ascii = 87;
        }
    }
    if (nb / 16)
    {
        dectohex(nb / 16, ascii);
        if (nb % 16 >= 10)
            write(1, &(char){ascii + nb % 16}, 1);
        else
            write(1, &(char){48 + nb % 16}, 1);
    }
    else if (nb % 16 >= 10)
        write(1, &(char){ascii + nb % 16}, 1);
    else
        write(1, &(char){48 + nb % 16}, 1);
}

int foo(char *p, ...)
{
    va_list x;
    char flagnum = 0;
    char *s;
    
    va_start(x, p);
    p--;
    while (*++p)
    { 
        if ('%' == *p)
        {
            if (flagnum++, 'd' == p[sizeof(char)] || 'i' == p[sizeof(char)])
                ft_putnbr((p++, va_arg(x, int)));
            else if ('c' == p[sizeof(char)])
                write((p++, 1), &(char){va_arg(x, int)}, sizeof(char));
            else if ('p' == p[sizeof(char)])
                dectohex((p++, va_arg(x, size_t)), 0);
            else if ('x' == p[sizeof(char)])
                dectohex((p++, va_arg(x, unsigned int)), 87);
            else if ('X' == p[sizeof(char)])
                dectohex((p++, va_arg(x, unsigned int)), 55);
            else if ('%' == p[sizeof(char)])
                write((p++, 1), &(char){'%'}, sizeof(char));
            else if ('s' == p[sizeof(char)])
            {
                s = va_arg(x, char *);
                write(1, s, sizeof(char) * strlen(s));
            }
            else
                write(1, &(char){'%'}, sizeof(char));
        }
        else
            write(1, p, 1);
    }
    return (va_end(x), flagnum);
}

int main()
{
    char *p;

    printf("%p\n", p);
    foo("%p\n", p);
    p = NULL;
    printf("%p\n", 123);
    foo("%p\n", 123);

    return 0;
}
