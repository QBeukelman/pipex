/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:49:25 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:53:01 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Add the node 'new' at the beginning of the list.

// Paramaters:
// lst: the address of a pointer to the first link of a list.
// new: the address of a pointer to the node to be added to
// the list.

// Return Value: none.

// Notes:
// The 'next' value of 'new' is set to a pointer to the first
// node in the list. The first item in the list becomes the
// new node.

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}
