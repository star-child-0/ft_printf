/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:01:47 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 17:44:44 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	plus_handler(int i, va_list args, t_flags *flags)
{
	int	n;

	n = va_arg(args, int);
	if (n >= 0)
		flags->ret += ft_putchar('+');
	flags->ret += ft_putnbr(n);
	return (++i);
}
