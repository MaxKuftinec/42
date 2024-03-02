#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*src2;

	src2 = src;
	while (--dstsize && *src2)
		*dst++ = *src2++;
	*dst = '\0';
	return (ft_strlen(src));
}

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	int	start;
		
	if (size > ft_strlen(dst) + 1)
	{
		len = ft_strlen(src) + ft_strlen(dst);
		start = ft_strlen(dst) + 1;
		while((size - start) && *src)
			dst[start++] = *src++;
		dst[start] = '\0';
	}
	else
		len = ft_strlen(src) + size;
	return (len);	
}
