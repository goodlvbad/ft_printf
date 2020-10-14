/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:13:04 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/10 20:59:05 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_p(t_data *ptr, int i)
{
	if (ptr->zero && ((ptr->hash && i < N - 1 && ptr->f_print[N - 2] != '0')
			|| ptr->type == 'p'))
		ptr->min_width -= 2;
	else if ((ptr->hash && i < N - 1 && ptr->f_print[N - 2] != '0')
			|| ptr->type == 'p')
	{
		ptr->f_print[--i] = 'x';
		ptr->f_print[--i] = '0';
	}
	return (i);
}

/*
**	int 	print_p_caps(t_data *ptr, int i)
**	{
**		if (ptr->zero && ptr->hash && ptr->f_print[i] != '0')
**		{
**			ptr->len += 2;
**			ft_putstr("0X");
**			ptr->min_width -= 2;
**		}
**		else if (ptr->hash && ptr->f_print[i] != '0')
**		{
**			ptr->f_print[--i] = 'X';
**			ptr->f_print[--i] = '0';
**		}
**		return (i);
**	}
*/

int		print_x(t_data *ptr, unsigned long long n)
{
	int	len;
	int	i;

	i = N - 1;
	check_if_prec_set(ptr, (int)n);
	if (!ptr->flag)
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
	while (ptr->precision > (N - 1) - i)
		ptr->f_print[--i] = '0';
	i = print_p(ptr, i);
	len = print(ptr, ptr->f_print + i, 0);
	return (len);
}

int		print_x_caps(t_data *ptr, unsigned long long n)
{
	int	len;
	int	i;

	i = N - 1;
	len = 0;
	check_if_prec_set(ptr, (int)n);
	if (!ptr->flag)
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
	while (ptr->precision > (N - 1) - i)
		ptr->f_print[--i] = '0';
	len += print(ptr, ptr->f_print + i, 0);
	return (len);
}
