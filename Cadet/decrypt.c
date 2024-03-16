#include <unistd.h>

void create_client(void)
{
	write(1, "Hey!\n", 5);
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;
	int i = 0;
	write(1, "Argument is: ", 13);
	while (argv[1][i])
	{
		if (argv[1][i] <= 'z' && argv[1][i] >= 'n')
		{
			argv[1][i] -= 13;
			write(1, &argv[1][i++], 1);
			continue;
		}
		if (argv[1][i] <= 'Z' && argv[1][i] >= 'N')
		{
			argv[1][i] -= 13;
			write(1, &argv[1][i++], 1);
			continue;
		}
		if (argv[1][i] <= 'm' && argv[1][i] >= 'a')
		{
			argv[1][i] += 13;
			write(1, &argv[1][i++], 1);
			continue;
		}
		if (argv[1][i] <= 'M' && argv[1][i] >= 'A')
		{
			argv[1][i] += 13;
			write(1, &argv[1][i++], 1);
			continue;
		}
		write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	ft_putstr("\n");
	return 0;
}*/