/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 22:08:15 by pachkyah          #+#    #+#             */
/*   Updated: 2025/06/22 22:10:26 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
/*
    This function takes a node as parameter and frees its content
    using the function ’del’. Free the node itself but
    does NOT free the next node.
*/
{
	if (!lst || !del)
		return;
	del(lst->content);
	free(lst);
}
