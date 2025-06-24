/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:50:46 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 16:47:34 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
/*
	This function replicates standard strncpy:
	copies at most n characters from src to dest
	if src is shorter than n, the rest of dest is filled with \0 characters
	if src is longer than or equal to n, it does not null-terminate dest
*/
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
int main(void)
{
    char src[] = "Hello, World!";
    char dest[10];

    ft_strncpy(dest, src, 9);

    // Prints each character including '\0's as dots
    for (int i = 0; i < 10; i++)
        printf("dest[%d] = %c (%d)\n", i, dest[i] ? dest[i] : '.', dest[i]);

    return 0;
}
*/
