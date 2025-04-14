//#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
/*
    The function takes two arguments:
    a pointer to an int and the number of elements
    than reverses a given array of integers
*/
{
    int tmp;
    int i = 0;

    while (i < size / 2)
    {
        tmp = tab[i];
        tab[i] = tab[size - 1 - i];
        tab[size - 1 - i] = tmp;
        i++;
    }
}

/*
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    ft_rev_int_tab(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
*/
