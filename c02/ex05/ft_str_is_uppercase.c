/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:23:35 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 17:32:27 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
/*
	This is a function that:
	returns 1 if the given string contains only uppercase letters or empty
			0 if it contains any other character
*/
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A'
				&& str[i] <= 'Z'))
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
    printf("is uppercase?: %d\n", ft_str_is_uppercase("HELLO"));
	// Should print 1
    printf("is uppercase?: %d\n", ft_str_is_uppercase("Hello"));   
	// Should print 0
    printf("is uppercase?: %d\n", ft_str_is_uppercase("hello1"));  
	// Should print 0
    printf("is uppercase?: %d\n", ft_str_is_uppercase(""));        
	// Should print 1
    return 0;
}
*/
