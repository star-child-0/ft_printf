/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:48:30 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/31 12:43:25 by anvannin         ###   ########.fr       */
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

		// ft_putnbr(flags->len);
		// ft_putnbr(flags->width);

		free(itoh);
		if ((int)arg < 15)
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

void	dot_uint(const char *str, int i, va_list args, t_flags *flags)
{
	long long	arg;

	arg = va_arg(args, long long);
	if (str[i] == 'u')
	{
		flags->len = ft_nbrlen((unsigned int)arg);
		while (flags->width > flags->len++)
			flags->ret += ft_putchar('0');
		flags->ret += ft_putunsign_nbr(arg);
	}
	else if (str[i] == 'x')
		dot_put_x(arg, flags);
	else if (str[i] == 'X')
		dot_put_big_x(arg, flags);
}

void	dot_int(va_list args, t_flags *flags)
{
	int	i;
	int	arg;

	i = 0;
	arg = va_arg(args, int);
	if (arg == INT_MIN)
	{
		flags->ret += ft_putchar('-');
		while (i++ < flags->width - ft_nbrlen(arg))
			flags->ret += ft_putchar('0');
		flags->ret += ft_putstr("2147483648");
		return ;
	}
	if (arg < 0)
	{
		flags->ret += ft_putchar('-');
		arg *= -1;
	}
	while (i++ < flags->width - ft_nbrlen(arg))
		flags->ret += ft_putchar('0');
	flags->ret += ft_putnbr(arg);
}

void	dot_str(va_list args, t_flags *flags)
{
	int		i;
	char	*arg;

	i = 0;
	arg = va_arg(args, char *);

	if (!arg[0])
		return ;
	while (i < flags->width && arg[i])
		flags->ret += ft_putchar(arg[i++]);
}

int	dot_handler(const char *str, int i, va_list args, t_flags *flags)
{
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
			flags->width = flags->width * 10 + (str[i++] - '0');
		if (str[i] == 's')
			dot_str(args, flags);
		else if (str[i] == 'd' || str[i] == 'i')
			dot_int(args, flags);
		else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
			dot_uint(str, i, args, flags);
	}
	flags->width = 0;
	return (i);
}
