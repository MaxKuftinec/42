/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:15:59 by asapar            #+#    #+#             */
/*   Updated: 2024/03/16 12:15:59 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

size_t  ft_strlen(char *s)
{
    size_t  i;

    i = 0;
    while (*s++)
        i++;
    return (i);
}

static void	ft_printcharf(char c, int *printed_char)
{
	((*printed_char)++, write(1, &c, sizeof(char)));
}

static void	ft_printfstrf(char *s, int *printed_char)
{
	size_t	strlen;

	strlen = ft_strlen(s);
	write(1, s, sizeof(char) * strlen);
	*printed_char += strlen;
}

static void	ft_printnbrf(int n, int *printed_char)
{
	if (n < 0 && n != -2147483648)
		(n *= -1, ft_printcharf('-', printed_char));
	if (n >= 0 && n <= 9)
		ft_printcharf(48 + n, printed_char);
	else
    {
        ft_printnbrf(n / 10, printed_char);
		ft_printcharf(48 + ((unsigned int)n % 10), printed_char);
    }
}

static void dectohex(size_t nb, char ascii, int *printed_char)
{    
    if (!ascii) // Subject to change for different platform
    {
        if (!nb)
            return (ft_printfstrf("(null)", printed_char));
        else
        {
        	ft_printfstrf("0x", printed_char);
            ascii = 87;
        }
    }
    if (nb / 16)
    {
        if (dectohex(nb / 16, ascii, printed_char), nb % 16 >= 10)
            ft_printcharf(ascii + nb % 16, printed_char);
        else
        	ft_printcharf(48 + nb % 16, printed_char);
    }
    else if (nb % 16 >= 10)
        ft_printcharf(ascii + nb % 16, printed_char);
    else
        ft_printcharf(48 + nb % 16, printed_char);
}

void	flag(const char *p, va_list x, int *printed_char) // Not efficient to make var in flag because we have to process vars once again
{
	char	*s;

	if ('d' == p[sizeof(char)] || 'i' == p[sizeof(char)])
		ft_printnbrf(va_arg(x, int), printed_char);
	else if ('c' == p[sizeof(char)])
		ft_printcharf(va_arg(x, int), printed_char);
	else if ('p' == p[sizeof(char)])
		dectohex(va_arg(x, size_t), 0, printed_char);
	else if ('x' == p[sizeof(char)])
		dectohex(va_arg(x, unsigned int), 87, printed_char);
	else if ('X' == p[sizeof(char)])
		dectohex(va_arg(x, unsigned int), 55, printed_char);
	else if ('%' == p[sizeof(char)])
		ft_printcharf('%', printed_char);
	else if ('s' == p[sizeof(char)])
	{
 	   s = va_arg(x, char *);
		if (!s)
			ft_printfstrf("(null)", printed_char);
		else
			ft_printfstrf(s, printed_char);
	}
}

int ft_printf(const char *p, ...)
{
	va_list x;
	int	printed_char;

	printed_char = 0;	
	(va_start(x, p), p--);
	while (*++p)
	{
		if ('%' == *p)
			flag(p++, x, &printed_char);
		else
			write((printed_char++, 1), p, sizeof(char));
	}
	return (va_end(x), printed_char);
}

int main()
{
	char	*p;
	char	*s = "My name is Jeff!";
	int nb;

	printf("%d\n", printf("Hello world!\n"));
	ft_printf("%d\n", ft_printf("Hello world!\n"));


	printf("\n");
	printf("%d\n", printf("%d\n", 2147483647));
	ft_printf("%d\n", ft_printf("%d\n", 2147483647));

	printf("\n");
	printf("%d\n", printf("%i\n", -2147483648));
	ft_printf("%d\n", ft_printf("%i\n", 2147483648));

	printf("\n");
	printf("%i\n", printf("%i\n", -2147483648));
	ft_printf("%i\n", ft_printf("%i\n", -2147483648));

	printf("\n");
	printf("%d\n", printf("%c\n", 97));
	ft_printf("%d\n", ft_printf("%c\n", 97));

	printf("\n");
	printf("%d\n", printf("%p\n", p));
	ft_printf("%d\n", ft_printf("%p\n", p));

	printf("\n");
	printf("%d\n", printf("%p\n", &p));
	ft_printf("%d\n", ft_printf("%p\n", &p));

	p = 0;
	printf("\n");
	printf("%d\n", printf("%p\n", p));
	ft_printf("%d\n", ft_printf("%p\n", p));

	printf("\n");
	printf("%d\n", printf("%x\n", 2147483648));
	ft_printf("%d\n", ft_printf("%x\n", 2147483648));

	printf("\n");
	printf("%d\n", printf("%X\n", 2147483647));
	ft_printf("%d\n", ft_printf("%X\n", 2147483647));

	printf("\n");
	printf("%d\n", printf("Hello %s\n", "world!"));
	ft_printf("%d\n", ft_printf("Hello %s\n", "world!"));

	printf("\n");
	printf("%d\n", printf("Hello %s\n", NULL));
	ft_printf("%d\n", ft_printf("Hello %s\n", NULL));

	printf("\n");
	printf("%d\n", printf("%%\n"));
	ft_printf("%d\n", ft_printf("%%\n"));

	printf("\n");
	printf("%d\n", printf("%%%%\n"));
	ft_printf("%d\n", ft_printf("%%%%\n"));

	printf("\n");
	printf("%d\n", printf("%%%%%%\n"));
	ft_printf("%d\n", ft_printf("%%%%%%\n"));

	printf("\n");
	printf("%d\n", printf("%s\n", s));
	ft_printf("%d\n", ft_printf("%s\n", s));
	return 0;
}
