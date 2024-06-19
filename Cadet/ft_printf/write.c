#include <unistd.h>
#include <fcntl.h>

int main()
{
    char    fd = open("essay.txt", O_WRONLY);
    char    *str1 = "String 1";
    char    *str2 = "String 2";
    char    *str3 = "String 3";

    write(fd, str1, 9);
    write(fd, str2, 9);
    write(fd, str3, 9);
}