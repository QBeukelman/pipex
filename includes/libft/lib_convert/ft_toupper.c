/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:30:48 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:52:21 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// The toupper function converts lower-case letters into the 
// corresponding upper-case letter.
//
// Assignment: Recreate Standard C library function toupper(3).
// Paramaters: int c, or possibly an ascii or extended ascii character.
// Return Value: If the argument is a lower-case letter, the fuction
// returns the corresponding upper-case letter. Otherwise, the argument is
// unchanged.

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
