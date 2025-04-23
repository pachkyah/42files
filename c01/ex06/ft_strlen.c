/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:40:01 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/15 15:40:01 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
/*
    This function that counts and returns
    the number of characters in a string
*/
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

/*
int main()
{
    char str[] = "hello";

    printf("Len: %d\n", ft_strlen(str));
    return 0;
}
*/
