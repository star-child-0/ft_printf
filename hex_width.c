/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:47:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 11:47:24 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_width(int n)
{
	int	l;

	l = 1;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 15)
	{
		n /= 16;
		l++;
	}
	return (l);
}
