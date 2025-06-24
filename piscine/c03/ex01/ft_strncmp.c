/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:20:08 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 22:01:27 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stddef.h> 

int	ft_strncmp(char *s1, char *s2, unsigned int n)
/*
	This function compares n characters in 2 strings:
    0, if the s1 and s2 are equal;
    a negative if n character value in s1 is less than s2;
    a positive if n character value in s1 is greater than s2.
*/
{
	size_t	i;

	i = 0;
	while (i < n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
int main()
{
    printf("%d\n", ft_strncmp("abc", "abc", 2));      // 0
    printf("%d\n", ft_strncmp("abc", "abd", 3));      // negative
    printf("%d\n", ft_strncmp("abc", "ab", 3));       // positive
    printf("%d\n", ft_strncmp("abc", "abcd", 10));    // negative
    return 0;
}
*/
