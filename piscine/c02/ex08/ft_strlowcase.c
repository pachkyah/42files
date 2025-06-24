/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:44:39 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 17:48:21 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
/*
	This function takes in a string
	and converted any uppercase letter into lowercase
*/
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A'
			&& str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
	return (str);
}

/*
int main(void)
{
    char str0[] = "HELLO WORLD!";
    char str1[] = "C programming in 42";

    printf("%s\n", ft_strlowcase(str0));  
    printf("%s\n", ft_strlowcase(str1));
    return 0;
}
*/
