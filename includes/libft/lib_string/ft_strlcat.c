/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:04:01 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:54:29 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Appends string src to the end of dst. it will append at most
// dstsize - serlen(dst) - 1 characters.
//
// Assignment: Recreate Standard C library function strlcat(3).
// Paramaters: string dst, string str, int dstsize.
// Return Value: Returns the total number of characters that it
// tried to create. For strlcat, that means the initial length of
// dst plus src.

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	result;
	size_t	src_count;
	size_t	dst_count;
	char	*p_src;

	i = 0;
	result = 0;
	src_count = ft_strlen(src);
	dst_count = ft_strlen(dst);
	p_src = (char *)src;
	if (dst_count < dstsize)
		result = src_count + dst_count;
	else
		result = src_count + dstsize;
	while (p_src[i] && (dst_count + 1) < dstsize)
	{
		dst[dst_count] = p_src[i];
		dst_count++;
		i++;
	}
	dst[dst_count] = '\0';
	return (result);
}
