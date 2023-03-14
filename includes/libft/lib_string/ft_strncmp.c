/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:36:20 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:54:41 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Strncmp lexicographically compares the null terminated
// strings s1 and s2. The function compares not more that n
// characters.
//
// Assignment: Recreate Standard C library function strncmp(3).
// Paramaters: string 1 (s1), string 2 (s2), size_t n.
// Return Value: Zero if s1 and s2 are equal. Negative value
// if the first charachter that does not matach has a lower
// value in s1 than in s2. Positive value if the first 
// character that does not match has a greater value in s1
// than in s2.

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	result = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (result);
}
