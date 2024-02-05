#include <unistd.h>

void solve(char *str1, char *str2)
{
    int i = -1, j = 0, ascii[256] = {0};
    while (str2[++i])
        if (ascii[(int)str2[i]] == 0)
            ascii[(int)str2[i]] = 1;
    i = -1;
    while (str1[++i])
        if (ascii[(int)str1[i]] == 1)
        {
            ascii[(int)str1[i]] = 2;
            write(1, &str1[i], 1);
        }
}

int	main(void) 
{
    int ascii[256] = {0};
    char str1[] = "padington";
    char str2[] = "Wasfasodpfuasfqew";
	solve(str1, str2);
	write(1, "\n", 1);
	return 0;
}
