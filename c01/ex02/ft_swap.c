/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:29:21 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/15 15:29:21 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
/*
    Takes in adresses of two int vars,
    switches their values
*/
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
int main(void)
{
    int a = 13;
    int b = 42;

    ft_swap(&a, &b);
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    return 0;
}
*/