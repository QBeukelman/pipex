/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qbeukelm <qbeukelm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 10:01:20 by qbeukelm      #+#    #+#                 */
/*   Updated: 2023/03/09 11:49:33 by qbeukelm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdarg.h>

// -- LIBFT --
// Linked list struct
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Check
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int i);
int			ft_isprint(int c);

// Convert
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);

// Memory
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);

// String
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *str);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		*ft_strtrim(char const *s1, char const *set);

// Apply
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

// File Descriptor
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// Linked List
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// -- PRINTF --
// Print
int			ft_printf(const char *input, ...);

// Tools
int			ft_putchar(int c);
int			ft_printstring(char *str);
void		ft_putstr(char *str);
int			ft_print_dec(int number);

// Pointers
int			ft_print_p(unsigned long long p);
void		ft_ptr_hex(uintptr_t number);
int			ft_count_p(uintptr_t number);

// Unsigned
int			ft_print_unsigned(unsigned int nbr);
char		*ft_itoa_unsigned( unsigned int nbr);
int			ft_number_len(unsigned int nbr);

// Hex
int			ft_print_hex(unsigned int nbr, const char format);
void		ft_put_hex(unsigned int nbr, const char format);
int			ft_hex_length(unsigned int nbr);

// -- GET NEXT LINE --
// get_next_line
char		*get_next_line(int fd);
char		*ft_read_and_save(int fd, char *saved_line);
char		*ft_save(char *line_saved);
void		ft_str_dup(char *saved_line, char *str, int i);
char		*ft_process_line(char *line_saved);

// utils
char		*ft_gnl_strchr(char *s, int c);
size_t		ft_gnl_strlen(char *str);
char		*ft_gnl_strjoin(char *s1, char *s2);
int			ft_gnl_len(char *saved_line);

#endif // LIBFT_H
