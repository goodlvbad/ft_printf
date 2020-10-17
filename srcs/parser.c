/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:19:45 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/17 15:29:52 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_flags(t_data *ptr)
{
	while (ft_strchr("#0-+ ", ptr->f_copy[ptr->i]))
	{
		if (ptr->f_copy[ptr->i] == '#')
			ptr->hash = 1;
		else if (ptr->f_copy[ptr->i] == '0')
			ptr->zero = 1;
		else if (ptr->f_copy[ptr->i] == '-')
			ptr->minus = 1;
		else if (ptr->f_copy[ptr->i] == '+')
			ptr->plus = 1;
		else if (ptr->f_copy[ptr->i] == ' ')
			ptr->space = 1;
		else if (ptr->f_copy[ptr->i] == '\0')
			break ;
		ptr->i++;
	}
}

void		parse_min_width(t_data *ptr, va_list arg)
{
	char	*str;

	if (ptr->f_copy[ptr->i] == '*')
	{
		ptr->min_width = va_arg(arg, int);
		ptr->i++;
		return ;
	}
	str = &(ptr->f_copy[ptr->i]);
	ptr->min_width = ft_atoi(str);
	while (ft_isdigit(ptr->f_copy[ptr->i]))
		ptr->i++;
}

void		parse_precision(t_data *ptr, va_list arg)
{
	char	*str;

	if (ptr->f_copy[ptr->i] != '.')
		return ;
	ptr->i++;
	ptr->prec_set = 1;
	if (ptr->f_copy[ptr->i] == '*')
	{
		ptr->precision = va_arg(arg, int);
		ptr->i++;
		return ;
	}
	str = &(ptr->f_copy[ptr->i]);
	ptr->precision = ft_atoi(str);
	if (ptr->precision < 0)
		ptr->prec_set = 0;
	while (ft_isdigit(ptr->f_copy[ptr->i]))
		ptr->i++;
}

void		parse_length(t_data *ptr)
{
	char	*str;

	if (!ft_strchr("hlL", ptr->f_copy[ptr->i]))
		return ;
	str = &(ptr->f_copy[ptr->i]);
	if (ft_strncmp(str, "hh", 2) == 0)
	{
		ptr->length = HH;
		ptr->i += 2;
		return ;
	}
	if (ft_strncmp(str, "ll", 2) == 0)
	{
		ptr->length = LL;
		ptr->i += 2;
		return ;
	}
	else if (ptr->f_copy[ptr->i] == 'h')
		ptr->length = H;
	else if (ptr->f_copy[ptr->i] == 'l')
		ptr->length = L;
	else if (ptr->f_copy[ptr->i] == 'L')
		ptr->length = LF;
	ptr->i++;
}

void		parse_conversion(t_data *ptr, va_list arg)
{
	parse_flags(ptr);
	parse_min_width(ptr, arg);
	parse_precision(ptr, arg);
	parse_length(ptr);
	ptr->type = ptr->f_copy[ptr->i];
}
