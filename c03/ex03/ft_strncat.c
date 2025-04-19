/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:24:08 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 22:20:08 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stddef.h> 

char	*ft_strncat(char *dest, const char *src, unsigned int nb)
/*
    This function appends nb characters from string src to the end of the string dest:
	the result is stored in dest
	dest must have enough space to hold the result (no mem check!)
*/
{
	char	*ptr;
	size_t	i;

	ptr = dest;
	while (*ptr)
	{
		ptr++;
	}
	i = 0;
	while (i < nb && *src)
	{
		*ptr = *src;
		ptr++;
		src++;
		i++;
	}
	*ptr = '\0';
	return (dest);
}

/*
int main()
{
    char buffer[100] = "Hello, ";
    char *add = "world! How are you?";

    ft_strncat(buffer, add, 6);  
    // Only append the first 6 characters of "world!"
    printf("%s\nb", buffer);
    // Output: Hello, world!

    return 0;
}
*/
