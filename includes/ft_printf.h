/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:19:54 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/08 22:11:44 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"

# define N 100

typedef enum		e_length
{
	NONE, HH, H, LL, L
}					t_length;

/*
**	format		-	string
**	f_copy		-	copy of string
**	f_print		-	string that print after '%'
**	len			-	length of string
**	i			-	counter of reading string
**	prec_set	-	flag shows if precision was set or wasn't
*/

typedef struct		s_data
{
	const char		*format;
	char			*f_copy;
	char			*f_print;
	int				len;
	size_t			i;

	char			sep;
	int				min_width;
	int				precision;
	int				prec_set;
	char			type;
	char			sign;

	t_length		length;

	int				hash;
	int				zero;
	int				minus;
	int				plus;
	int				space;

	// need to be done f F (l L)

}					t_data;


int					ft_printf(const char *format, ...);

t_data				*initialize(const char *format);
void				ft_free(t_data *ptr);

void				parser(t_data *ptr, va_list arg);

void				parse_conversion(t_data *ptr, va_list arg);
void				parse_length(t_data *ptr);
void				parse_precision(t_data *ptr, va_list arg);
void				parse_min_width(t_data *ptr);
void				parse_flags(t_data *ptr);


void				print_nbr_conv(t_data *ptr, va_list arg);

void				check_if_alias(t_data *ptr);
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


#endif
