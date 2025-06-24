/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:19:52 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 21:51:15 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
/*
    This function compares characters in 2 strings:
    0, if the s1 and s2 are equal;
    a negative value if s1 is less than s2;
    a positive value if s1 is greater than s2.
*/
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
int main()
{
    char str1[] = "apple";
    char str2[] = "apricot";
    char str3[] = "apple";

    int result = ft_strcmp(str1, str2);
    printf("Result: %d\n", result);

    int result2 = ft_strcmp(str1, str3);
    printf("Result: %d\n", result2);

    return 0;
}
*/
