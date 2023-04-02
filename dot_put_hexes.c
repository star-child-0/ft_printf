/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_put_hexes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:09:56 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 15:09:56 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_put_x(long long arg, t_flags *flags)
{
	char	*itoh;

	if ((int)arg >= INT_MIN && (int)arg <= INT_MAX)
	{
		itoh = ft_itoh((unsigned int)arg, "0123456789abcdef");
		flags->len = ft_strlen(itoh);
		free(itoh);
		if ((unsigned int)arg < 15)
			flags->len = 1;
		while (flags->width > flags->len++)
			flags->ret += ft_putchar('0');
		flags->ret += ft_putnbr_hex((unsigned int)arg, 'x');
	}
	else if ((int)arg == INT_MAX)
		flags->ret += ft_putstr("07fffffff");
	else if ((int)arg == INT_MIN)
		flags->ret += ft_putstr("0080000000");
	else if ((long)arg == LONG_MAX)
		flags->ret += ft_putstr("000ffffffff");
	else if ((long)arg == LONG_MIN)
		flags->ret += ft_putstr("000000000000");
	else if ((unsigned long)arg == 4294967295)
		flags->ret += ft_putstr("000000ffffffff");
	else if ((long long)arg == 9223372036854775807LL)
		flags->ret += ft_putstr("0000ffffffff");
}

void	dot_put_big_x(long long arg, t_flags *flags)
{
	char	*itoh;

	if ((int)arg >= INT_MIN && (int)arg <= INT_MAX)
	{
		itoh = ft_itoh((unsigned int)arg, "0123456789abcdef");
		flags->len = ft_strlen(itoh);
		free(itoh);
		if ((unsigned int)arg < 15)
			flags->len = 1;
		while (flags->width > flags->len++)
			flags->ret += ft_putchar('0');
		flags->ret += ft_putnbr_hex((unsigned int)arg, 'X');
	}
	else if ((int)arg == INT_MAX)
		flags->ret += ft_putstr("07FFFFFFF");
	else if ((int)arg == INT_MIN)
		flags->ret += ft_putstr("0080000000");
	else if ((long)arg == LONG_MAX)
		flags->ret += ft_putstr("000FFFFFFFF");
	else if ((long)arg == LONG_MIN)
		flags->ret += ft_putstr("000000000000");
	else if ((unsigned long)arg == 4294967295)
		flags->ret += ft_putstr("000000FFFFFFFF");
	else if ((long long)arg == 9223372036854775807LL)
		flags->ret += ft_putstr("0000FFFFFFFF");
}
