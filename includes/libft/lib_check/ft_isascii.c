/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 08:44:02 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:51:35 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Assignment: Recreate Standard C library function isascii(3).
// Paramaters: integer c
// Return Value: The manual does not specify. The ft_isascii function returns
// 1 if c is within the range of the extended ascci table.
//
// Notes:
// octal 0177 is decimal 127, hence 

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
