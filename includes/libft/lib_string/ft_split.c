/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:12:31 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 11:54:14 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Allocate (with malloc(3)) and return an array of strings
// obtained by splitting 's' using the character 'c' as a 
// delimiter. The array must end with a NULL pointer.

// Paramaters:
// s: The string to be split.
// c: The delimiter character.

// Return Value: The array of new strings resulting from the
// split. NULL if the allocation fails.

// https://www.youtube.com/watch?v=Vp6OELK4gmo

int		count_substrings(char const *s, char c, int len, int count);
char	**allocate_strings_buff(char const *s, char c, int len, char **strings);
int		check_beginning(char const *s, char c, int i, int len);
char	**allocate_strings(char **strings, char *buffer, int j, int *str_index);

char	**ft_split(char const *s, char c)
{
	int		len;
	int		count;
	char	**strings;

	count = 0;
	len = ft_strlen(s);
	count = count_substrings(s, c, len, count);
	strings = malloc(sizeof(char *) * (count + 1));
	if (strings == NULL)
	{
		free (strings);
		return (NULL);
	}
	strings = allocate_strings_buff(s, c, len, strings);
	return (strings);
}

int	count_substrings(char const *s, char c, int len, int count)
{
	int		i_check;
	int		i;

	i_check = 0;
	i = 0;
	while (i < len)
	{
		i = check_beginning(s, c, i, len);
		i_check = i;
		while (i < len)
		{
			if (s[i] == c)
				break ;
			i++;
		}
		if (i > i_check)
			count++;
	}
	return (count);
}

char	**allocate_strings_buff(char const *s, char c, int len, char **strings)
{
	int		i;
	int		j;
	int		str_index;
	char	buffer[1000];

	j = 0;
	i = 0;
	str_index = 0;
	while (i < len)
	{
		i = check_beginning(s, c, i, len);
		j = 0;
		while (i < len)
		{
			if (s[i] == c)
				break ;
			buffer[j] = s[i];
			i++;
			j++;
		}
		strings = allocate_strings(strings, buffer, j, &str_index);
	}
	strings[str_index] = 0;
	return (strings);
}

char	**allocate_strings(char **strings, char *buffer, int j, int *str_index)
{
	if (j > 0)
	{
		buffer[j] = '\0';
		strings[*str_index] = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
		ft_strlcpy(strings[*str_index], buffer, (ft_strlen(buffer) + 1));
		*str_index = *str_index + 1;
	}
	return (strings);
}

int	check_beginning(char const *s, char c, int i, int len)
{
	while (i < len)
	{
		if (s[i] != c)
			break ;
		i++;
	}
	return (i);
}
