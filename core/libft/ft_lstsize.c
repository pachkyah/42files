/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 22:03:29 by pachkyah          #+#    #+#             */
/*   Updated: 2025/06/22 22:04:38 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
/*
    This function counts the number of nodes in the list.
*/
{
	int count;
    
    count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
