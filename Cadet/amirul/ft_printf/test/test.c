#include "libft.h"
#include <stdio.h>

int main()
{
	char	*p;
	char	*s = "My name is Jeff!";
	int nb;

	printf("%d\n", printf("Hello world!\n"));
	ft_printf("%d\n", ft_printf("Hello world!\n"));


	printf("\n");
	printf("%d\n", printf("%d\n", 2147483647));
	ft_printf("%d\n", ft_printf("%d\n", 2147483647));

	printf("\n");
	printf("%d\n", printf("%i\n", -2147483648));
	ft_printf("%d\n", ft_printf("%i\n", 2147483648));

	printf("\n");
	printf("%i\n", printf("%i\n", -2147483648));
	ft_printf("%i\n", ft_printf("%i\n", -2147483648));

	printf("\n");
	printf("%d\n", printf("%c\n", 97));
	ft_printf("%d\n", ft_printf("%c\n", 97));

	printf("\n");
	printf("%d\n", printf("%p\n", p));
	ft_printf("%d\n", ft_printf("%p\n", p));

	printf("\n");
	printf("%d\n", printf("%p\n", &p));
	ft_printf("%d\n", ft_printf("%p\n", &p));

	p = 0;
	printf("\n");
	printf("%d\n", printf("%p\n", p));
	ft_printf("%d\n", ft_printf("%p\n", p));

	printf("\n");
	printf("%d\n", printf("%x\n", 2147483648));
	ft_printf("%d\n", ft_printf("%x\n", 2147483648));

	printf("\n");
	printf("%d\n", printf("%X\n", 2147483647));
	ft_printf("%d\n", ft_printf("%X\n", 2147483647));

	printf("\n");
	printf("%d\n", printf("Hello %s\n", "world!"));
	ft_printf("%d\n", ft_printf("Hello %s\n", "world!"));

	printf("\n");
	printf("%d\n", printf("Hello %s\n", NULL));
	ft_printf("%d\n", ft_printf("Hello %s\n", NULL));

	printf("\n");
	printf("%d\n", printf("%%\n"));
	ft_printf("%d\n", ft_printf("%%\n"));

	printf("\n");
	printf("%d\n", printf("%%%%\n"));
	ft_printf("%d\n", ft_printf("%%%%\n"));

	printf("\n");
	printf("%d\n", printf("%%%%%%\n"));
	ft_printf("%d\n", ft_printf("%%%%%%\n"));

	printf("\n");
	printf("%d\n", printf("%s\n", s));
	ft_printf("%d\n", ft_printf("%s\n", s));
	return 0;
}
