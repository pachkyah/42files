/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 22:04:45 by pachkyah          #+#    #+#             */
/*   Updated: 2025/06/22 22:07:42 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
/*
    This function adds the node ’new’ at the end of the list.
*/
{
	t_list *last;

	if (!lst || !new)
		return;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
