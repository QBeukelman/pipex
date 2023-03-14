/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 11:07:48 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2022/12/02 11:52:03 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Converts the inital portion of the string pointed to
// by str to int representation.

// Assignment: Recreate Standard C library function atoi(3).
// Paramaters: string pointed to by str.
// Return Value: Returns the int value of the first set of
// consecutive neumeric characters found in the string str.

int	ft_atoi(const char *str)
{
	int			i;
	int			minus_sign;
	long long	result;

	i = 0;
	minus_sign = 1;
	result = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		minus_sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (minus_sign * result);
}
