/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:47:49 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/30 21:03:21 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int	zero_handler(const char *str, int i, va_list args, t_flags *flags)
{
	int	n;
	int	l;

	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	l = ft_nbrlen(n);
	while (n > l++)
		flags->ret += ft_putchar('0');
	type_handler(str, i, args, flags);
	return (i);
}
*/

void	zero_int(va_list args, t_flags *flags)
{
	int	arg;

	arg = va_arg(args, int);
	flags->len = ft_nbrlen(arg);
	if (arg == INT_MIN)
	{
		flags->ret += ft_putchar('-');
		while (flags->width > flags->len++)
			flags->ret += ft_putchar('0');
		flags->ret += ft_putstr("2147483648");
		return ;
	}
	if (arg < 0)
	{
		flags->ret += ft_putchar('-');
		arg *= -1;
	}
	while (flags->width > flags->len++)
		flags->ret += ft_putchar('0');
	flags->ret += ft_putnbr(arg);
}

void	zero_unit(const char *str, int i, va_list args, t_flags *flags)
{
	unsigned int	arg;
	char			*itoh;

	arg = va_arg(args, unsigned int);
	if ((str[i] == 'x' || str[i] == 'X') && arg > 15)
	{
		itoh = ft_itoh(arg, "0123456789abcdef");
		flags->len = ft_strlen(itoh);
		free(itoh);
		flags->len = ft_nbrlen(arg);
	}
	else if ((str[i] == 'x' || str[i] == 'X') && arg <= 15)
		flags->len = 1;
	else
		flags->len = ft_nbrlen(arg);
	while (flags->width > flags->len++)
		flags->ret += ft_putchar('0');
	if (str[i] == 'x' || str[i] == 'X')
		flags->ret += ft_putnbr_hex(arg, str[i]);
	else
		flags->ret += ft_putunsign_nbr(arg);
}

int	zero_handler(const char *str, int i, va_list args, t_flags *flags)
{
	while (str[i] >= '0' && str[i] <= '9')
		flags->width = flags->width * 10 + (str[i++] - '0');
	if (str[i] == 'd' || str[i] == 'i')
		zero_int(args, flags);
	else
		zero_unit(str, i, args, flags);
	flags->width = 0;
	return (i);
}

