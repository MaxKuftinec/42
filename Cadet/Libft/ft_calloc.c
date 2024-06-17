#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;

	if (nitems > 2147483647 && size > 2147483647)
		return (NULL);
	p = malloc(size * nitems);
	if (!p)
		return (NULL);
	return (ft_bzero(p, size * nitems), p);
}

/*
#include <stdio.h>
int main()
{
	char *p = ft_calloc(-5, 3);
	printf("%s\n%p", p, p);
}
Test cases:
1) ft_calloc(0, -ve) or ft_calloc(-ve, 0) returns a pointer to some address. 
Does not return null and did perform malloc(0) and malloc(0) does not return 
null*/
