/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:48:13 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:53:32 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Allocate (with malloc(3)) and return a new node.
// The member variable 'content' is initalizes with
// the value of the parameter 'content'. The variable
// 'next' is initialized to NULL.

// Paramaters:
// content: the content to create the node with.

// Return Value: the new node.

// Notes:
// Linked list is a self rederential data structure, 
// it countains one data member, and one pointer which
// stored the address of next node, being of the same 
// type.

// 'head' is the pointer to struct node only. This
// pointer can access data and the link. Pointer to
// the first node.

t_list	*ft_lstnew(void *content)
{
	struct s_list	*head;

	head = malloc(sizeof(struct s_list));
	if (head == NULL)
		return (NULL);
	head -> content = content;
	head -> next = NULL;
	return (head);
}
