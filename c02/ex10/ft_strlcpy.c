/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:08:10 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 18:31:04 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlen(char *str)
/*
    This function that counts and returns
    the number of characters in a string
*/
{
	unsigned int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
/*
    This function that counts and returns
    the number of characters in a string, 
	but also makes a copy of len "size" into dest string
*/
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(src);
	if (size == 0)
		return (i);
	j = 0;
	while (src[j] != '\0' && j < size - 1)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

/*
int main(void)
{
    char src[] = "Hello, 42!";
    char dest[20];

    unsigned int len = ft_strlcpy(dest, src, 3);
	// He + '\0'

    printf("Copied string: %s\n", dest);
    printf("Length of src: %u\n", len);
    return 0;
}
*/
