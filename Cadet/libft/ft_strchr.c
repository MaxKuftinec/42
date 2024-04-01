/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:34:52 by asapar            #+#    #+#             */
/*   Updated: 2024/03/16 12:34:52 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s - (char)c))
		s++;
	if (*s != (char)c)
		return (NULL);
	return ((char *)s);
}

/*#include <string.h> Typecasted every occurence of c to char. This is important
#include <stdio.h>
int main()
{
//	char a = -42;
//	int b = 0;
//	printf("%d\n", b - a);
	char *s = ft_strchr("abcdef", 'a' + 256);
	printf("%s\n", s);
}*/