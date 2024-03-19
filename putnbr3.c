#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0 && n != -2147483648)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		ft_putchar(48 + n);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(48 + ((unsigned int)n % 10));
	}
}
