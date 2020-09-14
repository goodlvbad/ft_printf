/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:19:15 by oearlene          #+#    #+#             */
/*   Updated: 2020/09/14 16:23:51 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


t_data	*initialize(t_data *ptr)
{
	ptr->len = 0;
	ptr->i = 0;
	ptr->length = NONE;
	ptr->f_copy = (char *)ptr->format;
	ft_bzero(ptr->f_print, 100);
	ptr->flags->hash = 0;
	ptr->flags->zero = 0;
	ptr->flags->minus = 0;
	ptr->flags->plus = 0;
	ptr->flags->space = 0;
	ptr->conv->sign = 0;
	ptr->conv->sep = 0;
	ptr->conv->min_width = 0;
	ptr->conv->precision = 0;
	ptr->conv->prec_set = 0;
	ptr->conv->type = 0;
	return (ptr);
}


void		next_parser(t_data *ptr, va_list arg)
{
	ptr->i++;
	parse_conversion(ptr);
// add '%%'
// need to be done

	if (ft_strchr("idouxX", ptr->conv->type))
		print_nbr_conv(ptr, arg);
	//else
		//print_str_conv(ptr, arg);
}



void		parser(t_data *ptr, va_list arg)
{
	while (ptr->f_copy[ptr->i] != '\0')
	{
		if (ptr->f_copy[ptr->i] == '%')
		{
			next_parser(ptr,arg);
		}
		else
		{
			write(1,&(ptr->f_copy[ptr->i]),1);
			ptr->len++;
		}
		ptr->i++;
	}
}



int		ft_printf(const char *format, ...)
{
	t_data *ptr;
	va_list	args;

	ptr->format = format;
	ptr = initialize(ptr);
	if (format)
	{
		va_start(args, format);
		parser(ptr, args);
		va_end(args);
	}
	else
		return (-1);
	return (ptr->len);
}