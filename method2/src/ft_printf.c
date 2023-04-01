/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:53:09 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 18:53:09 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_flag_value2(char *s, int i, char flag)
{
	char	*tmp;
	int		n;

	tmp = 0;
	n = 0;
	if (flag == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		tcharl_push(&tmp, s[i++]);
	i--;
	if (tmp)
		n = ft_atoi(tmp);
	if (!n)
		n = -1;
	free(tmp);
	return (n);
}

int	get_flag_value(char *s, int i, char flag, int can_repeat)
{
	int	value;

	value = 0;
	if (can_repeat)
	{
		while (s[i++] == flag)
			value++;
		if (flag == '-')
			i--;
	}
	else if (flag && !can_repeat)
		i++;
	if (flag == '-' && (s[i + 1] < '0' || s[i + 1] > '9')
		|| (flag == '.' || flag == '0' || flag == ' ') && (s[i] < '0'
			|| s[i] > '9'))
		return (-1);
	else if (flag == ' ')
		return (value);
	else
		return (get_flag_value2(s, i, flag));
}

t_flags	parse_flags(char *s, t_flags flags)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
			flags.hash = 1;
		else if (s[i] == ' ')
			flags.space = get_flag_value(s, i, ' ', 1);
		else if (s[i] == '+')
			flags.plus = 1;
		else if (s[i] == '-')
			flags.minus = get_flag_value(s, i, '-', 1);
		else if (s[i] == '0')
			flags.zero = get_flag_value(s, i, '0', 0);
		else if (s[i] == '.')
			flags.dot = get_flag_value(s, i, '.', 0);
		else if (s[i] >= '1' && s[i] <= '9')
			flags.width = get_flag_value(s, i, 'w', 0);
		i++;
	}
	return (flags);
}

t_flags	init_flags(char *str, int i)
{
	char	*s;
	t_flags	flags;

	s = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.width = 0;
	while (str[i] != 'c' && str[i] != 's' && str[i] != 'd' && str[i] != 'i'
		&& str[i] != 'u' && str[i] != 'p' && str[i] != 'x' && str[i] != 'X'
		&& str[i] != '%')
		s = tcharl_push(s, str[i++]);
	if (s)
	{
		flags = parse_flags(s, flags);
		free(s);
	}
	return (flags);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	int		i;
	va_list	args;
	t_flags	flags;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			flags = init_flags((char *)str, ++i);
		}
		else
			ret += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
}
