/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:00:19 by oearlene          #+#    #+#             */
/*   Updated: 2020/09/18 19:45:12 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		main(void)
{
/*
	int *res;
	int re[2];
	char *kek;
 */

	int r;

	/*
	char	*s1 = "loljvdsnlkjvns dnvlsk jfwk;qdwdkf";
	wchar_t	*s2 = L"keklkvml;ds kmlv fvn;skf nkjd \300nw";

	printf("std s: %s\n", s1);
	printf("std ls: %ls\n", s2);
	ft_printf("my s: %s\n", s1);
	ft_printf("my ls: %ls\n", s2);
	printf("\n");
	printf("std s: %.3s\n", NULL);
	printf("std ls: %.3ls\n", (wchar_t *)NULL);
	ft_printf("my s: %.3s\n", NULL);
	ft_printf("my ls: %.3ls\n", (wchar_t *)NULL);

	r = ft_printf("%+.0i", 0);
	printf("\n%d\n", r);
	r = printf("%+.0i", 0);
	printf("\n%d\n", r);
	r = ft_printf("%+.d", 0);
	printf("\n%d\n", r);
	r = printf("%+.d", 0);
	printf("\n%d\n", r);

	ft_printf("%0*.*x\n", 6, -1, 37);
	printf("%0*.*x\n", 6, -1, 37);
	ft_printf("%0*.*x\n", 6, 0, 38);
	printf("%0*.*x\n", 6, 0, 38);
	ft_printf("%0*.*x\n", 6, 1, 39);
	printf("%0*.*x\n", 6, 1, 39);
	ft_printf("%0*.*d\n", 4, 1, -13);
	printf("%0*.*d\n", 4, 1, -13);

	r = ft_printf("%08.4u\t%hd\t%d\t%ld\t%ld\n", (unsigned char)258, (short)32765, 52342, 9223372036854775800, 922337203685477580);
	printf("%d\n", r);
	r = printf("%08.4u\t%hd\t%d\t%ld\t%ld\n", (unsigned char)258, (short)32765, 52342, 9223372036854775800, 922337203685477580);
	printf("%d\n", r);

	ft_printf("%hhu\t%hd\t%d\t%ld\t%lld\n", (unsigned char)129, (short)32768, 52342, 9223372036854775800, 9223372036854775809);
	printf("%hhu\t%hd\t%d\t%ld\t%lld\n", (unsigned char)129, (short)32768, 52342, 9223372036854775800, 9223372036854775809);


	r = ft_printf("%#x", 28);
	printf("\n%d\n", r);
	r = printf("%#x", 28);
	printf("\n%d\n", r);
	r = ft_printf("%0#7x", 26);
	printf("\n%d\n", r);
	r = printf("%0#7x", 26);
	printf("\n%d\n", r);
	r = ft_printf("%#-7x", 29);
	printf("\n%d\n", r);
	r = printf("%#-7x", 29);
	printf("\n%d\n", r);
	r = ft_printf("%#7.4x", 27);
	printf("\n%d\n", r);
	r = printf("%#7.4x", 27);
	printf("\n%d\n", r);
	r = ft_printf("%#7.10x", 27);
	printf("\n%d\n", r);
	r = printf("%#7.10x", 27);
	printf("\n%d\n\n", r);

	r = ft_printf("%+5.3d", 12);
	printf("\n%d\n", r);
	r = printf("%+5.3d", 12);
	printf("\n%d\n", r);
	r = ft_printf("%+05d", 14);
	printf("\n%d\n", r);
	r = printf("%+05d", 14);
	printf("\n%d\n", r);
	r = ft_printf("%+-10.4d", 13);
	printf("\n%d\n", r);
	r = printf("%+-10.4d", 13);
	printf("\n%d\n", r);
	r = ft_printf("%+3.d", 0);
	printf("\n%d\n", r);
	r = printf("%+3.d", 0);
	printf("\n%d\n", r);
	r = ft_printf("%+-3.d", 0);
	printf("\n%d\n", r);
	r = printf("%+-3.d", 0);
	printf("\n%d\n\n", r);
	*/
/*
	res = malloc(8);
 */
/*
	printf("\t//	COMBINED\n");
	r = ft_printf("start %% a: '%--4.c', b: '%-*c', c: '%-.c', str: '%*.*s', u: %-7.5u, di: %-.4d, hex: %-8.*X point: %p point2: %.p point3: %-20p", 'a', 4, 'b', 'c', 8, 4, "keklol", 1234, 52, 6, 5620, &res, &res, &res);
	ft_printf("\n%d\n", r);
	// printf("%d\n", *res);
	r = printf("start %% a: '%--4.c', b: '%-*c', c: '%-.c', str: '%*.*s', u: %-7.5u, di: %-.4d, hex: %-8.*X point: %p point2: %.p point3: %-20p", 'a', 4, 'b', 'c', 8, 4, "keklol", 1234, 52, 6, 5620, &res, &res, &res);
	printf("\n%d\n", r);
	// printf("%d\n", *res);
	r = ft_printf("start %% a: '%--4.c', b: '%-*c', c: '%-.c', str: '%*.*s', u: %-7.5u, di: %-.4d, hex: %-8.*X point: %p point2: %.p point3: %-20p kek", 'a', 4, 'b', 'c', 8, 4, "keklol", 1234, 52, 6, 5620, &res, &res, res);
	ft_printf("\n%d\n", r);
	// printf("%d\n", *res);
	r = printf("start %% a: '%--4.c', b: '%-*c', c: '%-.c', str: '%*.*s', u: %-7.5u, di: %-.4d, hex: %-8.*X point: %p point2: %.p point3: %-20p kek", 'a', 4, 'b', 'c', 8, 4, "keklol", 1234, 52, 6, 5620, &res, &res, res);
	printf("\n%d\n", r);
	// printf("%d\n\n", *res);
*/
/*
	printf("%-00000-----*i\n", 5, 5);
	ft_printf("%-00000-----*i\n", 5, 5);

	printf("\t//	FOR_C\n");
	r = ft_printf("%c%c%c%c%c%c\n", (char)1, (char)2, (char)3, (char)4, (char)5, (char)6);
	printf("%d\n", r);
	r = printf("%c%c%c%c%c%c\n", (char)1, (char)2, (char)3, (char)4, (char)5, (char)6);
	printf("%d\n", r);
	r = ft_printf("%*c\n", 3, 'e');
	printf("%d\n", r);
	r = printf("%*c\n", 3, 'e');
	printf("%d\n", r);
	r = ft_printf("%-4.c\n", 'e');
	printf("%d\n", r);
	r = printf("%-4.c\n", 'e');
	printf("%d\n\n", r);

	printf("\t//	FOR_%%\n");
	r = ft_printf("%5%\n");
	printf("%d\n", r);
	r = printf("%5%\n");
	printf("%d\n", r);
	r = ft_printf("%-5%\n");
	printf("%d\n", r);
	r = printf("%-5%\n");
	printf("%d\n", r);
	r = ft_printf("%05%\n");
	printf("%d\n", r);
	r = printf("%05%\n");
	printf("%d\n", r);
	r = ft_printf("%-05%\n");
	printf("%d\n", r);
	r = printf("%-05%\n");
	printf("%d\n", r);
	r = ft_printf("%5.4%\n");
	printf("%d\n", r);
	r = printf("%5.4%\n");
	printf("%d\n\n", r);

	printf("\t//	FOR_S\n");
	r = ft_printf("%s\n", "1234");
	printf("%d\n", r);
	r = printf("%s\n", "1234");
	printf("%d\n", r);
	r = ft_printf("%s\n", NULL);
	printf("%d\n", r);
	r = printf("%s\n", NULL);
	printf("%d\n", r);
	r = ft_printf("%7s\n", NULL);
	printf("%d\n", r);
	r = printf("%7s\n", NULL);
	printf("%d\n", r);
	r = ft_printf("%.3s\n", NULL);
	printf("%d\n", r);
	r = printf("%.3s\n", NULL);
	printf("%d\n", r);
	r = ft_printf("%7.*s\n", 5, "1234");
	printf("%d\n", r);
	r = printf("%7.*s\n", 5, "1234");
	printf("%d\n", r);
	r = ft_printf("%-7.3s\n", "1234");
	printf("%d\n", r);
	r = printf("%-7.3s\n", "1234");
	printf("%d\n", r);
	r = ft_printf("%-7.*s\n", -2, "456");
	printf("%d\n", r);
	r = printf("%-7.*s\n", -2, "456");
	printf("%d\n", r);
	r = ft_printf("%-7.0s\n", "46");
	printf("%d\n", r);
	r = printf("%-7.0s\n", "46");
	printf("%d\n\n", r);

	printf("\t//	FOR_U\n");
	r = ft_printf("%.0u\n", 0);
	printf("%u\n", r);
	r = printf("%.0u\n", 0);
	printf("%u\n", r);
	r = ft_printf("%05.*u", -1, 40);
	printf("\n%u\n", r);
	r = printf("%05.*u", -1, 40);
	printf("\n%u\n", r);
	r = ft_printf("%05.*u", 1, 41);
	printf("\n%u\n", r);
	r = printf("%05.*u", 1, 41);
	printf("\n%u\n", r);
	r = ft_printf("%05.u", 42);
	printf("\n%u\n", r);
	r = printf("%05.u", 42);
	printf("\n%u\n", r);
	r = ft_printf("%05u", 43);
	printf("\n%u\n", r);
	r = printf("%05u", 43);
	printf("\n%u\n", r);
	r = ft_printf("%8.*u", 6, 1234);
	printf("\n%u\n", r);
	r = printf("%8.*u", 6, 1234);
	printf("\n%u\n", r);
	r = ft_printf("%8.*u", -6, 1234);
	printf("\n%u\n", r);
	r = printf("%8.*u", -6, 1234);
	printf("\n%u\n", r);
	r = ft_printf("%7u", 1234);
	printf("\n%u\n", r);
	r = printf("%7u", 1234);
	printf("\n%u\n", r);
	r = ft_printf("%-7u", 1234);
	printf("\n%u\n", r);
	r = printf("%-7u", 1234);
	printf("\n%u\n", r);
	r = ft_printf("%7u", -1234);
	printf("\n%u\n", r);
	r = printf("%7u", -1234);
	printf("\n%u\n\n", r);
 */

	//printf("\t//	FOR_DI\n");
/*
	r = ft_printf("%05.*d", -1, 40);
	printf("\n%d\n", r);
	r = printf("%05.*d", -1, 40);
	printf("\n%d\n", r);
	r = ft_printf("%.*d", 1, 41);
	printf("\n%d\n", r);
	r = printf("%.*d", 1, 41);
	printf("\n%d\n", r);
	r = ft_printf("%05.d", 42);
	printf("\n%d\n", r);
	r = printf("%05.d", 42);
	printf("\n%d\n", r);
	r = ft_printf("%05d", 43);
	printf("\n%d\n", r);
	r = printf("%05d", 43);
	printf("\n%d\n", r);
	r = ft_printf("%-5.2d", -3);
	printf("\n%d\n", r);
	r = printf("%-5.2d", -3);
	printf("\n%d\n", r);
	r = ft_printf("%-5.7d", -3);
	printf("\n%d\n", r);
	r = printf("%-5.7d", -3);
	printf("\n%d\n", r);
 	r = ft_printf("%-5d", -3);
	printf("\n%d\n", r);
	r = printf("%-5d", -3);
	printf("\n%d\n", r);


	r = ft_printf("%-5.3d", -345);
	printf("\n%d\n", r);
	r = printf("%-5.3d", -345);
	printf("\n%d\n", r);


	r = ft_printf("%5.2d", -3);
	printf("\n%d\n", r);
	r = printf("%5.2d", -3);
	printf("\n%d\n", r);

	r = ft_printf("%5.7d", -3);
	printf("\n%d\n", r);
	r = printf("%5.7d", -3);
	printf("\n%d\n", r);


	r = ft_printf("%5d", -3);
	printf("\n%d\n", r);
	r = printf("%5d", -3);
	printf("\n%d\n", r);

	r = ft_printf("%5.3i", -345);
	printf("\n%d\n", r);
	r = printf("%5.3i", -345);
	printf("\n%d\n", r);


	r = ft_printf("%7d", -1234);
	printf("\n%d\n", r);
	r = printf("%7d", -1234);
	printf("\n%d\n", r);


	r = ft_printf("%-.4d", -1234);
	printf("\n%d\n", r);
	r = printf("%-.4d", -1234);
	printf("\n%d\n", r);

	r = ft_printf("%07d", 1234);
	printf("\n%d\n", r);
	r = printf("%07d", 1234);
	printf("\n%d\n", r);

	r = ft_printf("%-7d", 1234);
	printf("\n%d\n", r);
	r = printf("%-7d", 1234);
	printf("\n%d\n", r);

	r = ft_printf("%7.d", 1234);
	printf("\n%d\n", r);
	r = printf("%7.d", 1234);
	printf("\n%d\n", r);


	r = ft_printf("%-7.d", 1234);
	printf("\n%d\n", r);
	r = printf("%-7.d", 1234);
	printf("\n%d\n", r);

	r = ft_printf("%.3d", 1234);
	printf("\n%d\n", r);
	r = printf("%.3d", 1234);
	printf("\n%d\n", r);

	r = ft_printf("%-.3d", 1234);
	printf("\n%d\n", r);
	r = printf("%-.3d", 1234);
	printf("\n%d\n", r);

	r = ft_printf("%0.3d", 1234);
	printf("\n%d\n", r);
	r = printf("%0.3d", 1234);
	printf("\n%d\n", r);
	*/

	//ft_printf("%.d", 1234);
	//ft_putchar('\n');
	//ft_printf("%-.d",1234);
	/*
	r = ft_printf("%.d", 1234);
	printf("\n%d\n", r);
	r = printf("%.d", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%-.d",1234);
	printf("\n%d\n", r);
	r = printf("%-.d",1234);
	printf("\n%d\n", r);
	r = ft_printf("%d", 1234);
	printf("\n%d\n", r);
	r = printf("%d", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%06.0d", 1234);
	printf("\n%d\n", r);
	r = printf("%06.0d", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%7.2d", 1234);
	printf("\n%d\n", r);
	r = printf("%7.2d", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%05.*d", -1, -40);
	printf("\n%d\n", r);
	r = printf("%05.*d", -1, -40);
	printf("\n%d\n", r);
	r = ft_printf("%05.*d", 1, -41);
	printf("\n%d\n", r);
	r = printf("%05.*d", 1, -41);
	printf("\n%d\n", r);
	r = ft_printf("%05d", -43);
	printf("\n%d\n", r);
	r = printf("%05d", -43);
	printf("\n%d\n", r);
	r = ft_printf("%07.4d", -48);
	printf("\n%d\n", r);
	r = printf("%07.4d", -48);
	printf("\n%d\n\n", r);
*/


	//printf("\t//	FOR_Xx\n");
/*
	r = ft_printf("%X", 12);
	printf("\n%d\n", r);
	r = printf("%X", 12);
	printf("\n%d\n", r);
	*/
	r = ft_printf("%-8.*X", 3, 12);
	printf("\n%d\n", r);
	r = printf("%-8.*X", 3, 12);
	printf("\n%d\n", r);
	/*
	r = ft_printf("%-8.*X", -3, 12);
	printf("\n%d\n", r);
	r = printf("%-8.*X", -3, 12);
	printf("\n%d\n", r);
	r = ft_printf("%8.*X", -3, 12);
	printf("\n%d\n", r);
	r = printf("%8.*X", -3, 12);
	printf("\n%d\n", r);
	r = ft_printf("%X", -1);
	printf("\n%d\n", r);
	r = printf("%X", -1);
	printf("\n%d\n", r);
	r = ft_printf("%-8.*X", 0, 13);
	printf("\n%d\n", r);
	r = printf("%-8.*X", 0, 13);
	printf("\n%d\n", r);
	r = ft_printf("%10X", 12);
	printf("\n%d\n", r);
	r = printf("%10X", 12);
	printf("\n%d\n", r);
	r = ft_printf("%10X", -12);
	printf("\n%d\n", r);
	r = printf("%10X", -12);
	printf("\n%d\n", r);
	r = ft_printf("%07X", 1234);
	printf("\n%d\n", r);
	r = printf("%07X", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%-7X", 1234);
	printf("\n%d\n", r);
	r = printf("%-7X", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%7.X", 1234);
	printf("\n%d\n", r);
	r = printf("%7.X", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%-7.X", 1234);
	printf("\n%d\n", r);
	r = printf("%-7.X", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%.3x", 1234);
	printf("\n%d\n", r);
	r = printf("%.3x", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%-.3x", 1234);
	printf("\n%d\n", r);
	r = printf("%-.3x", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%0.3x", 1234);
	printf("\n%d\n", r);
	r = printf("%0.3x", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%.x", 1234);
	printf("\n%d\n", r);
	r = printf("%.x", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%-.x", 1234);
	printf("\n%d\n", r);
	r = printf("%-.x", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%x", 1234);
	printf("\n%d\n", r);
	r = printf("%x", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%0x", 1234);
	printf("\n%d\n", r);
	r = printf("%0x", 1234);
	printf("\n%d\n", r);
	r = ft_printf("%7.2x", 1234);
	printf("\n%d\n", r);
	r = printf("%7.2x", 1234);
	printf("\n%d\n\n", r);

	printf("\t//	FOR_P\n");
	r = ft_printf("%16p", res);
	printf("\n%d\n", r);
	r = printf("%16p", res);
	printf("\n%d\n", r);
	r = ft_printf("%-16p", res);
	printf("\n%d\n", r);
	r = printf("%-16p", res);
	printf("\n%d\n", r);
	r = ft_printf("%16p", re);
	printf("\n%d\n", r);
	r = printf("%16p", re);
	printf("\n%d\n", r);
	r = ft_printf("%.p", &kek);
	printf("\n%d\n", r);
	r = printf("%.p", &kek);
	printf("\n%d\n", r);
	r = ft_printf("%-5.p", NULL);
	printf("\n%d\n", r);
	r = printf("%-5.p", NULL);
	printf("\n%d\n", r);
	// r = ft_printf("%-5.*p", -1, NULL);
	// printf("\n%d\n", r);
	// r = printf("%-5.*p", -1, NULL);
	// printf("\n%d\n", r);
	r = ft_printf("%-5p", NULL);
	printf("\n%d\n", r);
	r = printf("%-5p", NULL);
	printf("\n%d\n", r);

	free(res);

	*/

	return (0);
}