/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:34:11 by asapar            #+#    #+#             */
/*   Updated: 2024/03/16 12:34:12 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	dst_len;
	size_t	src_len;
	int		start;

	src_len = ft_strlen(src);
	if (!dst && !size)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (size >= dst_len + 1)
	{
		len = src_len + dst_len;
		start = dst_len;
		while ((size - start - 1) && *src)
			dst[start++] = *src++;
		dst[start] = '\0';
	}
	else
		len = src_len + size;
	return (len);
}

/*
int main()
{
//	ft_strlcat("Hello", NULL, 0);
	char dest[100] = "rrrrrrrrrrrrrrr";
//	printf("%lu\n", strlcat(dest, "lorem ipsum dolor sit amet", 5));
	printf("%lu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
	printf("%s\n", dest);
}*/