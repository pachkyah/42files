//#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
/*
    This function that counts and returns
    the number of characters in a string
*/
{
    int index;

    index = 0;
    while (str[index] != '\0')
    {
        index++;
    }
    return index;
}

/*
int main()
{
    chat str[] = "hello"

    ft_putstr(str)
    return 0;
}
*/
