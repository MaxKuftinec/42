#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 3

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

char	*ft_realloc(char *memory_block, char *buffer, unsigned int allocation_count)
{
	char			*new_block;
	unsigned int	append_index;
	unsigned int	buffer_index;

	append_index = (allocation_count - 1) * BUFFER_SIZE;
	buffer_index = 0;
	if (allocation_count != 1)
		free(memory_block);
	new_block = malloc(allocation_count * BUFFER_SIZE);
	ft_memmove(new_block, memory_block, append_index);
	while (buffer_index != BUFFER_SIZE)
		new_block[append_index++] = buffer[buffer_index++];
	return(new_block);
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	static char		*memory_block = NULL;
	size_t			index;
	unsigned int	allocation_count;
	int 			i = 0;

	allocation_count = 1;
	index = 0;
	while (i++ != 2)
	{
		read(fd, buffer, BUFFER_SIZE);
		while (index != allocation_count * BUFFER_SIZE)
		{
			if (buffer[index++ - ((allocation_count - 1) * BUFFER_SIZE)] == 10)
				return (memory_block);
		}
		memory_block = ft_realloc(memory_block, buffer, allocation_count++);
	}
	return (memory_block);
}

int	main(void)
{
	int fd = open("essay1.txt", O_RDWR);

	printf("%s\n", get_next_line(fd));
	return (0);
}
