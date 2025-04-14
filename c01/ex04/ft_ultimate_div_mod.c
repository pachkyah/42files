//#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b)
/*
    This function divides int a by b
    and stores the result in a;
    stores the remainder of the division in the b;
    special case for 0;
*/
{
    if (b != 0)
    {
        *a = *a / *b;
        *b = *a % *b;
    }
    else
    {
        *a = 0;
        *b = 0;
    }
}

/*
int main()
{
    int a = 10;
    int b = 3;
    int div, mod;

    ft_ultimate_div_mod(&a, &b);

    printf("Div: %d, Mod: %d\n", a, b);
    return 0;
}
*/
