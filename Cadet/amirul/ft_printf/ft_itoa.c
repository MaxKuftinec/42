/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 05:26:22 by asapar            #+#    #+#             */
/*   Updated: 2024/03/16 05:26:23 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*alloc_assign(int i, int n)
{
	int		case_zero;
	char	*p;

	case_zero = 0;
	p = malloc(i * sizeof(char));
	if (!p)
		return (NULL);
	p[--i] = 0;
	while (i)
	{
		if (i == 1 && n == 0 && case_zero != 0)
		{
			p[--i] = '-';
			break ;
		}
		p[--i] = 48 + (n % 10);
		n /= 10;
		case_zero++;
	}
	return (p);
}

static char	*special_case(int n)
{
	char	*p;
	int		i;

	p = malloc(12 * sizeof(char));
	if (!p)
		return (NULL);
	i = 10;
	n = 147483648;
	p[0] = '-';
	p[1] = '2';
	p[11] = 0;
	while (i != 1)
	{
		p[i--] = 48 + (n % 10);
		n /= 10;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*p;

	i = 1;
	if (n == -2147483648)
	{
		p = special_case(n);
		return (p);
	}
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	j = n;
	while (++i, j >= 10)
		j /= 10;
	p = alloc_assign(i, n);
	if (!p)
		return (NULL);
	return (p);
}

/*
I is started from 1, that way we reserve space for null terminator
Refer to how p was allocated
*/
