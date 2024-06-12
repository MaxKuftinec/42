/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:24:56 by asapar            #+#    #+#             */
/*   Updated: 2024/06/11 17:50:37 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // Remove this before submitting
#include <stdio.h> // Remove this before submitting

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + offset];
	char		*memory_block;
	size_t		index;
	size_t		last_index;

	index = 0;
	if (!*(int *)buffer)
	{
		((int *)buffer)[1] = 42;
		// printf("What's happenin?\n");
	}
	while (((int *)buffer)[1])
	{
		// printf("memory_block[%s]\n", memory_block);
		if (!(*(int *)buffer % ((int *)buffer)[1]))
		{
			((int *)buffer)[1] = read(fd, buffer + offset, BUFFER_SIZE);
			// printf("It does read\n");
			if (((int *)buffer)[1] <= 0 && !index) // We can tell that there was previous allocation by tracking the index value
			{
				// printf("Returning null\n");
				return (NULL);
			}
			else if (((int *)buffer)[1] <= 0 && index)
				return(memory_block);
			*(int *)buffer = 0;
		}
		last_index = index;
		while (*(int *)buffer != ((int *)buffer)[1])
			if (index++, buffer[(*(int *)buffer)++ + offset] == 10 || ((*(int *)buffer == ((int *)buffer)[1]) && ((int *)buffer)[1] < BUFFER_SIZE))
				return (ft_realloc(memory_block, buffer, index, last_index));
		memory_block = ft_realloc(memory_block, buffer, index, last_index);
		 printf("Looping\n");
	}
	// printf("Should not print\n");
	return (NULL);
}

int main()
{
	char fd = open("multiple_line_with_nl", O_RDWR);
	char *memory_block;

	for (int i = 0; i < 7; i++)
	{
		memory_block = get_next_line(fd);
		printf("the line[%s]", memory_block);
		free(memory_block);
	}
}
