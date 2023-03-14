/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_pointers.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 13:00:37 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2022/12/02 12:17:40 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_count_p(uintptr_t number)
{
	int	count;

	count = 0;
	while (number != 0)
	{
		count++;
		number = number / 16;
	}
	return (count);
}

void	ft_ptr_hex(uintptr_t number)
{
	if (number >= 16)
	{
		ft_ptr_hex(number / 16);
		ft_ptr_hex(number % 16);
	}
	else
	{
		if (number <= 9)
			ft_putchar_fd((number + '0'), 1);
		else
			ft_putchar_fd((number - 10 + 'a'), 1);
	}
}

int	ft_print_p(unsigned long long p)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (p == 0)
		len += write(1, "0", 1);
	else
	{
		ft_ptr_hex(p);
		len += ft_count_p(p);
	}
	return (len);
}
