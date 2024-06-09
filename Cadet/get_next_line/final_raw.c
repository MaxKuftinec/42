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

	append_index = last_index; // Can be simplified by directly using last_index
	// printf("Inside realloc. index: %lu\n", index);
	// printf("Inside realloc. last_index: %lu\n", last_index);
	// printf("Inside realloc. old block[%s]\n", memory_block);
	// printf("Inside realloc. Address of old_block: %p\n", memory_block);
	if (index < BUFFER_SIZE)
		buffer_index = *(int *)buffer - (index - last_index); // Wrong here. This determines where the buffer_index should start
	else
		buffer_index = 0;
	// printf("Allocating new_block with index: %lu\n", index);
	new_block = malloc(index);
	if (!new_block)
		return(NULL);
	if (ft_memmove(new_block, memory_block, append_index), index > BUFFER_SIZE)
		{
			// printf("Yes, it does free\n");
			free(memory_block);
		}
	while (append_index < index)
		new_block[append_index++] = buffer[buffer_index++ + sizeof(int)];
	// printf("Inside realloc. new block[%s]\n", new_block);
	// printf("Inside realloc. Address of new_block: %p\n", new_block);
	return (new_block);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + sizeof(int)];
	char		*memory_block; // It would be best to initialize it to NULL. So we can know if we have to free it or not in ft_realloc. Or maybe not and retain current implementation?
	size_t		index; // Maybe can change size_t to int
	size_t		last_index;
	size_t		read_value;
 
	index = 0;
	read_value = BUFFER_SIZE;
	while (read_value == BUFFER_SIZE)
	{
		// printf("trim_index: %d\n", *(int *)buffer);
		// printf("memory_block[%s]\n", memory_block);
		if (!(*(int *)buffer % BUFFER_SIZE))
		{
			read_value = read(fd, buffer + sizeof(int), BUFFER_SIZE);
			// printf("new buffer[%s]\n", buffer + sizeof(int));
			if (read_value <= 0)
				return (NULL);
			*(int *)buffer = 0;
		}
		// else
		// 	printf("last buffer: [%s]\n", buffer + sizeof(int));
		last_index = index;
		// printf("last_index: %lu\n", last_index);
		while (*(int *)buffer != read_value)
		{
			if (index++, buffer[(*(int *)buffer)++ + sizeof(int)] == 10)
			{
				// printf("buffer[%s]\n", buffer + sizeof(int));
				return (ft_realloc(memory_block, buffer, index, last_index));
			}

		}
		memory_block = ft_realloc(memory_block, buffer, index, last_index);
		// printf("Looping again\n");
	}
	return (memory_block);
}

int	main(void)
{
	char fd = open("essay1.txt", O_RDWR);

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
