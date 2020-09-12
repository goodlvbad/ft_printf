/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:19:45 by oearlene          #+#    #+#             */
/*   Updated: 2020/09/12 22:40:31 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parse_flags(t_data *ptr)
{
	while (ft_strchr("#0-+ ", *ptr->f_print))
	{
		if (*ptr->f_print == '#')
			ptr->flags->hash = 1;
		else if (*ptr->f_print == '0')
			ptr->flags->zero = 1;
		else if (*ptr->f_print == '-')
			ptr->flags->minus = 1;
		else if (*ptr->f_print == '+')
			ptr->flags->plus = 1;
		else if (*ptr->f_print == ' ')
			ptr->flags->space = 1;
		else if (*ptr->f_print == '\0')
			break ;
		else
			printf_error("Parse Flags fucked up.");
		ptr->f_print++;
	}
	if (!ptr->f_print)
		printf_error("Invalid format. (After Flags)");
	return (ptr->f_print);
}

static char	*parse_min_width(t_data *ptr)
{
	// add '*.'
	ptr->conv->min_width = ft_atoi(ptr->f_print);
	while (ft_isdigit(*ptr->f_print))
		ptr->f_print++;
	if (!ptr->f_print)
		printf_error("Invalid format. (After Min Width)");
	return (ptr->f_print);
}

static char	*parse_precision(t_data *ptr)
{
	if (*ptr->f_print != '.')
		return (ptr->f_print);
	ptr->f_print++;
	// add '.*'
	ptr->conv->precision = ft_atoi(ptr->f_print);
	ptr->conv->prec_set = 1;
	while (ft_isdigit(*ptr->f_print))
		ptr->f_print++;
	if (!ptr->f_print)
		printf_error("Invalid format. (After Precision)");
	return (ptr->f_print);
}

static char	*parse_length(t_data *ptr)
{
	if (!ft_strchr("hl", *ptr->f_print))
		return (ptr->f_print);
	if (ft_strncmp(ptr->f_print, "hh", 2) == 0)
	{
		ptr->length = HH;
		return (ptr->f_print + 2);
	}
	if (ft_strncmp(ptr->f_print, "ll", 2) == 0)
	{
		ptr->length = LL;
		return (ptr->f_print + 2);
	}
	else if (*ptr->f_print == 'h')
		ptr->length = H;
	else if (*ptr->f_print == 'l')
		ptr->length = L;
	return (ptr->f_print + 1);
}

char		*parse_conversion(t_data *ptr)
{
	ptr->f_print += ptr->i;
	ptr->f_print = parse_flags(ptr);
	if (ft_strchr(",;:_", *ptr->f_print))
	{
		ptr->conv->sep = *ptr->f_print;
		ptr->f_print++;
	}
	if (!ptr->f_print)
		printf_error("Invalid format. (After Separator)");
	ptr->f_print = parse_min_width(ptr);
	ptr->f_print = parse_precision(ptr);
	ptr->f_print = parse_length(ptr);
	if (!ptr->f_print)
		printf_error("Invalid format. (After Length)");
	ptr->conv->type = *ptr->f_print;
	return (ptr->f_print + 1);
}