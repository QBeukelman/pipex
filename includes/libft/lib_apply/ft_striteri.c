/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:15:11 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:50:56 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Apply the function 'f' on each character of the string index
// passed as an argument, passing its index as first argument.
// Each character is passed by addres to 'f' to be modified if
// necessary.

// Paramaters:
// s: the string on which to iterate.
// f: the function to apply to each character.

// Return Value: none.

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
