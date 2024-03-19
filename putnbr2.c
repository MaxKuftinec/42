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
		if (n % 10 < 0)
			ft_putchar(48 - (n % 10));
		else
			ft_putchar(48 + (n % 10));
	}
}
