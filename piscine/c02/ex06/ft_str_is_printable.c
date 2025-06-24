/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:27:26 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 17:37:29 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
/*
	This is a function that:
	returns 1 if the given string contains only printable characters:
				from 32 = ' ', to 126 = '~'
			0 if it contains any other character
*/
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32
			|| str[i] > 126)
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
    printf("is printsble?: %d\n", ft_str_is_printable("HELLO, World!"));
	// Should print 1
    printf("is printsble?: %d\n", ft_str_is_printable("Hello\nWorld!"));   
	// Should print 0
    printf("is printsble?: %d\n", ft_str_is_printable("\rhel\tlo1"));  
	// Should print 0
    printf("is printsble?: %d\n", ft_str_is_printable(""));        
	// Should print 1
    return 0;
}
*/
