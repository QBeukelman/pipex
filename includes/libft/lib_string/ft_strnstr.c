/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:49:59 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:54:45 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// The strnstr function locates the first occurrence of the
// null-terminated string needle in the string heystack, where
// not more than len characters are searched. Characters that 
// appear after a '\0' character are not searched. Since the 
// strnstr() function is a freeBSD specific API, it shoult only
// be used when portability is not a concern.

// Assignment: Recreate Standard C library function strnstr(3).
// Paramaters: const string heystack, const string needle, len.
// Return Value: If needle is an empty string, heystack is returned, 
// if needle occurs nowhere in heystack, NULL is returned, 
// otherwise a pointer to the first character of the first 
// occurrence of needle is returned.

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && needle[j] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			while (haystack[i + j] == needle[j] && (i + j) < len)
			{
				if (needle[j + 1] == '\0')
					return ((char *)haystack + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
