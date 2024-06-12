/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:59:14 by asapar            #+#    #+#             */
/*   Updated: 2024/06/11 17:59:16 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

char	*ft_realloc(char *memory_block, char *buffer, size_t index, size_t last_index)
{
	char			*new_block;
	unsigned int	buffer_index;

	if (index < BUFFER_SIZE)
		buffer_index = *(int *)buffer - (index - last_index);
	else
		buffer_index = 0;
	printf("Old memory_block[%s]\n", memory_block);
	printf("Old memory_block address[%p]\n", memory_block);
	printf("Mallocking with size: %lu\n", index + 1);
	new_block = malloc(index + 1); // Please delete the + 1 before submitting
	if (!new_block)
		return (NULL);
	printf("index: %lu\nread_value: %d\n", index, ((int *)buffer)[1]);
	printf("last_index: %lu\n", last_index);
	if (ft_memmove(new_block, memory_block, last_index), last_index)
	{
		printf("Freeing memory_block\n");
		free(memory_block);
	}
	while (last_index < index)
		new_block[last_index++] = buffer[buffer_index++ + offset];
	new_block[last_index] = 0; // Please delete the + 1 before submitting
	printf("New memory_block[%s]\n", new_block);
	printf("New memory_block address[%p]\n", new_block);
	return (new_block);
}
