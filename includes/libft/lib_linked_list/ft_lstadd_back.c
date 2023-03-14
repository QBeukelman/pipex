/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:51:15 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:52:56 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Add the node 'new' at the end of the list

// Paramaters:
// lst: the address of a pointer to the first link of a list.
// new: the address of a pointer to the node to be added to
// the list.

// Return Value: none.

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_node;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current_node = ft_lstlast(*lst);
	current_node -> next = new;
}
