/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:19:15 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/08 22:09:45 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_free(t_data *ptr)
{
	ptr->format = NULL;
	ft_strdel(&(ptr->f_copy));
	ft_strdel(&(ptr->f_print));
	free(ptr);
	ptr = NULL;
}

t_data	*initialize(const char *format)
{
	t_data *ptr;

	if (!(ptr = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	ptr->format = format;
	ptr->f_copy = ft_strdup(ptr->format);
	ptr->len = 0;
	ptr->i = 0;
	ptr->length = NONE;
	ptr->f_print = ft_strnew(N);
	ptr->hash = 0;
	ptr->zero = 0;
	ptr->minus = 0;
	ptr->plus = 0;
	ptr->space = 0;
	ptr->sign = 0;
	ptr->sep = 0;
	ptr->min_width = 0;
	ptr->precision = 0;
	ptr->prec_set = 0;
	ptr->type = 0;
	ptr->flag = 0;
	return (ptr);
}

void		parser(t_data *ptr, va_list arg)
{
	while (ptr->f_copy[ptr->i] != '\0')
	{
		if (ptr->f_copy[ptr->i] == '%')
		{
			ptr->i++;
			parse_conversion(ptr, arg);
			if (ft_strchr("idouxX", ptr->type))
				print_nbr_conv(ptr, arg);
			else
				print_str_conv(ptr, arg);
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

	ptr = initialize(format);
	if (format)
	{
		va_start(args, format);
		parser(ptr, args);
		va_end(args);
	}
	else
		return (-1);
	ft_free(ptr);
	return (ptr->len);
}