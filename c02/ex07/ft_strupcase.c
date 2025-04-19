/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:38:53 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 17:42:58 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
/*
	This function takes in a string
	and converted any lowercase letter into uppercase
*/
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a'
			&& str[i] <= 'z')
		{
			str[i] = str[i] - 'a' + 'A';
		}
		i++;
	}
	return (str);
}

/*
int main(void)
{
    char str0[] = "hello world";
    char str1[] = "C programming in 42";

    printf("%s\n", ft_strupcase(str0));  
    printf("%s\n", ft_strupcase(str1));
    return 0;
}
*/