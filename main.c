/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:00:19 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/17 18:18:48 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		main(void)
{
	int t;

	t = ft_printf("%%\t4\t\t%0.2u , \t%s ,\t%f", 24567, "hello", 12.065);
	printf("\n%d\n", t);
	t = printf("%%\t5\t\t%0.2u , \t%s ,\t%f", 24567, "hello", 12.065);
	printf("\n%d\n", t);

/*
	t = ft_printf("%%-*.3s LYDI = |%-*.3s|", 5, "LYDI");
	printf("\n%d\n", t);
	t = printf("%%-*.3s LYDI = |%-*.3s|", 5, "LYDI");
	printf("\n%d\n", t);
	t = ft_printf("%012d", 2345);
	printf("\n%d\n", t);
	t = printf("%012d", 2345);
	printf("\n%d\n", t);
 */
	return (0);
}