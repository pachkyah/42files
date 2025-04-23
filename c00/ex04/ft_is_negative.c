/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:34:39 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/12 14:40:41 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
/*
    checks if int is negative or positive(including 0)
*/
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}

/*
int	main(void)
{
    ft_is_negative(5);
    ft_is_negative(0);
	ft_is_negative(-5);
	return (0);
}
*/