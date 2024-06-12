/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:24:56 by asapar            #+#    #+#             */
/*   Updated: 2024/06/11 21:49:14 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + offset];
	char		*mmry_blck;

	((int *)b)[2] = 0;
	if (!*(int *)b)
		((int *)b)[1] = 42;
	while (((int *)b)[1])
	{
		if (!(*(int *)b % ((int *)b)[1]))
		{
			((int *)b)[1] = read(fd, b + offset, BUFFER_SIZE);
			if (((int *)b)[1] <= 0 && !((int *)b)[2])
				return (NULL);
			else if (((int *)b)[1] <= 0 && ((int *)b)[2])
				return (mmry_blck);
			*(int *)b = 0;
		}
		((int *)b)[3] = ((int *)b)[2];
		while (*(int *)b != ((int *)b)[1])
			if (((int *)b)[2]++, b[(*(int *)b)++ + offset] == 10 || ((*(int *\
			)b == ((int *)b)[1]) && ((int *)b)[1] < BUFFER_SIZE))
				return (ft_realloc(mmry_blck, b, ((int *)b)[2], ((int *)b)[3]));
		mmry_blck = ft_realloc(mmry_blck, b, ((int *)b)[2], ((int *)b)[3]);
	}
	return (NULL);
}

/* 1) b stands for buffer (This particular array is a hybrid array)
2) mmry_block stands for memory_block. This is the block that represent
the final string. It will continously be reallocated in the factor of 
BUFFER_SIZE until gnl finds a newline or reach the eof
3) There's a total of 5 variable inside the hybrid array
((int *)buffer)[0] = trim_index (Represents the last index in the buffer when 
the last call returned after the loop found a newline)
((int *)buffer)[1] = read_value (Self explanatory)
((int *)buffer)[2] = index (Represents the size required to build memory block)
((int *)buffer)[3] = last_index (Saves the last value of index before it is 
incremented in the loop in search of newline. This does 2 important things. It 
tells how many bytes we need to transfer to new memory block from old block 
using memmove and it also indicate when to free the old block and when not too)
b[offset] = The starting offset inside the hybrid array at which the actual 
characters reside upon after the read system call
4) The program can only reach the return (NULL) at the end of the function if 
read_value equals 0. This means that we have reached the eof of our fd
5) 
*/ 
