#include <stdio.h>

int main(int argc, char *argv[]) 
{
    char str[] = "    Helloworld    ami";
    int i = 0, j;
    while (str[i] != '\0')
        i++;
    i--;
    while (i >= 0)
    {
        if (str[i] != ' ' && str[i] != '\t')
            break;
        else
            i--;
    }
    j = i;
    while (j > 0)
    {
        if (str[j - 1] == ' ' || str[j - 1] == '\t')
            break;
        else
            j--;
    }
    while (i >= j)
    {
        printf("%c", str[j]);
        j++;
    }
    return 0;
}
