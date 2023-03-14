/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 11:50:52 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:53:15 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Iterate the list 'lst' and applies the function 'f',
// on the content of each node.

// Paramaters:
// lst: the address of a pointer to a node.
// f: the address of the function used to iterate on the
// list.

// Return Value: none.

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current_node;

	current_node = lst;
	if (lst == NULL || f == NULL)
		return ;
	while (current_node != NULL)
	{
		(*f)(current_node -> content);
		current_node = current_node -> next;
	}
}
