/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:59:31 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/28 19:58:07 by anvannin         ###   ########.fr       */
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
		ft_putnbr(flags->width);
		ft_putchar(str[i]);
	}
	return (i);
}
