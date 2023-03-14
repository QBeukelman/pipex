
# ft_printf

This assigment is to discover a popular and versatile C function `printf()`. This exercise is a great opportunity to improve programming skills. It is of moderate difficulty and introduces `variadic functions` in C.

> For more information visit: [Codam.nl](https://www.codam.nl "Codam.nl") or [42 Cursus Subjects](https://github.com/Surfi89/42cursus/tree/main/Subject%20PDFs "42 Cursus Subjects")

<br />


# Function

### `ft_printf`

```c
  int	ft_printf(const char *input, ...);
```

> **Parameters:** A string as mandatory first argument and a varying number of optional parameters, defined by the possible format specifiers.

> **Return Value:** The number; as an integer, of characters printed (not including the trailing ‘\0’.

> `%c` Prints a single character.
> 
> `%s` Prints a string (as defined by the common C convention).
> 
> `%p` The void * pointer argument has to be printed in hexadecimal format.
> 
> `%d` Prints a decimal (base 10) number.
> 
> `%i` Prints an integer in base 10.
> 
> `%u` Prints an unsigned decimal (base 10) number.
> 
> `%x` Prints a number in hexadecimal (base 16) lowercase format.
> 
> `%X` Prints a number in hexadecimal (base 16) uppercase format.
> 
> `%%` Prints a percent sign.


<br />


# Accessories

#### `Tools`
```c
  int 	ft_putchar(int c);
  int  	ft_printstring(char  *str);
  void  ft_putstr(char  *str);
  int  	ft_print_dec(int number);
```
#### `Pointers`
```c
  int  	ft_print_p(unsigned  long  long p);
  void  ft_ptr_hex(uintptr_t number);
  int  	ft_count_p(uintptr_t number);
```
#### `Unsigned`
```c
  int  	ft_print_unsigned(unsigned  int nbr);
  char  *ft_itoa_unsigned( unsigned  int nbr);
  int  	ft_number_len(unsigned  int nbr);
```
#### `Hex`
```c
  int  ft_print_hex(unsigned  int nbr, const  char format);
  void  ft_put_hex(unsigned  int nbr, const  char format);
  int  ft_hex_length(unsigned  int nbr);
```
<br />
