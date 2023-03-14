/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 08:43:15 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:51:22 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Assignment: Recreate Standard C library function isalnum(3).
// Paramaters: integer c, possibly as ascii character.
// Return Value: 1 if the character is either a capital or lower case 
// alphebetical, or neumeric character, and 0 if the character tests false.

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
