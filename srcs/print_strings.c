/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 23:10:12 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/08 19:57:51 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(t_data *ptr, char c)
{
	int len;
	char s;

	s = c;
	len = print(ptr, &s, 0);
	return (len);
}

int			print_str(t_data *ptr, char *str)
{
	if (!str)
		str = "(null)";
	int len;

	len = ft_strlen(str);
	if (ptr->conv->prec_set)
	{
		if (len > ptr->conv->precision)
			len = print(ptr, str, ptr->conv->precision);
	}
	else
		len = print(ptr, str, 0);
	return (len);
}

void		print_str_conv(t_data *ptr, va_list arg)
{
	if (ptr->conv->type == 'c')
		ptr->len += print_char(ptr, va_arg(arg, int));
	else if (ptr->conv->type == 's')
		ptr->len += print_str(ptr, va_arg(arg, char*));
	else
		ptr->len += print_char(ptr, ptr->conv->type);
}