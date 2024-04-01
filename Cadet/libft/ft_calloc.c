/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:19:02 by asapar            #+#    #+#             */
/*   Updated: 2024/03/16 12:19:03 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;
	char	*q;
	size_t	totalsize;

	totalsize = size * nitems;
	if (nitems > 2147483647 && size > 2147483647)
		return (NULL);
	p = malloc(totalsize);
	if (!p)
		return (NULL);
	q = (char *)p;
	while (totalsize--)
		*q++ = 0;
	return (p);
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