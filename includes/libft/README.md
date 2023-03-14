


# 42_libft

libft, or library 42, is the first assignemnt in the Codam Core 
curriculum. The objective is to recreate a set of functions in the Standard C Library, and several additional functions.

> For more information visit: [Codam.nl](https://www.codam.nl "Codam.nl") or [42 Cursus Subjects](https://github.com/Surfi89/42cursus/tree/main/Subject%20PDFs "42 Cursus Subjects")

<br />


# Functions


### `lib_check`

```c
  int  ft_isalpha(int c);
  int  ft_isdigit(int c);
  int  ft_isalnum(int c);
  int  ft_isascii(int i);
  int  ft_isprint(int c);
```

### `lib_convert`

```c
  int  	ft_toupper(int c);
  int  	ft_tolower(int c);
  int  	ft_atoi(const  char  *str);
  char  *ft_itoa(int n);
```

### `lib_memory`

```c
  void  *ft_memset(void  *b, int c, size_t len);
  void  ft_bzero(void  *s, size_t n);
  void  *ft_memcpy(void  *dst, const  void  *src, size_t n);
  void  *ft_memmove(void  *dst, const  void  *src, size_t len);
  void  *ft_memchr(const  void  *s, int c, size_t n);
  int  	ft_memcmp(const  void  *s1, const  void  *s2, size_t n);
  void  *ft_calloc(size_t count, size_t size);
```

### `lib_string`

```c
  size_t  	ft_strlcpy(char  *dst, const  char  *src, size_t dstsize);
  size_t 	ft_strlcat(char  *dst, const  char  *src, size_t dstsize);
  char  	*ft_strchr(const  char  *s, int c);
  char  	*ft_strrchr(const  char  *s, int c);
  int  		ft_strncmp(const  char  *s1, const  char  *s2, size_t n);
  char  	*ft_strnstr(const  char  *haystack, const  char  *needle, size_t len);
  char  	*ft_strdup(const  char  *str);
  size_t  	ft_strlen(const  char  *s);
  char  	*ft_substr(char  const  *s, unsigned  int start, size_t len);
  char  	*ft_strjoin(char  const  *s1, char  const  *s2);
  char  	**ft_split(char  const  *s, char c);
  char  	*ft_strtrim(char  const  *s1, char  const  *set);
```

### `lib_apply`

```c
  char  *ft_strmapi(char  const  *s, char (*f)(unsigned  int, char));
  void  ft_striteri(char  *s, void (*f)(unsigned  int, char*));
```

### `lib_file_descriptor`

```c
  void  ft_putchar_fd(char c, int fd);
  void  ft_putstr_fd(char  *s, int fd);
  void  ft_putendl_fd(char  *s, int fd);
  void  ft_putnbr_fd(int n, int fd);
```

### `lib_linked_list`

```c
  t_list  	*ft_lstnew(void  *content);
  void  	ft_lstadd_front(t_list  **lst, t_list  *new);
  int  		ft_lstsize(t_list  *lst);
  t_list  	*ft_lstlast(t_list  *lst);
  void  	ft_lstadd_back(t_list  **lst, t_list  *new);
  void 		ft_lstdelone(t_list  *lst, void (*del)(void  *));
  void  	ft_lstclear(t_list  **lst, void (*del)(void  *));
  void  	ft_lstiter(t_list  *lst, void (*f)(void  *));
  t_list  	*ft_lstmap(t_list  *lst, void  *(*f)(void  *), void (*del)(void  *));
```

### `ft_printf`

```c
  int  ft_printf(const  char  *input, ...);
```

### `ft_get_next_line`

```c
  char  *get_next_line(int fd);
```
<br />


# Usage

#### Requirements

The functions are written in C language and therefore require the `gcc` **compiler** and some **standard C libraries** to run.

#### Instructions

#### 1. Compile the library

To compile, go to the library path directory and run:

```bash
  make
```
```bash
  make clean
```
```bash
  gcc main.c -L. libft.a && ./a.out
```

#### 2. Use the library

Include the following header to your `.c` file:

```c
  #include "includes/ft_libft.h"
```

<br />


# Testing

You can use this third party tester to measure the capability of the library:

- [Francinette](https://github.com/xicodomingues/francinette "Francinette")

<br />
