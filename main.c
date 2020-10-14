/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:00:19 by oearlene          #+#    #+#             */
/*   Updated: 2020/10/14 16:54:25 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		main(void)
{
	int t;

	t = ft_printf("This is the f %Lf number", 3.4);
	printf("\n%d\n", t);
	t = printf("This is the f %Lf number", 3.4);
	printf("\n%d\n", t);
	return (0);
}