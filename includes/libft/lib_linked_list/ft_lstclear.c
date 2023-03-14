/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 11:49:50 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:53:06 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Delete and free the given nodes and every
// successor of that node, using the function
// 'del' and free(3). The pointer to the list
// must be set to NULL.

// Paramaters:
// lst: the address of a pointer to a node.
// del: the address of the function used to 
// delete the content of the node

// Return Value: none.

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		p = (*lst)-> next;
		ft_lstdelone(*lst, del);
		(*lst) = p;
	}
}
