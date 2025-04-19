/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:20:18 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/19 19:11:32 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
/*
	This function appends the string src to the end of the string dest:
	the result is stored in dest
	dest must have enough space to hold the result (no mem check!)
*/
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
	{
		ptr++;
	}
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

/*
int main()
{
    char buffer[100] = "Hello, ";
    char *add = "world!";

    ft_strcat(buffer, add);
    printf("%s\n", buffer); 
	// Output: Hello, world!

    return 0;
}
*/
