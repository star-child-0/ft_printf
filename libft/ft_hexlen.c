/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:54:57 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 08:55:11 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Calculates the length of a hexadecimal number.
 * @param n 
	Number.
 * @return 
	Returns a size_t representing the length of a number in hexadecimal format.
 */
size_t	ft_hexlen(size_t n)
{
	size_t	i;

	if (!n)
		return (1);
	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}
