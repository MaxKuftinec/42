/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 06:03:58 by asapar            #+#    #+#             */
/*   Updated: 2024/03/16 06:03:59 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alloc(const char *s)
{
	return (malloc((ft_strlen(s) + 1) * sizeof(char)));
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	str = ft_alloc(s);
	if (!str)
		return (NULL);
	while (*s)
		*str++ = f(i++, *s++);
	*str = 0;
	return (str - i);
}
