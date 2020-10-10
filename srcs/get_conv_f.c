/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:06:45 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/11 00:28:14 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					length_of_nbr(long double nbr)
{
	int				i;

	i = 0;
	while (nbr >= 1)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void				round_float_nb(t_data *ptr, long double nbr)
{
	long int		temp;
	int				prec;
	int				len_fractional;

	temp = (long int)nbr;
	nbr = nbr - temp;
	prec = ptr->precision + 1;
	while (prec)
	{
		nbr *= 10;
		temp = (long int)nbr;
		prec--;
	}
	len_fractional = length_of_nbr(nbr / 10);
	if (temp % 10 >= 5)
		nbr = nbr / 10 + 1;
	else
		nbr = nbr / 10;
	if ((len_fractional || ptr->precision)
			&& len_fractional != (length_of_nbr(nbr)))
		ptr->int_part_f++;
	ptr->fractional = (int)nbr;
}

int					ft_save_f(t_data *ptr, int i)
{
	if (ptr->fractional != 0)
	{
		ptr->f_print[--i] = '0' + (ptr->fractional % 10);
		ptr->flag++;
		while ((ptr->fractional /= 10) > 0)
		{
			ptr->f_print[--i] = '0' + (ptr->fractional % 10);
			ptr->flag++;
		}
		if (ptr->flag != ptr->precision)
			ptr->f_print[--i] = '0';
		ptr->f_print[--i] = '.';
	}
	else
	{
		while (ptr->precision > 49 - i)
			ptr->f_print[--i] = '0';
		ptr->f_print[--i] = '.';
	}
	return (i);
}

int					ft_print_f(t_data *ptr)
{
	int				len;
	int				i;

	len = 0;
	i = 99;
	i = ft_save_f(ptr, i);
	if (ptr->sign == '-')
		ptr->f_print[--i] = '0';
	ptr->f_print[--i] = '0' + (ptr->int_part_f % 10);
	while ((ptr->int_part_f /= 10) > 0)
		ptr->f_print[--i] = '0' + (ptr->int_part_f % 10);
	len += print(ptr, ptr->f_print + i, 0);
	return (len);
}

void				get_f(t_data *ptr, va_list arg)
{
	long double		nbr;

	if (ptr->length == LF)
		nbr = va_arg(arg, long double);
	else
		nbr = va_arg(arg, double);
	ptr->flag = 0;
	if (!(ptr->prec_set))
		ptr->precision = 6;
	if (nbr < 0 && (nbr *= -1))
		ptr->sign = '-';
	ptr->int_part_f = (long int)nbr;
	round_float_nb(ptr, nbr);
	ptr->len += ft_print_f(ptr);
}
