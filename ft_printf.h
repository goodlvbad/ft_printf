/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:19:54 by oearlene          #+#    #+#             */
/*   Updated: 2020/09/18 22:10:38 by oearlene         ###   ########.fr       */
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


typedef struct		s_flags
{
	int				hash;
	int				zero;
	int				minus;
	int				plus;
	int				space;
}					t_flags;

typedef enum		e_length
{
	NONE, HH, H, LL, L
}					t_length;

typedef struct		s_conversion
{
	char			sep;
	int				min_width;
	int				precision;
	int				prec_set; // is precision set or no
	char			type;
	char			sign;
}					t_conversion;


typedef struct		s_data
{
	const char		*format; // string
	char			*f_copy; // copy of string
	char			f_print[100]; // copy of string that print after '%'
	int				len; // length of string
	size_t			i; // counter of reading string

	t_conversion	*conv;
	t_length		length;
	t_flags			*flags;

	// need to be done f F (l L)

}					t_data;


int					ft_printf(const char *format, ...);

t_data				*initialize(t_data *ptr);

void				parser(t_data *ptr, va_list arg);

void				parse_conversion(t_data *ptr, va_list arg);
void				parse_length(t_data *ptr);
void				parse_precision(t_data *ptr, va_list arg);
void				parse_min_width(t_data *ptr);
void				parse_flags(t_data *ptr);


void				print_nbr_conv(t_data *ptr, va_list arg);

static void			check_if_alias(t_data *ptr);
unsigned long long	get_conv_unsign(t_data *ptr, va_list arg);
long long			get_conv_sign(t_data *ptr, va_list arg);

int					print(t_data *ptr, char *str, int size);
int					print_spacing(int len, int min, char c);
void				ft_putstr_sized(char *str, int size);

int					print_u(t_data *ptr, unsigned long long num);
int					print_d(t_data *ptr, long long num);
int					print_o(t_data *ptr, unsigned long long n);
int					print_x(t_data *ptr,unsigned long long n);
int					print_x_caps(t_data *ptr,unsigned long long n);

void				print_str_conv(t_data *ptr, va_list arg);
int					print_str(t_data *ptr, char *str);
int					print_char(t_data *ptr, char c);


#endif //FT_PRINTF_H
