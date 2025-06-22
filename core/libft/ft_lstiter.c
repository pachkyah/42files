/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 22:16:15 by pachkyah          #+#    #+#             */
/*   Updated: 2025/06/22 22:17:05 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
/*
    This function iterates through the list ’lst’ and applies the
    function ’f’ to the content of each node.
*/
{
	if (!lst || !f)
		return;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
