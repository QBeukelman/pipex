/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 09:57:10 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 12:09:01 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Assignment: Recreate Standard C library function strlen(3).
// Paramaters: const string.
// Return Value: size_t number of characters that precede the 
// terminating NUL character.
// 
// Notes:
// size_t: a base unsigned integer type. The type's size is 
// chosen so that it can store the maximum size of a theoretically
// possible array of any type. On a 32-bit system size_t will take 
// 32 bits, on a 64-bit one 64 bits.

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
