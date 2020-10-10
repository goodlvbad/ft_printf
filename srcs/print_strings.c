/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 23:10:12 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/10 20:00:17 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(t_data *ptr, char c)
{
	int len;

	len = 0;
	if (c == '\0')
	{
		write(1, 0, 1);
		len += 1;
		ptr->min_width--;
	}
	else
		ptr->f_print[0] = c;
	len += print(ptr, &ptr->f_print[0], 0);
	return (len);
}

int			print_str(t_data *ptr, char *str)
{
	int len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (ptr->prec_set)
	{
		if (ptr->precision == 0)
			str = "";
		if (len > ptr->precision)
			len = print(ptr, str, ptr->precision);
		else
			len = print(ptr, str, 0);
	}
	else
		len = print(ptr, str, 0);
	return (len);
}

void		print_str_conv(t_data *ptr, va_list arg)
{
	if (ptr->type == 'c')
		ptr->len += print_char(ptr, va_arg(arg, int));
	else if (ptr->type == 's')
		ptr->len += print_str(ptr, va_arg(arg, char*));
	else
		ptr->len += print_char(ptr, ptr->type);
}
