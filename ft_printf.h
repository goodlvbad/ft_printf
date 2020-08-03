

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <ctype.h>

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "../libft/libft.h"

# include <stdio.h>


typedef struct	s_data
{
	const char	*format; // string
	char		*f_copy; // copy of string
	char		*f_print; // copy of string that print before '%'
	int			len; // length of string
	size_t		i; // counter of reading string

	int 		minus; // '-'
	int 		plus; // '+'
	int 		space; // ' '
	int 		hash; // '#'
	int 		zero; // '0'

	long int	field_width; // 0-9
	long int	precision; // '.#'

	int 		length; // ll l hh h


}				t_data;


int				ft_printf(const char *format, ...);
int				parser(t_data *ptr);
int				next_parser(t_data *ptr);





t_data			*initialize(t_data *ptr, const char *format);



#endif //FT_PRINTF_H
