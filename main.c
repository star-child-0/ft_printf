/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:42:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/31 12:38:04 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
clear && gcc *.c && ./a.out
clear && gcc *.c && valgrind ./a.out
clear && gcc *.c && valgrind --leak-check=full ./a.out
*/
#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	// printf("pf88 %.3x \n", 1);
	// printf("pf98 %.1x \n", -9);
	// printf("pf99 %.2x \n", -10);
	// printf("pf100 %.3x \n", -11);
	// printf("pf101 %.4x \n", -14);
	// printf("pf102 %.5x \n", -15);
	// printf("pf103 %.6x \n", -16);
	// printf("pf104 %.1x \n", -99);
	// printf("pf105 %.2x \n", -100);
	// printf("pf106 %.3x \n", -101);
	// printf("pf107 %.9x \n", INT_MAX);
	// printf("pf108 %.10x \n", INT_MIN);
	// printf("pf109 %.11x \n", LONG_MAX);
	// printf("pf110 %.12x \n", LONG_MIN);
	// printf("pf112 %.14x \n", ULONG_MAX);
	// printf("pf113 %.15x \n", 9223372036854775807LL);
	// printf("pf114 %.9x %.10x %.11x %.12x %.13x %.14x %.15x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	// ft_printf("ft88 %.3x \n", 1);
	// ft_printf("ft98 %.1x \n", -9);
	// ft_printf("ft99 %.2x \n", -10);
	// ft_printf("ft100 %.3x \n", -11);
	// ft_printf("ft101 %.4x \n", -14);
	// ft_printf("ft102 %.5x \n", -15);
	// ft_printf("ft103 %.6x \n", -16);
	// ft_printf("ft104 %.1x \n", -99);
	// ft_printf("ft105 %.2x \n", -100);
	// ft_printf("ft106 %.3x \n", -101);
	// ft_printf("ft107 %.9x \n", INT_MAX);
	// ft_printf("ft108 %.10x \n", INT_MIN);
	// ft_printf("ft109 %.11x \n", LONG_MAX);
	// ft_printf("ft110 %.12x \n", LONG_MIN);
	// ft_printf("ft112 %.14x \n", ULONG_MAX);
	// ft_printf("ft113 %.15x \n", 9223372036854775807LL);
	// ft_printf("ft114 %.9x %.10x %.11x %.12x %.13x %.14x %.15x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	printf("pf %.3x \n", 101);
	ft_printf("ft %.3x \n", 101);

	return (0);
}
