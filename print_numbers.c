/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:06:12 by oearlene          #+#    #+#             */
/*   Updated: 2020/09/12 22:57:55 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_spacing(int len, int min, char c)
{
	int i;

	i = 0;
	while (min > len)
	{
		putchar(c);
		min--;
		i++;
	}
	return (i);
}

int		print_left(t_data *ptr, char *str)
{
	int len;

	len = ft_strlen(str);
	ft_putstr(str);
	len += print_spacing(len, (int)ptr->conv->min_width, ' ');
	return (len);
}


int		print_num_spaced(t_data *ptr, char *str)
{
	int len;

	len = 0;
	if (ptr->flags->minus)
		return (len += print_left(ptr, str));
	if (ptr->flags->zero)
		len += print_spacing(ft_strlen(str), (int)ptr->conv->min_width, '0');
	else
		len += print_spacing(ft_strlen(str), (int)ptr->conv->min_width, ' ');
	len += ft_strlen(str);
	ft_putstr(str);
	return (len);
}

int		print_u(t_data *ptr, unsigned long long n)
{
	int		len;
	char	*str;
	int		i;

	len = 0;
	i = 99;
	str[i] = '\0';
	if (!ptr->conv->prec_set)
		str[--i] = '0' + (n % 10);
	while ((n /= 10) > 0)
		str[--i] = '0' + (n % 10);
	if (ptr->conv->precision > 99 - i)
		ptr->flags->zero = 0;
	while (ptr->conv->precision > 99 - i)
		str[--i] = '0';
	len += print_num_spaced(ptr, str + i);
	return (len);
}

int		print_d(t_data *ptr, long long nb)
{
	int		len;
	char	*str;
	int		i;

	len = 0;
	i = 99;
	str[i] = '\0';
	if (nb > 0 || !ptr->conv->prec_set)
		str[--i] = '0' + (nb % 10);
	while ((nb /= 10) > 0)
		str[--i] = '0' + (nb % 10);
	if (ptr->conv->precision > 99 - i)
		ptr->flags->zero = 0;
	while (ptr->conv->precision > 99 - i)
		str[--i] = '0';
	if (ptr->flags->zero && ptr->conv->sign)
	{
		write(1,&(ptr->conv->sign),1);
		len = 1;
		ptr->conv->min_width--;
	}
	else if (ptr->conv->sign)
		str[--i] = ptr->conv->sign;
	len += print_num_spaced(ptr, str + i);
	return (len);
}


int			print_o(t_data *ptr, unsigned long long n)
{
	int		len;
	char	*str;
	int		i;

	i = 99;
	str[i] = '\0';
	if (!ptr->conv->prec_set)
		str[--i] = '0' + (n % 8);
	while ((n /= 8) > 0)
		str[--i] = '0' + (n % 8);
	if (ptr->flags->hash && str[i] != '0')
		str[--i] = '0';
	while (ptr->conv->precision > 99 - i)
		str[--i] = '0';
	len = print_num_spaced(ptr, str + i);
	return (len);
}

int			print_x(t_data *ptr,unsigned long long n)
{
	int		len;
	char	*str;
	int		i;

	i = 99;
	str[i] = '\0';
	if (!ptr->conv->prec_set)
	{
		if ((n % 16) <= 9)
			str[--i] = '0' + (n % 16);
		else
			str[--i] = '0' + (n % 16) + 39;
	}
	while ((n /= 16) > 0)
	{
		if ((n % 16) <= 9)
			str[--i] = '0' + (n % 16);
		else
			str[--i] = '0' + (n % 16) + 39;
	}
	while (ptr->conv->precision > 99 - i)
		str[--i] = '0';
	if (ptr->flags->zero && ((ptr->flags->hash && i < 99 && str[98] != '0')
							  || ptr->conv->type == 'p'))
		ptr->conv->min_width -= 2;
	else if ((ptr->flags->hash && i < 99 && str[98] != '0')
			 || ptr->conv->type == 'p')
	{
		str[--i] = 'x';
		str[--i] = '0';
	}
	len = print_num_spaced(ptr, str + i);
	return (len);
}

int			print_x_caps(t_data *ptr,unsigned long long n)
{
	int		len;
	char	*str;
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