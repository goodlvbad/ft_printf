/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 23:15:09 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/08 21:14:35 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long				get_conv_sign(t_data *ptr, va_list arg)
{
	if (ptr->length == HH)
		return ((char)va_arg(arg, int));
	if (ptr->length == H)
		return ((short)va_arg(arg, int));
	if (ptr->length == L)
		return (va_arg(arg, long));
	if (ptr->length == LL)
		return (va_arg(arg,  long long));
	return (va_arg(arg, int));
}

unsigned long long		get_conv_unsign(t_data *ptr, va_list arg)
{
	if (ptr->length == HH)
		return ((unsigned char)va_arg(arg, unsigned int));
	if (ptr->length == H)
		return ((unsigned short)va_arg(arg, unsigned int));
	if (ptr->length == L)
		return (va_arg(arg, unsigned long));
	if (ptr->length == LL)
		return (va_arg(arg, unsigned long long));
	return (va_arg(arg, unsigned int));
}

void		check_if_alias(t_data *ptr)
{
	if (ptr->type == 'i')
		ptr->type = 'd';
	else if (ptr->type == 'p')
	{
		ptr->length = L;
		ptr->hash = 1;
	}
}

void		print_nbr_conv(t_data *ptr, va_list arg)
{
	unsigned long long	n;
	long long nb;

	check_if_alias(ptr);
	if (ptr->type == 'd')
	{
		nb = get_conv_sign(ptr, arg);
		if (nb < 0 && (nb *= -1))
			ptr->sign = '-';
		else if (ptr->plus)
			ptr->sign = '+';
		else if (ptr->space)
			ptr->sign = ' ';
		ptr->len += print_d(ptr, nb);
	}
	else
		n = get_conv_unsign(ptr, arg);
	if (ptr->type == 'u')
		ptr->len += print_u(ptr, n);
	else if (ptr->type == 'o')
		ptr->len += print_o(ptr, n);
	else if (ft_strchr("xp", ptr->type))
		ptr->len += print_x(ptr, n);
	else if (ptr->type == 'X')
		ptr->len += print_x_caps(ptr, n);
}