/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:42:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/31 19:35:55 by anvannin         ###   ########.fr       */
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
	printf("ret pf %d \n", printf("pf 0 98 %01x \n", -9));
	printf("ret ft %d \n", ft_printf("ft 0 98 %01x \n", -9));

	printf("ret pf %d\n", printf("pf 0 112 %014x \n", ULONG_MAX));
	printf("ret ft %d\n", ft_printf("ft 0 112 %014x \n", ULONG_MAX));

	return (0);
}
