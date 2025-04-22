/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:40:32 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/22 18:08:51 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
/*
	This function returns element number 'index',
	from Fibonacci sequence
	using recursive methid
	returns -1 for bad inputs
*/
{
	if (index < 0)
	{
		return (-1);
	}
	if (index == 0)
	{
		return (0);
	}
	if (index == 1)
	{
		return (1);
	}
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*
int main() {
    int number = 0;
	int number1 = 5;
	int number2 = 10;
    int result = ft_fibonacci(number);
	int result1 = ft_fibonacci(number1);
	int result2 = ft_fibonacci(number2);

    if (result != -1) {
        printf("%dnd element of Fibonacci = %d\n", number, result);
		printf("%dnd element of Fibonacci = %d\n", number1, result1);
		printf("%dnd element of Fibonacci = %d\n", number2, result2);
    } else {
        printf("bad input 😭\n");
    }
    return 0;
}
*/
