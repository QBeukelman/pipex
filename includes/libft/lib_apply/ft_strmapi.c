/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:14:11 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:51:06 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Apply the function 'f' to each character of the string 's',
// and passing its index as the first argument to create a new
// string (with malloc(3)) resulting from the successive
// applications of 'f'.

// Paramaters:
// s: the string on which to iterate.
// f: the function to apply to each character.

// Return Value: The string created from the successive
// applications of 'f'.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	p = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
