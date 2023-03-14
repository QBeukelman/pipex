/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_unsigned.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 09:24:56 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 12:17:50 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_number_len(unsigned int nbr)
{
	int	char_count;

	char_count = 0;
	while (nbr != 0)
	{
		char_count++;
		nbr = nbr / 10;
	}
	return (char_count);
}

char	*ft_itoa_unsigned( unsigned int nbr)
{
	char	*nbr_str;
	int		char_count;

	char_count = ft_number_len(nbr);
	nbr_str = (char *)malloc((char_count + 1) * sizeof(char));
	if (nbr_str == NULL)
		return (0);
	nbr_str[char_count] = '\0';
	while (nbr != 0)
	{
		nbr_str[char_count - 1] = nbr % 10 + 48;
		nbr = nbr / 10;
		char_count--;
	}
	return (nbr_str);
}

int	ft_print_unsigned(unsigned int nbr)
{
	int		char_count;
	char	*nbr_str;

	char_count = 0;
	if (nbr == 0)
		char_count += ft_putchar('0');
	else
	{
		nbr_str = ft_itoa_unsigned(nbr);
		char_count += ft_printstring(nbr_str);
		free (nbr_str);
	}
	return (char_count);
}
