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
#include <stdlib.h>

static char	*ft_strtrim_line(const char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	while (ft_strchr(10, s[i]) && s[i])
		i++;
	while (ft_strchr(10, s[j - 1]) && j > i)
		j--;
	str = (char *) malloc(sizeof(char) * (j - i + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[i], j - i + 1);
	return (str);
}

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

char	*get_next_line(int fd) // use the static var to track last index
{
	char			*line;
	static char		*buffer[2]; // One for original buffer, 2nd for return. Has to be static because if not, then the read data will be lost after the function ends. If static, the variable will keep the values
	static long		buffer_index = 0;
	long			copy;		
	unsigned int	allocation_count;

	buffer[0] = malloc(BUFFER_SIZE);
	read(fd, buffer[0], BUFFER_SIZE); // Before reading, allocate space. What if read return lower than buffer size?
	allocation_count = 1;
	
	while(buffer_index != allocation_count * BUFFER_SIZE)
	{
		if (copy = 0, buffer[0][buffer_index] == 10)
		{
			buffer[1] = malloc(buffer_index + 1);
			while (copy <= buffer_index)
			{
				buffer[1][copy] = buffer[0][copy];
				copy++;
			}
			return (free(buffer[0]), free(buffer[1]), buffer[1]);
		}
		buffer_index++;
	}
	//From this line onward, might put it all in the same while above
	buffer[1] = malloc(BUFFER_SIZE * allocation_count++);
	copy everything from buffer0 to buffer1
	free buffer0
	buffer0 = malloc(BUFFER_SIZE * allocation_count);
}
//Current process flow only calculate for 1 allocation. There's 2 critical situation. If one read does not include a newline char and if one read include more than one newline char
int	main(void)
{
	int fd = open("essay.txt", O_RDWR);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}
