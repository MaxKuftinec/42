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

#include "libft.h"
#include "ft_printf.h"

t_null_ptr_representation null_ptr_rep;

void init_null_ptr_representation(void)
{
#if defined(_WIN32) || defined(_WIN64) || defined(__APPLE__)
    null_ptr_rep = NULL_PTR_0X0;
#elif defined(__linux__) || defined(__unix__)
    null_ptr_rep = NULL_PTR_NIL;
#else
    null_ptr_rep = NULL_PTR_NULL;
#endif
}

const char *null_ptr_representation_to_string(t_null_ptr_representation rep)
{
    switch (rep)
    {
        case NULL_PTR_0X0:
            return "0x0";
        case NULL_PTR_NIL:
            return "(nil)";
        case NULL_PTR_NULL:
        default:
            return "(null)";
    }
}
static void	ft_printfstrf(char *s, int *printed_char, char printchar)
{
	size_t	strlen;

	if (printchar)
		return ((void)((*printed_char)++, write(1, s, sizeof(char))));
	strlen = ft_strlen(s);
	write(1, s, strlen);
	*printed_char += strlen;
}

static void	ft_printnbrf(int n, int *printed_char, char type)
{
	if (type && n < 0)
	{
		ft_printnbrf((unsigned int)n / 10, printed_char, 0);
		ft_printfstrf((char [2]){48 + (unsigned int)n % 10}, printed_char, 42);
		return ;
	}
	if (n < 0 && n != -2147483648)
	{
		n *= -1;
		ft_printfstrf((char [2]){'-'}, printed_char, 42);
	}
	if (n >= 0 && n <= 9)
		ft_printfstrf((char [2]){48 + n}, printed_char, 42);
	else
	{
		ft_printnbrf(n / 10, printed_char, 0);
		ft_printfstrf((char [2]){48 + (unsigned int)n % 10}, printed_char, 42);
	}
}

static void	dectohex(size_t nb, char ascii, int *printed_char)
{
	if (!ascii)
	{
		if (!nb)
			return (ft_printfstrf(NULL_PTR_REPRESENTATION, printed_char, 0));
		else
		{
			ft_printfstrf("0x", printed_char, 0);
			ascii = 87;
		}
	}
	if (nb / 16)
	{
		if (dectohex(nb / 16, ascii, printed_char), nb % 16 >= 10)
			ft_printfstrf((char [2]){ascii + nb % 16}, printed_char, 42);
		else
			ft_printfstrf((char [2]){48 + nb % 16}, printed_char, 42);
	}
	else if (nb % 16 >= 10)
		ft_printfstrf((char [2]){ascii + nb % 16}, printed_char, 42);
	else
		ft_printfstrf((char [2]){48 + nb % 16}, printed_char, 42);
}

void	flag(const char *p, va_list x, int *printed_char)
{
	char	*s;

	if ('d' == p[1] || 'i' == p[1])
		ft_printnbrf(va_arg(x, int), printed_char, 0);
	else if ('u' == p[1])
		ft_printnbrf(va_arg(x, unsigned int), printed_char, 42);
	else if ('c' == p[1])
		ft_printfstrf((char [2]){va_arg(x, int)}, printed_char, 42);
	else if ('p' == p[1])
		dectohex(va_arg(x, size_t), 0, printed_char);
	else if ('x' == p[1])
		dectohex(va_arg(x, unsigned int), 87, printed_char);
	else if ('X' == p[1])
		dectohex(va_arg(x, unsigned int), 55, printed_char);
	else if ('%' == p[1])
		ft_printfstrf((char [2]){'%'}, printed_char, 42);
	else if ('s' == p[1])
	{
		s = va_arg(x, char *);
		if (!s)
			ft_printfstrf("(null)", printed_char, 0);
		else
			ft_printfstrf(s, printed_char, 0);
	}
}

int	ft_printf(const char *p, ...)
{
	va_list	x;
	int		printed_char;

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
