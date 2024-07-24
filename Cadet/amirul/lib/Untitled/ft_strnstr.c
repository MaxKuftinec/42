/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:38:28 by asapar            #+#    #+#             */
/*   Updated: 2024/03/16 12:38:29 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!len && *needle)
		return (NULL);
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && i + j < len
				&& haystack[i + j] != '\0' && needle[j] != '\0')
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

/*
"if (needle == NULL || haystack == NULL || needle[0] == '\0')" Tried 
thisbefore, but doesn't work because shouldn't handle NULL

#include <string.h>
int main()
{
//	printf("%s\n", ft_strnstr(NULL, "fake", 0));
	printf("%s\n", strnstr("lorem ", "dolor", 0));
}*/