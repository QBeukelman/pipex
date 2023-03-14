/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:37:13 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:53:51 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Memchr locates the first occurance of c (converted to an
// unsigned char) in string s.
//
// Assignment: Recreate Standard C library function memchr(3).
// Paramaters: contant string s, int c, size_t n.
// Return Value: A pointer to the byte located, or NULL if no such
// byte exists within n bytes.
//
// Notes:
// We can not dereferance a void pointer, because by definition, we
// do not know the type of the pointer. We are able to cast it to a
// char pointer before dereferancing it.

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	character;

	i = 0;
	string = (unsigned char *)s;
	character = (unsigned char)c;
	while (i < n)
	{
		if (*string == character)
		{
			return (string);
		}
		string++;
		i++;
	}
	return (NULL);
}
