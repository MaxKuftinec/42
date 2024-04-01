/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:05:02 by asapar            #+#    #+#             */
/*   Updated: 2024/03/17 03:05:03 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
What "*lst = new" for?
What about "lst = &new"
Apparently, setting "lst = &new" leads to sigsegv. Why?
Answered. Doing "lst = &new" only changes the local copy of the variable in 
this function. That particular syntax is function scoped.
*lst means the address of the very first element that the first node points to

#include <stdio.h>

static void del_content(void *content)
{
    free(content);
}

int main()
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	int		i;

	printf("Address of both pointer   : %p - %p\n", &a, &b);
	printf("Address that they point to: %p - %p\n", a, b);
	printf("Creating nodes...\n");
	
	a = ft_lstnew("4");
	b = ft_lstnew("2");
	c = ft_lstnew("-");

	printf("Value of each node (a): %s - %s\n", a->content, a->next);
	printf("Value of each node (b): %s - %s\n", b->content, b->next);

	printf("After creation...\n");
	printf("Address of both pointer   : %p - %p\n", &a, &b);
	printf("Address that they point to: %p - %p\n", a, b);
	printf("Address of their content %p(a) - %p(b)\n", a->content, b->content);
	printf("Size of t_list: %zu\n", sizeof(t_list));

	printf("Inserting b before a...\n");

	ft_lstadd_front(&b, a);
	printf("Insertion completed...\n");
	printf("Address of both pointer   : %p - %p\n", &a, &b);
	printf("Address that they point to: %p - %p\n", a, b);

	ft_lstadd_front(&a, c);
	printf("2nd Insertion completed...\n");
	printf("Address of both pointer   : %p - %p\n", &a, &c);
	printf("Address that they point to: %p - %p\n", a, c);

	printf("Value of node: %s%p\n", a->content, a->next);

	c = &c->content;
	i = 1;
	while (c)
	{
		printf("%s\n", c->content);
		c = c->next;
		printf("Length of list: %d\n", i++);
	}
	printf("Creating a node and deleting it\n");
	t_list *elem = ft_lstnew("Hello");
	printf("Address %p - %p - %p - %p\n", elem->content, elem, &elem, *elem);
	del_content(elem);
	//ft_lstdelone(elem, del_content);
	printf("%s - %p\n", elem->content, elem);
}*/