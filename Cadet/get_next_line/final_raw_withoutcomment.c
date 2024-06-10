#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 10

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
	unsigned int	append_index;
	unsigned int	buffer_index;

	append_index = last_index;
	if (index < BUFFER_SIZE)
		buffer_index = *(int *)buffer - (index - last_index);
	else
		buffer_index = 0;
	new_block = malloc(index);
	if (!new_block)
		return(NULL);
	if (ft_memmove(new_block, memory_block, append_index), index > BUFFER_SIZE)
			free(memory_block);
	while (append_index < index)
		new_block[append_index++] = buffer[buffer_index++ + sizeof(int)];
	return (new_block);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + sizeof(int)];
	char		*memory_block;
	size_t		index;
	size_t		last_index;
	size_t		read_value;
 
	index = 0;
	read_value = BUFFER_SIZE;
	while (read_value == BUFFER_SIZE)
	{
		if (!(*(int *)buffer % BUFFER_SIZE))
		{
			read_value = read(fd, buffer + sizeof(int), BUFFER_SIZE);
			if (read_value <= 0)
				return (NULL);
			*(int *)buffer = 0;
		}
		last_index = index;
		while (*(int *)buffer != read_value)
			if (index++, buffer[(*(int *)buffer)++ + sizeof(int)] == 10)
				return (ft_realloc(memory_block, buffer, index, last_index));
		memory_block = ft_realloc(memory_block, buffer, index, last_index);
	}
	return (memory_block);
}

int	main(void)
{
	char fd = open("essay.txt", O_RDWR);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("The line[%s]\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));

	return (0);
}
