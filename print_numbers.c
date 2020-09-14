/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:06:12 by oearlene          #+#    #+#             */
/*   Updated: 2020/09/14 15:18:40 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_spacing(int len, int min, char c)
{
	int i;

	i = 0;
	while (min > len)
	{
		ft_putchar(c);
		min--;
		i++;
	}
	return (i);
}

int		print_num_spaced(t_data *ptr, char *str)
{
	int len;

	len = ft_strlen(str);
	if (ptr->flags->minus)
		ft_putstr(str);
	if (ptr->flags->zero)
		len += print_spacing(len, (int)ptr->conv->min_width, '0');
	len += print_spacing(len, (int)ptr->conv->min_width, ' ');
	ft_putstr(str);
	return (len);
}

int		print_u(t_data *ptr, unsigned long long n)
{
	int		len;
	int		i;

	len = 0;
	i = 99;
	if (!ptr->conv->prec_set)
		ptr->f_print[--i] = '0' + (n % 10);
	while ((n /= 10) > 0)
		ptr->f_print[--i] = '0' + (n % 10);
	if (ptr->conv->precision > 99 - i)
		ptr->flags->zero = 0;
	while (ptr->conv->precision > 99 - i)
		ptr->f_print[--i] = '0';
	len += print_num_spaced(ptr, ptr->f_print + i);
	return (len);
}

int		print_d(t_data *ptr, long long nb)
{
	int		len;
	int		i;

	len = 0;
	i = 99;
	if (nb > 0 || !ptr->conv->prec_set)
		ptr->f_print[--i] = '0' + (nb % 10);
	while ((nb /= 10) > 0)
		ptr->f_print[--i] = '0' + (nb % 10);
	if (ptr->conv->precision > 99 - i)
		ptr->flags->zero = 0;
	while (ptr->conv->precision > 99 - i)
		ptr->f_print[--i] = '0';
	if (ptr->flags->zero && ptr->conv->sign)
	{
		write(1,&(ptr->conv->sign),1);
		len = 1;
		ptr->conv->min_width--;
	}
	else if (ptr->conv->sign)
		ptr->f_print[--i] = ptr->conv->sign;
	len += print_num_spaced(ptr, ptr->f_print + i);
	return (len);
}


int			print_o(t_data *ptr, unsigned long long n)
{
	int		len;
	int		i;

	i = 99;
	if (!ptr->conv->prec_set)
		ptr->f_print[--i] = '0' + (n % 8);
	while ((n /= 8) > 0)
		ptr->f_print[--i] = '0' + (n % 8);
	if (ptr->flags->hash && ptr->f_print[i] != '0')
		ptr->f_print[--i] = '0';
	while (ptr->conv->precision > 99 - i)
		ptr->f_print[--i] = '0';
	len = print_num_spaced(ptr, ptr->f_print + i);
	return (len);
}

int			print_x(t_data *ptr,unsigned long long n)
{
	int		len;
	int		i;

	i = 99;
	if (!ptr->conv->prec_set)
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
	while (ptr->conv->precision > 99 - i)
		ptr->f_print[--i] = '0';
	if (ptr->flags->zero && ((ptr->flags->hash && i < 99 && ptr->f_print[98] != '0')
							  || ptr->conv->type == 'p'))
		ptr->conv->min_width -= 2;
	else if ((ptr->flags->hash && i < 99 && ptr->f_print[98] != '0')
			 || ptr->conv->type == 'p')
	{
		ptr->f_print[--i] = 'x';
		ptr->f_print[--i] = '0';
	}
	len = print_num_spaced(ptr, ptr->f_print + i);
	return (len);
}

int			print_x_caps(t_data *ptr,unsigned long long n)
{
	int		len;
	char	str[100];
	int		i;

	i = 99;
	str[i] = '\0';
	if (!ptr->conv->prec_set)
	{
		if ((n % 16) <= 9)
			str[--i] = '0' + (n % 16);
		else
			str[--i] = '0' + (n % 16) + 7;
	}
	while ((n /= 16) > 0)
	{
		if ((n % 16) <= 9)
			str[--i] = '0' + (n % 16);
		else
			str[--i] = '0' + (n % 16) + 7;
	}
	while (ptr->conv->precision > 99 - i)
		str[--i] = '0';
	if (ptr->flags->zero && ptr->flags->hash && str[i] != '0')
	{
		len = 2;
		ft_putstr("0X");
		ptr->conv->min_width -= 2;
	}
	else if (ptr->flags->hash && str[i] != '0')
	{
		str[--i] = 'X';
		str[--i] = '0';
	}
	len = print_num_spaced(ptr, str + i);
	return (len);
}