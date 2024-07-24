/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:05:10 by asapar            #+#    #+#             */
/*   Updated: 2024/03/16 14:05:10 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
#include <stdio.h>
int main()
{
	int a = 42;
	int b = 13;
	t_list *p = ft_lstnew(&a);
	t_list *q = ft_lstnew(&b);
	printf("%d\n", *(int *)q->content);
	printf("%s\n", (char *)p->next);
	printf("%u\n", -2);
}
*/