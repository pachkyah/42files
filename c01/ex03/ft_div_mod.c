//#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod)
/*
    This function divides int a by b
    and stores the result in div;
    stores the remainder of the division in the mod;
    special case for 0;
*/
{
    if (b != 0)
    {
        *div = a / b;
        *mod = a % b;
    }
    else
    {
        *div = 0;
        *mod = 0;
    }
}

/*
int main()
{
    int a = 10;
    int b = 3;
    int div, mod;

    ft_div_mod(a, b, &div, &mod);

    printf("Div: %d, Mod: %d\n", div, mod);
    return 0;
}
*/
