/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_tools.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 12:34:25 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2022/12/02 12:17:45 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printstring(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], sizeof(char));
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_dec(int number)
{
	size_t	i;
	char	*str;
	size_t	str_len;

	i = 0;
	str = ft_itoa(number);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	str_len = ft_strlen(str);
	free (str);
	return (str_len);
}
