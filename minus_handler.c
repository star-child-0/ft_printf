/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:59:31 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 15:14:21 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	minus_string(va_list args, t_flags *flags)
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
	if (flags->width == 0 && arg == 0)
		return (0);
	flags->ret += ft_putnbr(arg);
	return (len);
}

int	minus_unsign(const char *str, int i, va_list args, t_flags *flags)
{
	int				len;
	unsigned int	arg;

	arg = va_arg(args, unsigned int);
	if (str[i] == 'u')
	{
		len = ft_nbrlen(arg);
		flags->ret += ft_putunsign_nbr(arg);
	}
	else if (str[i] == 'X')
	{
		len = ft_putnbr_hex(arg, 'X');
		flags->ret += len;
	}
	else if (str[i] == 'x')
	{
		len = ft_putnbr_hex(arg, 'x');
		flags->ret += len;
	}
	return (len);
}

void	minus_type(const char *str, int i, va_list args, t_flags *flags)
{
	int			len;
	int			n;
	uintptr_t	arg;

	len = 0;
	if (str[i] == 's')
		len = minus_string(args, flags);
	else if (str[i] == 'c' && len++ > -1)
		flags->ret += ft_putchar(va_arg(args, int));
	else if (str[i] == 'd' || str[i] == 'i')
		len = minus_int(args, flags);
	else if (str[i] == 'u' || str[i] == 'X' || str[i] == 'x')
		len = minus_unsign(str, i, args, flags);
	else if (str[i] == 'p')
	{
		arg = va_arg(args, uintptr_t);
		n = ft_put_pointer(arg);
		flags->ret += n;
		len = n;
	}
	while (flags->width > len++)
		flags->ret += ft_putchar(' ');
	flags->width = 0;
}

int	minus_handler(const char *str, int i, va_list args, t_flags *flags)
{
	int	j;

	if (str[i + 1] == '.')
	{
		i++;
		flags->dot = 1;
	}
	if (str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		j = i + 1;
		while (str[j] >= '0' && str[j] <= '9')
			flags->width = flags->width * 10 + str[j++] - '0';
		i = j;
	}
	else
	{
		i++;
		flags->width = -1;
	}
	minus_type(str, i, args, flags);
	return (i);
}
