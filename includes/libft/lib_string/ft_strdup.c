/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:05:38 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:54:21 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// strdup allocates sufficient memory for a copy of the string
// s1, does the copy and returns a pointer to it. If insufficient
// memory is available, NULL is returned and errno is set to 
// ENOMEM

// Assignment: Recreate Standard C library function strchr(3).
// Paramaters: string pointed to by s, int c.
// Return Value: A pointer to the located character, or NULL if the
// character does not appear in the string.

// Notes:
// errno is used for reporting system errors. For all practical 
// purposes you can treat errno like a global variable, although
// it is not.

char	*ft_strdup(const char *str)
{
	char	*p;

	p = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, str, ft_strlen(str) + 1);
	return (p);
}
