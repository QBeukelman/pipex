/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 08:58:08 by qbeukelm      #+#    #+#                 */
/*   Updated: 2022/12/02 12:27:01 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// About:
// This project is about programming a function that returns a line read from a
// file descriptor

// Parameters:
// fd: The file descriptor to read from

// Return value:
// Read line, correct behavour. Or, NULL if there is nothing else to read, or
// an error occured.

/* Read from fd, up to the first buffer size including the new line character */
char	*ft_read_and_save(int fd, char *line_saved)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(buff))
		return (NULL);
	read_bytes = 1;
	while (!(ft_gnl_strchr(line_saved, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(line_saved);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		line_saved = ft_gnl_strjoin(line_saved, buff);
	}
	free (buff);
	return (line_saved);
}

/* Save the final version of line_saved and return it */
char	*ft_save(char *line_saved)
{
	int		i;
	int		j;
	int		len;
	char	*temp_str;

	i = 0;
	while (line_saved[i] && line_saved[i] != '\n')
		i++;
	if (!(line_saved[i]))
	{
		free(line_saved);
		return (NULL);
	}
	if (line_saved == NULL)
		return (NULL);
	len = ft_gnl_len(line_saved);
	temp_str = (char *)malloc((sizeof(char) * (len - (i++ + 1) + 1)));
	if (!(temp_str))
		return (NULL);
	j = 0;
	while (line_saved[i] && i < len)
		temp_str[j++] = line_saved[i++];
	temp_str[j] = '\0';
	free(line_saved);
	return (temp_str);
}

/* Create a duplicate of line_saved called "str" */
void	ft_str_dup(char *line_saved, char *str, int i)
{
	while (line_saved[i] && line_saved[i] != '\n')
	{
		str[i] = line_saved[i];
		i++;
	}
	if (line_saved[i] == '\n')
	{
		str[i] = line_saved[i];
		i++;
	}
	str[i] = '\0';
}

/* Check end of line for characters after '\n' and remove them */
char	*ft_process_line(char *line_saved)
{
	int		i;
	char	*str;

	i = 0;
	if (line_saved == NULL)
		return (NULL);
	while (line_saved[i])
	{
		if (line_saved[i] == '\n')
			break ;
		i++;
	}
	if (line_saved[i] == '\n')
		str = (char *)malloc(sizeof(char) * (i + 2));
	else
		str = (char *)malloc(sizeof(char) * (i + 1));
	if (!(str))
		return (NULL);
	i = 0;
	ft_str_dup(line_saved, str, i);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_saved = 0;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	line_saved = ft_read_and_save(fd, line_saved);
	if (!(line_saved))
	{
		free (line_saved);
		return (NULL);
	}
	line = ft_process_line(line_saved);
	if (line[0] == '\0' || line == NULL)
	{
		free (line);
		line = NULL;
	}
	line_saved = ft_save(line_saved);
	return (line);
}
