/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:48:30 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 15:14:59 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		while (flags->width - ft_nbrlen(arg) + 1 > ++i)
			flags->ret += ft_putchar('0');
		flags->ret += ft_putstr("2147483648");
		return ;
	}
	if (arg < 0)
	{
		flags->ret += ft_putchar('-');
		arg *= -1;
	}
	if (!flags->width && !arg)
		return ;
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
	if (!arg)
		return ;
	while (i < flags->width && arg[i])
		flags->ret += ft_putchar(arg[i++]);
}

int	dot_handler(const char *str, int i, va_list args, t_flags *flags)
{
	int		arg;

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
	else if (str[i] == 's')
		return (i);
	else
	{
		arg = va_arg(args, int);
		if (arg)
			flags->ret += ft_putnbr(arg);
	}
	flags->width = 0;
	return (i);
}
