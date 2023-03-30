/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:42:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/30 21:09:19 by anvannin         ###   ########.fr       */
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
	// printf("pf %03x \n", 1);
	// ft_printf("ft %03x \n", 1);

	// printf("ret pf: %d\n", printf("pf %03x \n", 1));
	// printf("ret fd: %d\n", ft_printf("ft %03x \n", 1));

	// printf("ret pf: %d", printf("pf %01x \n", -9));
	// printf("ret ft: %d", ft_printf("ft %01x \n", -9));

	// printf("ret pf: %d", printf("pf %02x \n", -10));
	// printf("ret ft: %d", ft_printf("ft %02x \n", -10));

	printf("ret pf: %d\n", printf("pf %03x \n", 1));
	printf("ret ft: %d\n", ft_printf("ft %03x \n", 1));

	return (0);
}
