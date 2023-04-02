/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:42:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 15:05:43 by anvannin         ###   ########.fr       */
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


	// printf("88: %03x \n", 1);
	// ft_printf("88: %03x \n", 1);

	// printf("98: %01x \n", -9);
	// ft_printf("98: %01x \n", -9);

	// printf("113: %015x \n", 9223372036854775807LL);
	// ft_printf("113: %015x \n", 9223372036854775807LL);

	// printf("114: %09x %010x %011x %012x %013x %014x %015x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// ft_printf("114: %09x %010x %011x %012x %013x %014x %015x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	// printf("117: %03X \n", 1);
	// ft_printf("117: %03X \n", 1);

	// printf("127: %01X \n", -9);
	// ft_printf("127: %01X \n", -9);

	// printf("142: %015X \n", 9223372036854775807LL);
	// ft_printf("142: %015X \n", 9223372036854775807LL);

	// printf("143: %09X %010X %011X %012X %013X %014X %015X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// ft_printf("143: %09X %010X %011X %012X %013X %014X %015X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	printf(" %.2x \n", -1);
	ft_printf(" %.2x \n", -1);

	return (0);
}
