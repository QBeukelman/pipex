/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 11:39:19 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2022/12/02 11:54:34 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Copies up to dstsize - 1 characters from the string src to dst,
// NULL-turminating the result if dstsize is not 0.
//
// Assignment: Recreate Standard C library function strlcpy(3).
// Paramaters: string dst, string src, size destsize.
// Return Value: The total length of the string it tried to create. in this case
// that means the length of src.

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize -1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}
