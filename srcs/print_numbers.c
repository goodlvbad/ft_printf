/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:06:12 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/10 18:15:59 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	check_if_prec_set(t_data *ptr, int nbr)
{
	if (ptr->prec_set)
	{
		ptr->zero = 0;
		if (nbr == 0)
		{
			if (ptr->precision == 0)
				ptr->flag = 1;
		}
	}
}

int		print_u(t_data *ptr, unsigned long long n)
{
	int		len;
	int		i;

	len = 0;
	i = 99;
	check_if_prec_set(ptr, (int)n);
	if (!ptr->flag)
		ptr->f_print[--i] = '0' + (n % 10);
	while ((n /= 10) > 0)
		ptr->f_print[--i] = '0' + (n % 10);
	while (ptr->precision > 99 - i)
		ptr->f_print[--i] = '0';
	len += print(ptr, ptr->f_print + i, 0);
	return (len);
}

int		print_sign(t_data *ptr)
{
	int len;

	len = 0;
	write(1,&(ptr->sign),1);
	len = 1;
	ptr->min_width--;
	return (len);
}

int		print_d(t_data *ptr, long long nb)
{
	int		len;
	int		i;

	len = 0;
	i = 99;
	check_if_prec_set(ptr, (int)nb);
	if (!ptr->flag)
		ptr->f_print[--i] = '0' + (nb % 10);
	while ((nb /= 10) > 0)
		ptr->f_print[--i] = '0' + (nb % 10);
	while (ptr->precision > 99 - i)
		ptr->f_print[--i] = '0';
	if (ptr->zero && ptr->sign)
		len += print_sign(ptr);
	else if (ptr->sign)
		ptr->f_print[--i] = ptr->sign;
	len += print(ptr, ptr->f_print + i, 0);
	return (len);
}

int			print_o(t_data *ptr, unsigned long long n)
{
	int		len;
	int		i;

	i = 99;
	check_if_prec_set(ptr, (int)n);
	if (!ptr->flag)
		ptr->f_print[--i] = '0' + (n % 8);
	while ((n /= 8) > 0)
		ptr->f_print[--i] = '0' + (n % 8);
	if (ptr->hash && ptr->f_print[i] != '0')
		ptr->f_print[--i] = '0';
	if (ptr->prec_set)
		ptr->zero = 0;
	while (ptr->precision > 99 - i)
		ptr->f_print[--i] = '0';
	len = print(ptr, ptr->f_print + i, 0);
	return (len);
}


/*

int			print_x(t_data *ptr,unsigned long long n)
{
	int		len;
	int		i;

	i = 99;
	if (n != 0)
	{
		if ((n % 16) <= 9)
			ptr->f_print[--i] = '0' + (n % 16);
		else
			ptr->f_print[--i] = '0' + (n % 16) + 39;
	}
	while ((n /= 16) > 0)
	{
		if ((n % 16) <= 9)
			ptr->f_print[--i] = '0' + (n % 16);
		else
			ptr->f_print[--i] = '0' + (n % 16) + 39;
	}
	if (ptr->prec_set)
		ptr->zero = 0;
	while (ptr->precision > 99 - i)
		ptr->f_print[--i] = '0';
	if (ptr->zero && ((ptr->hash && i < 99 && ptr->f_print[98] != '0')
							  || ptr->type == 'p'))
		ptr->min_width -= 2;
	else if ((ptr->hash && i < 99 && ptr->f_print[98] != '0')
			 || ptr->type == 'p')
	{
		ptr->f_print[--i] = 'x';
		ptr->f_print[--i] = '0';
	}
	len = print(ptr, ptr->f_print + i, 0);
	return (len);
}

int			print_x_caps(t_data *ptr,unsigned long long n)
{
	int len;
	int i;

	i = 99;
	len = 0;
	if (n != 0)
	{
		if ((n % 16) <= 9)
			ptr->f_print[--i] = '0' + (n % 16);
		else
			ptr->f_print[--i] = '0' + (n % 16) + 7;
	}
	while ((n /= 16) > 0)
	{
		if ((n % 16) <= 9)
			ptr->f_print[--i] = '0' + (n % 16);
		else
			ptr->f_print[--i] = '0' + (n % 16) + 7;
	}
	if (ptr->prec_set)
		ptr->zero = 0;
	while (ptr->precision > 99 - i)
		ptr->f_print[--i] = '0';
	if (ptr->zero && ptr->hash && ptr->f_print[i] != '0')
	{
		len = 2;
		ft_putstr("0X");
		ptr->min_width -= 2;
	}
	else if (ptr->hash && ptr->f_print[i] != '0')
	{
		ptr->f_print[--i] = 'X';
		ptr->f_print[--i] = '0';
	}
	len += print(ptr, ptr->f_print + i, 0);
	return (len);
}

*/