/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:34:01 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/30 19:41:52 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->len = 0;
	flags->ret = 0;
	return (flags);
}

int	type_handler(const char *str, int i, va_list args, t_flags *flags)
{
	if (str[i] == 'c')
		flags->ret += ft_putchar(va_arg(args, int));
	else if (str[i] == 's')
		flags->ret += ft_putstr(va_arg(args, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		flags->ret += ft_putnbr(va_arg(args, int));
	else if (str[i] == 'u')
		flags->ret += ft_putunsign_nbr(va_arg(args, unsigned int));
	else if (str[i] == 'p')
		flags->ret += ft_put_pointer(va_arg(args, uintptr_t));
	else if (str[i] == 'X' || str[i] == 'x')
		flags->ret += ft_putnbr_hex(va_arg(args, unsigned int), str[i]);
	else if (str[i] == '%')
		flags->ret += ft_putchar('%');
	return (i);
}

int	flags_handler(const char *str, int i, va_list args, t_flags *flags)
{
	if (str[i] == '+')
		i = plus_handler(i, args, flags);
	else if (str[i] == ' ')
		i = space_handler(str, i, args, flags);
	else if (str[i] == '#')
		i = hash_handler(str, i, args, flags);
	else if (str[i] == '-')
		i = minus_handler(str, i, args, flags);
	else if (str[i] == '0')
		i = zero_handler(str, ++i, args, flags);
	else if (str[i] >= '1' && str[i] <= '9')
		i = width_handler(str, i, args, flags);
	else
		i = type_handler(str, i, args, flags);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	t_flags	*flags;
	va_list	args;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	flags = init_flags(flags);
	i = -1;
	va_start(args, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
			i = flags_handler(str, ++i, args, flags);
		else
			flags->ret += ft_putchar(str[i]);
	}
	va_end(args);
	ret = flags->ret;
	free(flags);
	return (ret);
}
