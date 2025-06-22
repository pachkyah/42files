/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 22:10:39 by pachkyah          #+#    #+#             */
/*   Updated: 2025/06/22 22:13:05 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
/*
    This function deletes and frees the given node and all its
    successors, using the function ’del’ and free(3).
    Finally, set the pointer to the list to NULL.
*/
{
	t_list *tmp;

	if (!lst || !del)
		return;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
