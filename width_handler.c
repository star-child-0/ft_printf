/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:38:06 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/29 18:38:06 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_string(va_list args, t_flags *flags)
{
	int		len;
	char	*arg;

	arg = va_arg(args, char *);
	if (arg == NULL)
		arg = "(null)";
	len = ft_strlen(arg);
	while (flags->width > len++)
		flags->ret += ft_putchar(' ');
	flags->ret += ft_putstr(arg);
	return (len);
}

int	width_int(va_list args, t_flags *flags)
{
	int		len;
	int		n;
	int		arg;

	arg = va_arg(args, int);
	n = ft_putnbr(arg);
	flags->ret += n;
	len = n;
	return (len);
}

int	width_unsign(const char *str, int i, va_list args, t_flags *flags)
{
	int		len;
	int		n;
	int		arg;

	arg = va_arg(args, int);
	if (str[i] == 'u')
		n = ft_putunsign_nbr(arg);
	else if (str[i] == 'X')
		n = ft_putnbr_hex(arg, 'X');
	else if (str[i] == 'x')
		n = ft_putnbr_hex(arg, 'x');
	flags->ret += n;
	len = n;
	return (len);
}

void	width_type(const char *str, int i, va_list args, t_flags *flags)
{
	int			len;
	int			n;
	uintptr_t	arg;

	len = 0;
	if (str[i] == 's')
		len = width_string(args, flags);
	else if (str[i] == 'c' && len++ > -1)
		flags->ret += ft_putchar(va_arg(args, int));
	else if (str[i] == 'd' || str[i] == 'i')
		len = width_int(args, flags);
	else if (str[i] == 'u' || str[i] == 'X' || str[i] == 'x')
		len = width_unsign(str, i, args, flags);
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

int	width_handler(const char *str, int i, va_list args, t_flags *flags)
{
	int	j;

	j = i;
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[j] >= '0' && str[j] <= '9')
			flags->width = flags->width * 10 + str[j++] - '0';
		i = j;
		width_type(str, i, args, flags);
	}
	return (i);
}
