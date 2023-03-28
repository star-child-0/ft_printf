/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:42:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/28 19:48:19 by anvannin         ###   ########.fr       */
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
	// printf("%-2c\n", 'a');
	// printf("%-2c\n", '0');
	// printf("%-3c\n", '0');
	// printf("%-4c\n", '0');
//			 2 4
	ft_printf("%-5c\n", 'a');
	// ft_printf("%-2c\n", '0');
	// ft_printf("%-3c\n", '0');
	// ft_printf("%-4c\n", '0');

	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%-di ft_printf:\t\t %-d\n\n", 42) - 3, printf("%%-di printf:\t\t %-d\n", 42));
	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%-di ft_printf:\t\t %-d\n\n", -42) - 3,printf("%%-di printf:\t\t %-d\n", -42));

	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%.di ft_printf:\t\t %.d\n", 42) - 3, printf("%%.di printf:\t\t %.d\n", 42));
	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%.di ft_printf:\t\t %.d\n", -42) - 3,printf("%%.di printf:\t\t %.d\n", -42));
	return (0);
}
