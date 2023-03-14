/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:02:24 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:52:09 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Allocate (with malloc(3)) and return a string representing the
// integer recived as an argument. Negative numbers must be
// handled.

// Paramaters:
// n: the integer to convert. 

// Return Value: The string representing the integer. NULL if the
// allocation fails.

int		count_int_characters(int n);
char	*convert(int n, int *i, char *buffer, int n_length);
char	*reverse(char *buffer, int i, int j);

char	*ft_itoa(int n)
{
	int			i;
	int			j;
	int			n_length;
	char		*buffer;

	i = 0;
	j = 0;
	n_length = count_int_characters(n);
	buffer = malloc((n_length + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	buffer = convert(n, &i, buffer, n_length);
	buffer[j] = '\0';
	i = n_length;
	buffer = reverse(buffer, i, j);
	return (buffer);
}

int	count_int_characters(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*convert(int n, int *i, char *buffer, int n_length)
{
	size_t		n_temp;

	n_temp = n;
	if (n < 0)
	{
		n_temp = n_temp * -1;
		buffer[n_length] = '-';
	}
	if (n == 0)
	{
		buffer[*i + 1] = '0';
		*i = *i + 1;
	}
	while (n_temp > 0)
	{
		buffer[*i + 1] = (n_temp % 10) + '0';
		n_temp = n_temp / 10;
		*i = *i + 1;
	}
	return (buffer);
}

char	*reverse(char *buffer, int i, int j)
{
	char		c;

	while (j < i)
	{
		c = buffer[j];
		buffer[j] = buffer[i];
		buffer[i] = c;
		j++;
		i--;
	}
	return (buffer);
}
