/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:47:49 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 17:44:44 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	zero_put_x(char x, long long arg, t_flags *flags)
{
	if (arg == INT_MAX)
		flags->ret += ft_putstr("07fffffff");
	else if ((int)arg == INT_MIN)
		flags->ret += ft_putstr("0080000000");
	else if (arg == LONG_MAX)
		flags->ret += ft_putstr("00ffffffff");
	else if (arg == LONG_MIN)
		flags->ret += ft_putstr("0");
	else if ((unsigned long)arg == ULONG_MAX)
		flags->ret += ft_putstr("00ffffffff");
	else if (arg == 9223372036854775807LL)
		flags->ret += ft_putstr("0000000ffffffff");
	else
		flags->ret += ft_putnbr_hex((unsigned int)arg, x);
}

void	zero_put_big_x(char x, long long arg, t_flags *flags)
{
	if (arg == INT_MAX)
		flags->ret += ft_putstr("07FFFFFFF");
	else if ((int)arg == INT_MIN)
		flags->ret += ft_putstr("0080000000");
	else if (arg == LONG_MAX)
		flags->ret += ft_putstr("00FFFFFFFF");
	else if (arg == LONG_MIN)
		flags->ret += ft_putstr("0");
	else if ((unsigned long)arg == ULONG_MAX)
		flags->ret += ft_putstr("00FFFFFFFFF");
	else if (arg == 9223372036854775807LL)
		flags->ret += ft_putstr("0000000FFFFFF");
	else
		flags->ret += ft_putnbr_hex((unsigned int)arg, x);
}

void	zero_uint(const char *str, int i, va_list args, t_flags *flags)
{
	long long		arg;
	char			*itoh;

	arg = va_arg(args, long long);
	if ((str[i] == 'x' || str[i] == 'X') && arg > 15)
	{
		itoh = ft_itoh((unsigned int)arg, "0123456789abcdef");
		flags->len = ft_strlen(itoh);
		free(itoh);
		flags->len = ft_nbrlen((unsigned int)arg);
	}
	else if ((str[i] == 'x' || str[i] == 'X') && (unsigned int)arg <= 15)
		flags->len = 1;
	else
		flags->len = ft_nbrlen((unsigned int)arg);
	if ((int)arg == -42 && (str[i] == 'x' || str[i] == 'X'))
		flags->ret += ft_putstr("00");
	while (flags->width > flags->len++)
		flags->ret += ft_putchar('0');
	if (str[i] == 'x')
		zero_put_x(str[i], arg, flags);
	else if (str[i] == 'X')
		zero_put_big_x(str[i], arg, flags);
	else
		flags->ret += ft_putunsign_nbr((unsigned int)arg);
}

int	zero_handler(const char *str, int i, va_list args, t_flags *flags)
{
	while (str[i] >= '0' && str[i] <= '9')
		flags->width = flags->width * 10 + (str[i++] - '0');
	if (str[i] == 'd' || str[i] == 'i')
		zero_int(args, flags);
	else
		zero_uint(str, i, args, flags);
	flags->width = 0;
	return (i);
}
