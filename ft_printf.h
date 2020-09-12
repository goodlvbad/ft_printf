/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:19:54 by oearlene          #+#    #+#             */
/*   Updated: 2020/09/12 17:56:25 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <ctype.h>

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"

# include <stdio.h>


typedef struct			s_flags
{
	int					pound;
	int					zero;
	int					minus;
	int					plus;
	int					space;
}						t_flags;

typedef enum			e_modifier
{
	NONE, HH, H, LL, L, J, Z
}						t_modifier;

typedef struct			s_conversion
{
	char				sep;
	long int			min_width;
	long int			precision;
	int					prec_set;
	char				type;
	char				sign;
}						t_conversion;


typedef struct		s_data
{
	const char		*format; // string
	char			*f_copy; // copy of string
	char			*f_print; // copy of string that print after '%'
	int				len; // length of string
	size_t			i; // counter of reading string

	t_conversion	*conv;
	t_modifier		modif;
	t_flags			*flags;


	/*
	int 		counter;
	char 		*flags;
	char 		*type;
	char		c;
	int 		true;

	long int	field_width; // 0-9
	long int	precision; // '.#'

	int 		length; // ll l hh h

*/

}				t_data;


int				ft_printf(const char *format, ...);
int				parser(t_data *ptr);
int				next_parser(t_data *ptr);





t_data			*initialize(t_data *ptr, const char *format);



#endif //FT_PRINTF_H
