/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 22:21:25 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/08 20:53:07 by oearlene         ###   ########.fr       */
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

void 	ft_putstr_sized(char *str, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		print(t_data *ptr, char *str, int size)
{
	int len;

	len = ft_strlen(str);
	if (size > 0)
		len = size;
	if (ptr->minus)
	{
		ft_putstr_sized(str, len);
		len += print_spacing(len, ptr->min_width, ' ');
		return (len);
	}
	if (ptr->zero)
		len += print_spacing(len, ptr->min_width, '0');
	len += print_spacing(len, ptr->min_width, ' ');
	ft_putstr_sized(str, len);
	return (len);
}
