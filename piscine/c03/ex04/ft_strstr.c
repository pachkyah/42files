/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:24:11 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/19 19:11:36 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stddef.h> 

size_t	ft_strlen(char *str)
/*
    This function that counts and returns
    the number of characters in a string
*/
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

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

char	*ft_strstr(char *str, char *to_find)
/*
	This function locates substring to_find in str:
	goes through each character in str, and runs strncmp
	if found returns pointer to location of to_find in str
	else NULL 
*/
{
	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str)
	{
		if (ft_strncmp(str, to_find, ft_strlen(to_find)) == 0)
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}

// int main()
// {
//     char *haystack = "Hello, world!";
//     char *needle = "world";

//     char *result = ft_strstr(haystack, needle);
//     if (result){
//         printf("Found: %s\n", result);
// 		// Found: world!
// 	}else{
//         printf("Not found\n");
// 	}
//     return 0;
// }
