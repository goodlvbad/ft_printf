/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:00:19 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/11 00:27:47 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		main(void)
{
	int t;

	t = ft_printf("This is the f %f number", 517.256);
	printf("\n%d\n", t);
	t = printf("This is the f %f number", 517.256);
	printf("\n%d\n", t);
	return (0);
}