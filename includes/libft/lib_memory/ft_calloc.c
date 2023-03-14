/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:05:19 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:53:47 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// calloc contiguously (being in actual contact) allocates enough space
// for "count" objects that are "size" bytes of memory each. The 
// allocated memory is filled with bytes of zero value.

// Assignment: Recreate Standard C library function calloc(3).
// Paramaters: 
// Return Value: A pointer to the allocated memory.

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, (count * size));
	return (p);
}
