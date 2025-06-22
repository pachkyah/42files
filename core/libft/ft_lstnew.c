/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pachkyah <pachkyah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:56:50 by pachkyah          #+#    #+#             */
/*   Updated: 2025/06/22 21:59:10 by pachkyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
/*
    This function allocates memory (using malloc(3)) and returns
    a new node. The ’content’ member variable is
    initialized with the given parameter ’content’.
    The variable ’next’ is initialized to NULL.
*/
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
