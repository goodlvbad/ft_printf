/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:19:45 by oearlene          #+#    #+#             */
/*   Updated: 2020/09/12 17:56:59 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

static void		check_if_alias(t_conversion *conv)
{
	if (ft_strchr("DOU", conv->type))
	{
		conv->modif = L;
		conv->type = ft_tolower(conv->type);
	}
	else if (conv->type == 'i')
		conv->type = 'd';
	else if (conv->type == 'p')
	{
		conv->modif = L;
		conv->flags->pound = 1;
	}
}

static void		print_num_conv(t_conversion *conv, va_list ap)
{
	intmax_t	num;

	check_if_alias(conv);
	if (conv->type == 'd')
	{
		num = get_conv_signed(conv, ap);
		if (num < 0 && (num *= -1))
			conv->sign = '-';
		else if (conv->flags->plus)
			conv->sign = '+';
		else if (conv->flags->space)
			conv->sign = ' ';
	}
	else
		num = get_conv_unsigned(conv, ap);
	if (ft_strchr("du", conv->type))
		print_u(conv, (uintmax_t)num);
	else if (conv->type == 'o')
		print_o(conv, (uintmax_t)num);
	else if (ft_strchr("xp", conv->type))
		print_x(conv, (uintmax_t)num);
	else if (conv->type == 'X')
		print_x_caps(conv, (uintmax_t)num);
}

static void		print_str_conv(t_conversion *conv, va_list ap)
{
	if (ft_strchr("CS", conv->type))
	{
		conv->modif = L;
		conv->type = ft_tolower(conv->type);
	}
	if (conv->modif == L)
	{
		if (conv->type == 'c')
			print_wchar(conv, va_arg(ap, wint_t));
		else if (conv->type == 's')
			print_wstr(conv, va_arg(ap, wchar_t*));
		else
			print_char(conv, conv->type);
	}
	else
	{
		if (conv->type == 'c')
			print_char(conv, va_arg(ap, int));
		else if (conv->type == 's')
			print_str(conv, va_arg(ap, char*));
		else
			print_char(conv, conv->type);
	}
}

*/

static char	*parse_flags(t_data *ptr)
{
	while (ft_strchr("#0-+ ", *ptr->f_print))
	{
		if (*ptr->f_print == '#')
			ptr->flags->pound = 1;
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
	ptr->conv->precision = ft_atoi(ptr->f_print);
	ptr->conv->prec_set = 1;
	while (ft_isdigit(*ptr->f_print))
		ptr->f_print++;
	if (!ptr->f_print)
		printf_error("Invalid format. (After Precision)");
	return (ptr->f_print);
}

static char	*parse_modifier(t_data *ptr)
{
	if (!ft_strchr("hljz", *ptr->f_print))
		return (ptr->f_print);
	if (ft_strncmp(ptr->f_print, "hh", 2) == 0)
	{
		ptr->modif = HH;
		return (ptr->f_print + 2);
	}
	if (ft_strncmp(ptr->f_print, "ll", 2) == 0)
	{
		ptr->modif = LL;
		return (ptr->f_print + 2);
	}
	else if (*ptr->f_print == 'h')
		ptr->modif = H;
	else if (*ptr->f_print == 'l')
		ptr->modif = L;
	else if (*ptr->f_print == 'j')
		ptr->modif = J;
	else if (*ptr->f_print == 'z')
		ptr->modif = Z;
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
	ptr->f_print = parse_modifier(ptr);
	if (!ptr->f_print)
		printf_error("Invalid format. (After Modifier)");
	ptr->conv->type = ptr->f_print;
	return (ptr->f_print + 1);
}

/*
char	*print_type(t_data *ptr, va_list arg)
{

	if (ft_strchr("idDoOuUxXp", conv->type))
		print_num_conv(conv, arg);
	else
		print_str_conv(conv, arg);

	return (ptr);
}
*/




int		next_parser(t_data *ptr, va_list arg)
{
	ptr->i++;
	ptr->f_print = parse_conversion(ptr);

// need to be done





	return (ptr->len);
}

int		parser(t_data *ptr, va_list arg)
{
	while (ptr->f_copy[ptr->i] != '\0')
	{
		if (ptr->f_copy[ptr->i] == '%')
		{
			ptr->len += next_parser(ptr, arg);
		}
		else
		{
			write(1,ptr->f_copy[ptr->i],1);
			ptr->len++;
		}
		ptr->i++;
	}
	return (ptr->len);
}