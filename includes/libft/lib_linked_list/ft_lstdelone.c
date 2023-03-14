/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 11:49:19 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:53:11 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Take as a parameter a node and free the memory of
// the node's content using the function 'del' given
// as a parameter. The memory of 'next' must not be 
// freed.

// Paramaters:
// lst: the node to free.
// del: the address of the function used to delete the
// content.

// Return Value: none.

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst -> content);
	free(lst);
	lst = NULL;
}
