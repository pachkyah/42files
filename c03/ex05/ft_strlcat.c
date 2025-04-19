/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:24:15 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/19 19:06:41 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
/*
	This function appends the string src of size 'size' to the end of the string dest:
	the result is stored in dest
	if dest has enough space -> append src and return length of dest+src
						else -> return length that needs to be avaliable
*/
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	available_space;
	size_t			i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	available_space = size - dest_len - 1;
	i = 0;
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	while (i < available_space && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// int main() {
//     // Test case 1: Normal case with sufficient space
//     char dest1[20] = "Hello";
//     char src1[] = " World!";
//     unsigned int size1 = sizeof(dest1);

//     unsigned int result1 = ft_strlcat(dest1, src1, size1);
//     printf("Test 1: %s (Result: %u)\n", dest1, result1);

//     // Test case 2: Not enough space in dest
//     char dest2[10] = "Hello";
//     char src2[] = " World!";
//     unsigned int size2 = sizeof(dest2);

//     unsigned int result2 = ft_strlcat(dest2, src2, size2);
//     printf("Test 2: %s (Result: %u)\n", dest2, result2);

//     // Test case 3: Exact space, no room for additional characters
//     char dest3[13] = "Hello";
//     char src3[] = " World!";
//     unsigned int size3 = sizeof(dest3);

//     unsigned int result3 = ft_strlcat(dest3, src3, size3);
//     printf("Test 3: %s (Result: %u)\n", dest3, result3);

//     // Test case 4: No space at all in dest
//     char dest4[3] = "Hi";
//     char src4[] = " World!";
//     unsigned int size4 = sizeof(dest4);

//     unsigned int result4 = ft_strlcat(dest4, src4, size4);
//     printf("Test 4: %s (Result: %u)\n", dest4, result4);

//     return 0;
// }
