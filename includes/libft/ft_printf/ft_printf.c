/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 10:23:30 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2022/12/02 12:17:56 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Recreate the function printf(1). Do not implement the buffer management of
// the orignal prinft. The ft_printf should hande the following conversions:

/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format. 
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/

#include "../includes/libft.h"

int	check_string(const char c)
{
	char	*format;

	format = "cspdiuxX%";
	if (ft_strchr(format, c))
		return (1);
	else
		return (0);
	return (1);
}

int	conversions(va_list args, const char format)
{
	int		char_count;

	char_count = 0;
	if (format == 'c')
		char_count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		char_count += ft_printstring(va_arg(args, char *));
	else if (format == 'p')
		char_count += ft_print_p(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		char_count += ft_print_dec(va_arg(args, int));
	else if (format == 'u')
		char_count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		char_count += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
	{
		char_count += 1;
		ft_putchar('%');
	}
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	int			i;
	int			char_count;
	va_list		args;

	i = 0;
	char_count = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			if (!(check_string(input[i + 1])))
				char_count += ft_putchar(input[i + 1]);
			if (input[i + 1] == '\0')
				break ;
			char_count += conversions(args, input[i + 1]);
			i++;
		}
		else
			char_count += ft_putchar(input[i]);
		i++;
	}
	va_end(args);
	return (char_count);
}
