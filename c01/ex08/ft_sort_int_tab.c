//#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
/*
    The function takes two arguments:
    a pointer to an int and the number of elements
    than sorts an array of integers in ascending order
*/
{
    int i, tmp;
    int sorted = 0;

    while (!sorted)
    {
        sorted = 1;
        i = 0;
        while (i < size - 1)
        {
            if (tab[i] > tab[i + 1])
            {
                tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                sorted = 0;
            }
            i++;
        }
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