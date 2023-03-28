/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:59:31 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/28 21:54:32 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	minus_handler(const char *str, int i, va_list args, t_flags *flags)
{
	int	j;

	j = i + 1;
	if (str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		while (str[j] >= '0' && str[j] <= '9')
			flags->width = flags->width * 10 + str[j++] - '0';
		i = j;
		minus_printf_handler(str, i, args, flags);
	}
	return (i);
}

void	minus_printf_handler(const char *str, int i, va_list args, t_flags *flags)
{
	int			len;
	uintptr_t	arg;

	len = 0;
	if (str[i] == 's')
		len = minus_sting(args, flags);
	else if (str[i] == 'c' && len++ > -1)
		flags->ret += ft_putchar(va_arg(args, int));
	else if (str[i] == 'd' || str[i] == 'i')
		minus_int(args, flags);
	else if (str[i] == 'u' || str[i] == 'X' || str[i] == 'x')
		minus_unsign(str, i, args, flags);
	else if (str[i] == 'p')
	{
		arg = va_arg(args, uintptr_t);
		len = ft_nbrlen((uintptr_t)arg);
		flags->ret += ft_put_pointer(arg);
	}
	while (flags->width > len++)
		flags->ret += ft_putchar(' ');
}

int	minus_sting(va_list args, t_flags *flags)
{
	int		len;
	char	*arg;

	arg = va_arg(args, char *);
	len = ft_strlen(arg);
	flags->ret += ft_putstr(arg);
	return (len);
}

int	minus_int(va_list args, t_flags *flags)
{
	int		len;
	int		arg;

	arg = va_arg(args, int);
	len = ft_nbrlen(arg);
	flags->ret += ft_putnbr(arg);
	return (len);
}

int	minus_unsign(const char *str, int i, va_list args, t_flags *flags)
{
	int				len;
	unsigned int	arg;

	arg = va_arg(args, unsigned int);
	len = ft_nbrlen(arg);
	if (str[i] == 'u')
		flags->ret += ft_putunsign_nbr(arg);
	else if (str[i] == 'X')
		flags->ret += ft_putnbr_hex(arg, 'X');
	else if (str[i] == 'x')
		flags->ret += ft_putnbr_hex(arg, 'x');
	return (len);
}
