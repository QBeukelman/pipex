/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:08:28 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:54:53 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Allocate (with malloc(3)) and return a copy of s1 with
// the characters specified in "set" removed from the 
// beginning and the end of the string.

// Paramaters: 
// s1: The string to be trimmed
// set: The reference set of characters to trim.

// Return Value: The trimmed string. Null if the allocation
// fails.

int	char_exists(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*new_str;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && char_exists(s1[start], set))
		start++;
	while (end > start && char_exists(s1[end - 1], set))
		end--;
	new_str = malloc((end - start + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (start < end)
	{
		new_str[i] = s1[start];
		start++;
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
