/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 08:52:30 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:54:03 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// The memmove function copies len bytes from string src to string dst. If the
// two strings overlap, the copy is always non-distructive. The memmove function
// is similar to memcpy, however here we have to handle the overlapping 
// scenario.
//
// Assignment: Recreate Standard C library function memmove(3).
// Paramaters: string src, string dst, int len.
// Return Value: Memcpy is a void function. However it returns the orignal 
// value of dst, copied to the source, src.
//
// Notes:
// We need to type cast src and dst addresses to (char *).
// Also we allocate memory for a temp array.
// The memmove function is slower in comparison to memcpy because in memmove 
// extra temporary array is used to copy n characters from the source and after 
// that, it uses to copy the stored characters to the destination memory. The 
// memcpy is useful in forwarding copy but memmove is useful in case of 
// overlapping scenarios.

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*p_src;
	char			*p_dst;
	size_t			i;

	p_src = (char *)src;
	p_dst = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (p_dst > p_src)
		while (len-- > 0)
			p_dst[len] = p_src[len];
	else
	{
		while (i < len)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	return (dst);
}
