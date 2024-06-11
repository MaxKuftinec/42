/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:24:56 by asapar            #+#    #+#             */
/*   Updated: 2024/06/11 13:25:05 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 100000
// #define OFFSET (2 * sizeof(int))
enum { OFFSET = 2 * sizeof(int) };

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
	new_block = malloc(index);
	if (!new_block)
		return (NULL);
	if (ft_memmove(new_block, memory_block, last_index), index > BUFFER_SIZE)
		free(memory_block);
	while (last_index < index)
		new_block[last_index++] = buffer[buffer_index++ + OFFSET];
	return (new_block);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + OFFSET];
	char		*memory_block;
	size_t		index;
	size_t		last_index;

	index = 0;
	if (!*(int *)buffer)
		((int *)buffer)[1] = 42;
	while (((int *)buffer)[1])
	{
		if (!(*(int *)buffer % ((int *)buffer)[1]))
		{
			((int *)buffer)[1] = read(fd, buffer + OFFSET, BUFFER_SIZE);
			if (((int *)buffer)[1] <= 0)
				return (NULL);
			*(int *)buffer = 0;
		}
		last_index = index;
		while (*(int *)buffer != ((int *)buffer)[1])
			if (index++, buffer[(*(int *)buffer)++ + OFFSET] == 10 || ((*(int *)buffer == ((int *)buffer)[1]) && ((int *)buffer)[1] < BUFFER_SIZE))
				return (ft_realloc(memory_block, buffer, index, last_index));
		memory_block = ft_realloc(memory_block, buffer, index, last_index);
	}
	return (NULL);
}

int	main(void)
{
	char fd = open("essay1.txt", O_RDWR);
	
	for (int i = 0; i < 80; i++)
		printf("The line[%s]\n", get_next_line(fd));
	printf("fd: %d\n", fd);
	return (0);
}
