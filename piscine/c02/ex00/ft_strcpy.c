/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:29:02 by ypachkou          #+#    #+#             */
/*   Updated: 2025/04/17 15:42:37 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
/*
    This function replicates the behavior of the function strcpy:
    meaning it copies each character form src to dest,
    assuming that dest has enough memory!!!
	+ terminator char at the end
*/
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int main(void)
{
    char src[] = "Hello, World!";
    char *dest = malloc(sizeof(char) * (sizeof(src))); // enough space for src

    if (dest == NULL)
        return 1;

    ft_strcpy(dest, src);
    printf("Copied string: %s\n", dest);

    free(dest);
    return 0;
}
*/
