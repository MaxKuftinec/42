#include <string.h>
#include <stdio.h>

int main()
{
    char buffer[] = "Hello "; // size = 7
    char buffer2[] = "world!"; // size = 7
    char buffer3[100];

    printf("Return value: %d\nbuffer3: %s", strlcat(buffer3, buffer, 7), buffer3);
    printf("Return value: %d\nbuffer3: %s", strlcat(buffer3, buffer2, 7), buffer3);
}