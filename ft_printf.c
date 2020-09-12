/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:19:15 by oearlene          #+#    #+#             */
/*   Updated: 2020/09/12 17:40:50 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*initialize(const char *format)
{
	t_data *ptr;

	ptr->format = format;
	ptr->len = 0;
	ptr->i = 0;
	ptr->modif = NONE;
	ptr->f_copy = (char *)ptr->format;
	ptr->f_print = (char *)ptr->format;
	return (ptr);
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

	// return (length of string)
	return (ptr->len);
}

{
	va_list			ap;
	char			*str;

	va_start(ap, format);
	str = (char *)format;
	while (*str != '\0')
	{
		str = print_until(str, '%');
		if (*str == '%')
		str++;
		if (*str != '\0')
		str = print_conversion(str, ap);
	}
	va_end(ap);
	return (tally_get(0, 0));
}


