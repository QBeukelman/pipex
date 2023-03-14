/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:07:47 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:54:25 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Allocate (with malloc(3)) and returns a new string,
// which is the result of the concatenation of s1 & s2.

// Paramaters: 
// s1: The prefix string.
// s2: The suffix string.

// Return Value: The new string. Null if the allocation
// fails.

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_length;
	char	*p;

	i = 0;
	j = 0;
	total_length = ft_strlen(s1) + ft_strlen(s2);
	p = malloc((total_length + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i <= total_length)
	{
		if (i < ft_strlen(s1))
			p[i] = s1[i];
		if (i >= ft_strlen(s1) && i <= total_length)
		{
			p[i] = s2[j];
			j++;
		}
		i++;
	}
	if (p == NULL)
		return (NULL);
	return (p);
}
