//#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
/* writes 1 character,
	write args:
	1 means stdout,
	1 means length */
{
	write(1, &c, 1);
}


void ft_putstr(char *str)
/*
    This function that displays
    a string of characters on the standard output
*/
{
    int index;

    index = 0;
    while (str[index] != '\0')
    {
        ft_putchar(str[index]);
        index++;
    }
    
}

/*
int main()
{
    chat str[] = "hello"

    ft_putstr(str)
    return 0;
}
*/
