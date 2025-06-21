/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:31 by ypachkou          #+#    #+#             */
/*   Updated: 2025/06/01 02:36:15 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
/*
	This function returns a pointer to a new string 
	which is a duplicate of the string 's'.
*/
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
