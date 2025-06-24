/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:49:06 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 19:07:40 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str)
/*
	This function capitalizes the first letter of each word 
	and converts all other letters to lowercase
	A word is a sequence of alphanumeric characters
	basically combined ft_strupcase/lowcase
*/
{
	int	i;
	int	is_new_word;

	i = 0;
	is_new_word = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (is_new_word && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 'a' + 'A';
			else if (!is_new_word && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] - 'A' + 'a';
			is_new_word = 0;
		}
		else
		{
			is_new_word = 1;
		}
		i++;
	}
	return (str);
}

/*
int main(void)
{
    char str0[] = "hi, how are you? 42words forty-two; fifty+and+one";
    char str1[] = "hello, world! this is 42+prague";
    char str2[] = "mIXed CaSe TeXT with-42numbers";

    printf("%s\n", ft_strcapitalize(str0));
    printf("%s\n", ft_strcapitalize(str1));
    printf("%s\n", ft_strcapitalize(str2));
    return 0;
}
*/
