/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:09:42 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 17:15:20 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
/*
	This is a function that:
	returns 1 if the given string contains only digits or empty
			0 if it contains any letters or else
*/
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0'
				&& str[i] <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
int main(void)
{
    char src[] = "Hello, World!";
    char src1[] = "hello";
    char src2[] = "2716839";
	char src3[] = "";

    printf("is it only numeric: %d\n", ft_str_is_numeric(src));
    printf("is it only numeric: %d\n", ft_str_is_numeric(src1));
    printf("is it only numeric: %d\n", ft_str_is_numeric(src2));
	printf("is it only numeric: %d\n", ft_str_is_numeric(src3));
    return 0;
}
*/
