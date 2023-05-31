/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:55:26 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 08:55:28 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
 	Checks whether c is a 7-bit unsigned char value that fits into the ASCII
	character set.
 * @return
 	The values returned are nonzero if the character c falls into the tested
	class, and zero if not.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
