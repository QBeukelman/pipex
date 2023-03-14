/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:34:36 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:54:17 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// The strchr locates the first occurance of c in the string pointed
// to by s. The terminating character is considered to be part of 
// the string; therefor if c is '\0', the function locates the
// the terminating character
//
// Assignment: Recreate Standard C library function strchr(3).
// Paramaters: string pointed to by s, int c.
// Return Value: A pointer to the located character, or NULL if the
// character does not appear in the string.
//
// Notes:
// const char, means that we are not able to change the values in the
// string pointed to by s. However, we are able to move the pointer to
// the first value.
// It may be surprising that we are using the int type for the second
// argument of the function. The C Programming Languages uses values
// to encode and refer to each character.

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
