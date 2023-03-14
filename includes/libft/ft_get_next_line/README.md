

# get_next_line

This assigment is to write a function that returns a line read from a `file descriptor`. Repeated calls (e.g., using a loop) to your `get_next_line()` function should let you read the text file pointed to by the file descriptor, one line at a time. Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return `NULL`.

> For more information visit: [Codam.nl](https://www.codam.nl "Codam.nl") or [42 Cursus Subjects](https://github.com/Surfi89/42cursus/tree/main/Subject%20PDFs "42 Cursus Subjects")
<br />


# Function

### `get_next_line`

> **Parameters:** The file descriptor to read from.

> **Return Value:** Read line, correct behavour. Or, NULL if there is nothing else to read, or an error occured.

```c
  char  *get_next_line(int fd);
```
<br />


# Accessories

#### `helpers`
```c
  char  *get_next_line(int fd);
  char  *ft_read_and_save(int fd, char  *saved_line);
  char  *ft_save(char  *line_saved);
  void  ft_str_dup(char  *saved_line, char  *str, int i);
  char  *ft_process_line(char  *line_saved);
```
#### `utils`
```c
  char  	*ft_gnl_strchr(char  *s, int c);
  size_t  	ft_gnl_strlen(char  *str);
  char  	*ft_gnl_strjoin(char  *s1, char  *s2);
  int  		ft_gnl_len(char  *saved_line);
```
<br />


# Usage

### 1. Create a main entry point

Add the following code to a `main.c` file, in the root directory:

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/libft.h"

void run()
{
	char *buffer = NULL;
	int fd  =  open("txt", O_RDONLY);
	if (fd < 0)
		printf("Error opening file!\n");
	if (!get_next_line(42))
		printf("returning NUll\n");
	buffer = get_next_line(fd);
	
	int i = 0;
	while(buffer)
	{
		++i;
		printf("%d: %s", i, buffer);
		free(buffer);
		buffer = NULL;
		buffer = get_next_line(fd);
	}
	printf("\n");
}

int main(void)
{
	run();
	// while (1);
	return (0);
}
```
<br />


### 2. Use the function

Compile all C files to the executable `a.out`, set the `BUFFER_SIZE` and use `cat -e` to check the spacing of the return. 

```shell
  gcc -Wall -Werror -Wextra *.c && ./a.out -D BUFFER_SIZE=2 | cat -e
```
<br />


### 3. Check for leaks

First, add an infinate loop to the main, to keep the program running.

```c
  while (1);
```

Run the program, to start the infinate loop. Open a new terminal and run the code below to search for leaks.

```shell
  leaks a.out
```
<br />
