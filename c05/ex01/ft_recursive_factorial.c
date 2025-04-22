/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:15:27 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/22 18:09:00 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_factorial(int nb)
/*
	This function counts factorial until nb,
	using recursive methid
	returns 1 for nb == 0; and 0 for bad inputs
*/
{
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}

/*
int main() {
    int number = 10;
    int result = ft_recursive_factorial(number);

    if (result != 0) {
        printf("%d!=%d\n", number, result);
    } else {
        printf("bad input 😭\n");
    }
    return 0;
}
*/
