/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asapar <asapar@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:36:45 by asapar            #+#    #+#             */
/*   Updated: 2024/04/17 23:22:40 by asapar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>

int a = 0;

// Two way to read. Create 2 different file descriptor for the same file, first one to detect newline, the other is to read. Compare which is faster

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;
	char	*q;
	size_t	totalsize;

	totalsize = size * nitems;
	if (nitems > 4294967295 && size > 4294967295)
		return (NULL);
	p = malloc(totalsize);
	if (!p)
		return (NULL);
	q = (char *)p;
	while (totalsize--)
		*q++ = 0;
	return (p);
}

char	*get_next_line(int fd, int fd2) // Find a way to make this function accept 1 argument only
{
	char	*line;
	size_t	count;
	char	check_newline;

	a = dup(fd);
	count = 0;
	check_newline = 0;

	while (check_newline != '\n' && read(fd2, &check_newline, 1))
		count++;
	line = ft_calloc(count, sizeof(char)); // Gotta calloc it
	read(fd, line, count);
	free(line);
	return (line);
}

int	main(void)
{
	clock_t tic, toc;
	char buffer[100];
	char check_newline = 0;
	size_t count = 0;

	int fd = open("essay.txt", O_RDWR);
	int fd2 = open("essay.txt", O_RDONLY);
	
	/*while (check_newline != '\n') // stop loop if last read was newline
	{	
		read(fd2, &check_newline, 1); //read from fd2
		count++; // This variable serve as 3rd argument of read for returning get_next_line
	}
	read(fd, buffer, count); // Returning the line to buffer*/
	printf("%s", get_next_line(fd, fd2));
	printf("%s", get_next_line(fd, fd2));
	printf("%s", get_next_line(fd, fd2));
	printf("%s", get_next_line(fd, fd2));
	printf("%s", get_next_line(fd, fd2));
	close(fd);
	close(fd2);
}
