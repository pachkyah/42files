/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:48:11 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 17:07:56 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
/*
	This is a function that:
	returns 1 if the given string contains only abc characters or empty
			0 if it contains any other character
*/
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z')))
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

    printf("is it only alphabet: %d\n", ft_str_is_alpha(src));
    printf("is it only alphabet: %d\n", ft_str_is_alpha(src1));
    printf("is it only alphabet: %d\n", ft_str_is_alpha(src2));
	printf("is it only alphabet: %d\n", ft_str_is_alpha(src3));
    return 0;
}
*/
