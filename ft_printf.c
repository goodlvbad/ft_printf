/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:19:15 by oearlene          #+#    #+#             */
/*   Updated: 2020/09/12 22:05:00 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*initialize(const char *format)
{
	t_data *ptr;

	ptr->format = format;
	ptr->len = 0;
	ptr->i = 0;
	ptr->length = NONE;
	ptr->f_copy = (char *)ptr->format;
	ptr->f_print = (char *)ptr->format;
	return (ptr);
}



int		next_parser(t_data *ptr, va_list arg)
{
	int len;

	len = 0;
	ptr->i++;
	ptr->f_print = parse_conversion(ptr);
// add '%%'
// need to be done

	if (ft_strchr("idouxX", ptr->conv->type))
		len = print_nbr_conv(ptr, arg);
	else
		len = print_str_conv(ptr, arg);

	return (len);
}

int		parser(t_data *ptr, va_list arg)
{
	while (ptr->f_copy[ptr->i] != '\0')
	{
		if (ptr->f_copy[ptr->i] == '%')
		{
			ptr->len += next_parser(ptr, arg);
			ptr->f_copy = ptr->f_print;
			ptr->i = 0;
		}
		else
		{
			write(1,&(ptr->f_copy[ptr->i]),1);
			ptr->len++;
		}
		ptr->i++;
	}
	return (ptr->len);
}



int		ft_printf(const char *format, ...)
{
	t_data *ptr;
	va_list	args;

	ptr = initialize(format);
	if (format)
	{
		va_start(args, format);
		ptr->len = parser(ptr, args);
		va_end(args);
	}

	// return (length of printed string)
	return (ptr->len);
}