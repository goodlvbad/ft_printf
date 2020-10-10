/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:00:19 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/10 18:00:03 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		main(void)
{
	int t;

	t = ft_printf("This is %0.10d number", -26);
	printf("\n%d\n", t);
	t = printf("This is %0.10d number", -26);
	printf("\n%d\n", t);
	return (0);
}