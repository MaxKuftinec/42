#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char *begin;

	begin = (char *)s;
	while (*s)
		s++;
	return (s - begin);
}
