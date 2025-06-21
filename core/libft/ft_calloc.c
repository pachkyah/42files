/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypachkou <ypachkou@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:24:40 by ypachkou          #+#    #+#             */
/*   Updated: 2025/05/31 21:13:21 by ypachkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
/*
	This function allocates memory for an array
	and initializes all bytes to zero;
	Returnes NULL if memory overflow
*/
{
	size_t	total_size;
	void	*ptr;

	total_size = num * size;
	if (size != 0 && total_size / size != num)
	{
		return (NULL);
	}
	ptr = malloc(total_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	return (ft_memset(ptr, 0, total_size));
}
