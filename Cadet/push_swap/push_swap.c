#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(char *)s++ = 0;
}
/*
Return 0 means no difference
*/
int	ft_bfrncmp(const char *bfr1, const char *bfr2, size_t n)
{
	while (n)
	{
		if (n--, *bfr1 == *bfr2)
			(bfr1++, bfr2++);
		else
			return ((unsigned char)*bfr1 - (unsigned char)*bfr2);
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dest;
	char	*to;
	char	*from;

	to = (char *) dst;
	from = (char *) src;
	dest = dst;
	if (!dest && !src)
		return (dest);
	if (dst - src > 0)
		while (len--)
			to[len] = from[len];
	else
		while (len--)
			*(char *)dst++ = *(char *)src++;
	return (dest);
}
/*
'size' must be in bytes and would be called with the size of a stack, not total
*/
char	*append_list(char **next, char *permutation, size_t size)
{
	char	*head;

	head = malloc(2 * (size + sizeof(char *)));
	*next = head;
	*(char **)head = NULL;
	ft_memmove(head + sizeof(char *), permutation, 2 * size);

	return (head);
}

char	swap(int *num1, int *num2, int elements)
{
	// If elements is nonzero, the if statement executes. This logic ensures that
	// swap rule always work. If there is only 1 number in a stack, swap won't execute
	if (elements)
		while (elements--)
		{
			if (!elements)
				return (0);
			if (*num1++ && *num1--)
			{
				num2 = num1 + 1;
				break ; // Always break with size > 0
			}
		}
	*num1 = *num1 ^ *num2;
	*num2 = *num1 ^ *num2;
	*num1 = *num1 ^ *num2;
	return (42);
}

char	rotate(int stack[], int elements)
{
	while (elements--)
	{
		if (!elements)
			return (0);
		if (*stack++ && *stack--)
			while (elements)
				swap(stack + elements--, stack, 0);
	}
	return (42);
}

char	rev_rotate(int stack[], int elements)
{
	while (elements--)
	{
		if (!elements)
			return (0);
		if (*stack++ && *stack--)
			while (elements)
				(swap(stack, stack + elements--, 0), stack++);
	}
	return (42);
}

char	push(int dst[], int src[], int elements)
{
	while (elements--)
		if (*src++)
			return (swap(dst + elements, src - 1, 0));
	return (0);
}

char	sorted(int *permutation, int elements)
{
	while (--elements)
		if (*permutation > permutation[1] || !*permutation++)
			return (0);
	return (42);
}
/*
linked_list has to be passed from the very first node
size must be in bytes and would be called with the size of a stack, not total
*/
char	permutation_check(const char *linked_list, char *permutation, size_t size, char *unsolved)
{
	// This function will traverse the linked_list to check if the generated combination
	// has been generated prior or not

	if (sorted((int *)permutation, size / sizeof(int)))
	{
		printf("The solution permutation has been found!\n");
		return (ft_bzero(unsolved, 1), 42);
	}
	while (linked_list)
	{
		if (!ft_bfrncmp(linked_list + sizeof(char *), permutation, 2 * size))
			return (0);
		linked_list = *(char **)linked_list;
	}
	return (42);
}
/*size must be in bytes and would be called with the size of a stack, not total*/
char	*generation(char *linked_list, char *head, size_t size)
{
	int		elements = size / sizeof(int);
	char	*parsed_stack = malloc(2 * size);
	char	*traverse = linked_list;
	char	unsolved = 42;

	while (unsolved) // Could put unsolved && traverse to avoid infinite loop
	{
		ft_memmove(parsed_stack, traverse + sizeof(char *), 2 * size);
		if (unsolved && swap((int *)parsed_stack, NULL, elements))
		{
			if (permutation_check(linked_list, parsed_stack, size, &unsolved))
			{
				head = append_list((char **)head, parsed_stack, size);
				*(char **)(head + sizeof(char *) + 2 * size) = traverse;
			}
			swap((int *)parsed_stack, NULL, elements);
		}
		if (unsolved && swap((int *)parsed_stack + elements, NULL, elements))
		{
			if (permutation_check(linked_list, parsed_stack, size, &unsolved))
			{
				head = append_list((char **)head, parsed_stack, size);
				*(char **)(head + sizeof(char *) + 2 * size) = traverse;
			}
			swap((int *)parsed_stack + elements, NULL, elements);
		}
		if (unsolved)
		{
			(swap((int *)parsed_stack, NULL, elements), swap((int *)parsed_stack + elements, NULL, elements));
			if (permutation_check(linked_list, parsed_stack, size, &unsolved))
			{
				head = append_list((char **)head, parsed_stack, size);
				*(char **)(head + sizeof(char *) + 2 * size) = traverse;
			}
			(swap((int *)parsed_stack, NULL, elements), swap((int *)parsed_stack + elements, NULL, elements));
		}
		if (unsolved && rotate((int *)parsed_stack, elements))
		{
			if (permutation_check(linked_list, parsed_stack, size, &unsolved))
			{
				head = append_list((char **)head, parsed_stack, size);
				*(char **)(head + sizeof(char *) + 2 * size) = traverse;
			}
			rev_rotate((int *)parsed_stack, elements);
		}
		if (unsolved && rotate((int *)(parsed_stack + size), elements))
		{
			if (permutation_check(linked_list, parsed_stack, size, &unsolved))
			{
				head = append_list((char **)head, parsed_stack, size);
				*(char **)(head + sizeof(char *) + 2 * size) = traverse;
			}
			rev_rotate((int *)(parsed_stack + size), elements);
		}
		if (unsolved)
		{
			(rotate((int *)parsed_stack, elements), rotate((int *)(parsed_stack + size), elements));
			if (permutation_check(linked_list, parsed_stack, size, &unsolved))
			{
				head = append_list((char **)head, parsed_stack, size);
				*(char **)(head + sizeof(char *) + 2 * size) = traverse;
			}
			(rev_rotate((int *)parsed_stack, elements), rev_rotate((int *)(parsed_stack + size), elements));
		}
		if (unsolved && rev_rotate((int *)parsed_stack, elements))
		{
			if (permutation_check(linked_list, parsed_stack, size, &unsolved))
			{
				head = append_list((char **)head, parsed_stack, size);
				*(char **)(head + sizeof(char *) + 2 * size) = traverse;
			}
			rotate((int *)parsed_stack, elements);
		}
		if (unsolved && rev_rotate((int *)(parsed_stack + size), elements))
		{
			if (permutation_check(linked_list, parsed_stack, size, &unsolved))
			{
				head = append_list((char **)head, parsed_stack, size);
				*(char **)(head + sizeof(char *) + 2 * size) = traverse;
			}
			rotate((int *)(parsed_stack + size), elements);
		}
		if (unsolved)
		{
			(rev_rotate((int *)parsed_stack, elements), rev_rotate((int *)(parsed_stack + size), elements));
			if (permutation_check(linked_list, parsed_stack, size, &unsolved))
			{
				head = append_list((char **)head, parsed_stack, size);
				*(char **)(head + sizeof(char *) + 2 * size) = traverse;
			}
			(rotate((int *)parsed_stack, elements), rotate((int *)(parsed_stack + size), elements));
		}
		if (unsolved && push((int *)(parsed_stack + size), (int *)parsed_stack, elements))
		{
			if (permutation_check(linked_list, parsed_stack, size, &unsolved))
			{
				head = append_list((char **)head, parsed_stack, size);
				*(char **)(head + sizeof(char *) + 2 * size) = traverse;
			}
			push((int *)parsed_stack, (int *)(parsed_stack + size), elements);
		}
		if (unsolved && push((int *)parsed_stack, (int *)(parsed_stack + size), elements))
		{
			if (permutation_check(linked_list, parsed_stack, size, &unsolved))
			{
				head = append_list((char **)head, parsed_stack, size);
				*(char **)(head + sizeof(char *) + 2 * size) = traverse;
			}
			push((int *)(parsed_stack + size), (int *)parsed_stack, elements);
		}
		traverse = *(char **)traverse;
	}
	return (free(parsed_stack), head);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*strassign;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (str);
	strassign = str;
	while (*s1)
		*strassign++ = *s1++;
	while (*s2)
		*strassign++ = *s2++;
	*strassign = 0;
	return (str);
}

void	instruction(char *parent, size_t size)
{
	char	*child = malloc(2 * size);
	char	*ins_str = malloc(1);
	char	*ins_free = ins_str;
	int		elements = size / sizeof(int);

	ft_bzero(ins_str, 1);
	ft_memmove(child, parent + sizeof(char *), 2 * size);
	while (*(char **)(parent + sizeof(char *) + 2 * size))
	{
		parent = *(char **)(parent + sizeof(char *) + 2 * size);
		if (swap((int *)child, NULL, elements))
		{
			if (!ft_bfrncmp(parent + sizeof(char *), child, 2 * size))
			{
				ins_str = ft_strjoin("sa\n", ins_str);
				free(ins_free);
				ins_free = ins_str;
				continue;
			}
			swap((int *)child, NULL, elements);
		}
		if (swap((int *)child + elements, NULL, elements))
		{
			if (!ft_bfrncmp(parent + sizeof(char *), child, 2 * size))
			{
				ins_str = ft_strjoin("sb\n", ins_str);
				free(ins_free);
				ins_free = ins_str;
				continue;
			}
			swap((int *)child + elements, NULL, elements);
		}
		(swap((int *)child, NULL, elements), swap((int *)child + elements, NULL, elements));
		if (!ft_bfrncmp(parent + sizeof(char *), child, 2 * size))
		{
			ins_str = ft_strjoin("ss\n", ins_str);
			free(ins_free);
			ins_free = ins_str;
			continue;
		}
		(swap((int *)child, NULL, elements), swap((int *)child + elements, NULL, elements));
		if (rotate((int *)child, elements))
		{
			if (!ft_bfrncmp(parent + sizeof(char *), child, 2 * size))
			{
				ins_str = ft_strjoin("rra\n", ins_str);
				free(ins_free);
				ins_free = ins_str;
				continue;
			}
			rev_rotate((int *)child, elements);
		}
		if (rotate((int *)(child + size), elements))
		{
			if (!ft_bfrncmp(parent + sizeof(char *), child, 2 * size))
			{
				ins_str = ft_strjoin("rrb\n", ins_str);
				free(ins_free);
				ins_free = ins_str;
				continue;
			}
			rev_rotate((int *)(child + size), elements);
		}
		(rotate((int *)child, elements), rotate((int *)(child + size), elements));
		if (!ft_bfrncmp(parent + sizeof(char *), child, 2 * size))
		{
			ins_str = ft_strjoin("rrr\n", ins_str);
			free(ins_free);
			ins_free = ins_str;
			continue;
		}
		(rev_rotate((int *)child, elements), rev_rotate((int *)(child + size), elements));
		if (rev_rotate((int *)child, elements))
		{
		if (!ft_bfrncmp(parent + sizeof(char *), child, 2 * size))
		{
			ins_str = ft_strjoin("ra\n", ins_str);
			free(ins_free);
			ins_free = ins_str;
			continue;
		}
			rotate((int *)child, elements);
		}
		if (rev_rotate((int *)(child + size), elements))
		{
			if (!ft_bfrncmp(parent + sizeof(char *), child, 2 * size))
			{
				ins_str = ft_strjoin("rb\n", ins_str);
				free(ins_free);
				ins_free = ins_str;
				continue;
			}
			rotate((int *)(child + size), elements);
		}
		(rev_rotate((int *)child, elements), rev_rotate((int *)(child + size), elements));
		if (!ft_bfrncmp(parent + sizeof(char *), child, 2 * size))
		{
			ins_str = ft_strjoin("rr\n", ins_str);
			free(ins_free);
			ins_free = ins_str;
			continue;
		}
		(rotate((int *)child, elements), rotate((int *)(child + size), elements));
		if (push((int *)(child + size), (int *)child, elements))
		{
			if (!ft_bfrncmp(parent + sizeof(char *), child, 2 * size))
			{
				ins_str = ft_strjoin("pa\n", ins_str);
				free(ins_free);
				ins_free = ins_str;
				continue;
			}
			push((int *)child, (int *)(child + size), elements);
		}
		if (push((int *)child, (int *)(child + size), elements))
		{
			if (!ft_bfrncmp(parent + sizeof(char *), child, 2 * size))
			{
				ins_str = ft_strjoin("pb\n", ins_str);
				free(ins_free);
				ins_free = ins_str;
				continue;
			}
			push((int *)(child + size), (int *)child, elements);
		}
	}
	printf("Voila! Below are the sets of instructions to solve the given stack\n");
	printf("%s", ins_str);
}

int	main()
{
	int		a[] = {9, 4, 8, 7, 3, 6, 5}; // {9, 4, 8, 7}
	int		*b = (int[sizeof(a) / sizeof(int)]){};
	int 	elements = sizeof(a) / sizeof(int);
	/*
	Each node has corresponding data:
	1) a pointer(char *) that points to the next node
	2) stack a
	3) stack b
	4) a pointer(char *) that points to the node that generates this node
	*/
	char	*linked_list = malloc(2 * (sizeof(a) + sizeof(char *)));
	char	*head = linked_list;

	*(char **)head = NULL;
	ft_memmove(head + sizeof(char *), a, sizeof(a));
	ft_memmove(head + sizeof(char *) + sizeof(a), b, sizeof(a));
	*(char **)(head + 2 * sizeof(a) + sizeof(char *)) = NULL;
	printf("Beforing entering generation\n");
	printf("1st node address: %p\n", linked_list);
	printf("Stack configuration:\n");
	for (size_t i = 0; i < elements; i++)
		printf(" %d %d\n", ((int *)(linked_list + sizeof(char *)))[i], ((int *)(linked_list + sizeof(char *)))[elements + i]);
	write(1, " - -\n a b\n", 10);
	head = generation(linked_list, head, sizeof(a));
	// printf("Traversing solution backward\n");
	// while (head)
	// {
	// 	write(1, "Node information:\n", 18);
	// 	printf("Address: %p\n", head);
	// 	printf("Generated by: %p\n", *(char **)(head + sizeof(char *) + 2 * sizeof(a)));
	// 	printf("Stack a: [ ");
	// 	for (size_t i = 0; i < elements; i++)
	// 		printf("%d ", ((int *)(head + sizeof(char *)))[i]);
	// 	printf("]\n");
	// 	printf("Stack b: [ ");
	// 	for (size_t i = 0; i < elements; i++)
	// 		printf("%d ", ((int *)(head + sizeof(char *) + sizeof(a)))[i]);
	// 	printf("]\n");
	// 	head = *(char **)(head + sizeof(char *) + 2 * sizeof(a));
	// }
	instruction(head, sizeof(a));
	return (0);
}
