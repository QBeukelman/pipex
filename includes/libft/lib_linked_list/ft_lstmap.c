/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 11:51:11 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:53:27 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Iterate the list 'lst' and apply the function 'f'
// on the content of each node. Creare a new list 
// resulting from the successive applications of 'f'.
// The 'del' function is used to delete the content
// of a node if needed.

// Paramaters:
// lst: the address of a pointer to a node.
// f: the address of the function used to iterate on the
// list.
// del: the address of the  function used to delete the
// content of a node if needed.

// Return Value: the new list. NULL if the allocation 
// fails.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew((*f)(lst -> content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst -> next;
	}
	return (new_list);
}
