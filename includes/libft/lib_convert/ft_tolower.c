/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:29:44 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:52:15 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// The toupper function converts an upper-case letters into the 
// corresponding lower-case letter.
//
// Assignment: Recreate Standard C library function tolower(3).
// Paramaters: int c, or possibly an ascii or extended ascii character.
// Return Value: If the argument is an upper-case letter, the fuction
// returns the corresponding lower-case letter. Otherwise, the argument is
// unchanged.

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
