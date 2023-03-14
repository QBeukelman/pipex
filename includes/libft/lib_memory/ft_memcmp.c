/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:38:47 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:53:55 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Compare byte string s1 against byte string s2.
// Both strings are assumed to be n bytes long.
//
// Assignment: Recreate Standard C library function memcmp(3).
// Paramaters: constant string s1, constant string s2, size_t n.
// Return Value: Zero if the two strings are identical. Otherwise
// returns the differance between the first two differing bytes.
// Zero length strings are always identical.

int	ft_strncmp_edit(const char *s1, const char *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		result;
	size_t	s1_len;
	size_t	s2_len;

	result = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len > s2_len)
		result = (ft_strncmp_edit((const char *)s2, (const char *)s1, n) * -1);
	else
		result = ft_strncmp_edit((const char *)s1, (const char *)s2, n);
	return (result);
}

int	ft_strncmp_edit(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1)
		i++;
	result = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (result);
}
