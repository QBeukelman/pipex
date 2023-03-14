/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:06:50 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:54:56 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Allocates (with malloc(3)) and returns a substring
// from s. The substring begins at indes "start", and
// is of maximum size "len".

// Paramaters: 
// s: the string from which to create the substring. 
// start: the start index of the substring in the 
// substring s. 
// len: the maximum length of the substring.

// Return Value: The substring. NULL if the allocation
// fails.

size_t	check_len(char const *s, unsigned int *start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	unsigned int	j;

	len = check_len(s, &start, len);
	p = malloc((len + 1) * sizeof(*s));
	if (p == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			p[j] = s[i];
			j++;
		}
		i++;
	}
	p[j] = '\0';
	return (p);
}

size_t	check_len(char const *s, unsigned int *start, size_t len)
{
	unsigned int	s_size;

	s_size = ft_strlen(s);
	if (*start > s_size)
	{
		*start = s_size;
		len = 0;
	}
	else if (s_size < *start + len)
		len = s_size - *start;
	return (len);
}
