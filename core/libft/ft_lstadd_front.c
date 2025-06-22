/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 22:00:35 by pachkyah          #+#    #+#             */
/*   Updated: 2025/06/22 22:02:16 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
/*
    This function adds the node ’new’ at the beginning of the list.
*/
{
	if (!lst || !new)
		return;
	new->next = *lst;
	*lst = new;
}
