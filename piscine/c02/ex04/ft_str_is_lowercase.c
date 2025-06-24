/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:16:03 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 17:22:18 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
/*
	This is a function that:
	returns 1 if the given string contains only lowercase letters or empty
			0 if it contains any other character
*/
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a'
				&& str[i] <= 'z'))
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
    printf("is lowercase?: %d\n", ft_str_is_lowercase("hello"));
	// Should print 1
    printf("is lowercase?: %d\n", ft_str_is_lowercase("Hello"));   
	// Should print 0
    printf("is lowercase?: %d\n", ft_str_is_lowercase("hello1"));  
	// Should print 0
    printf("is lowercase?: %d\n", ft_str_is_lowercase(""));        
	// Should print 1
    return 0;
}
*/
