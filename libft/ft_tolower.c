/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:02:39 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 09:02:40 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	This function convert uppercase letters to lowecase.

	If c is an uppercase letter, tolower() returns its lowercase equivalent, if
	a lowercase representation exists in the current locale, otherwise, it
	returns c.

	If c is neither an unsigned char value nor EOF, the behavior of this
	function is undefined.
 * @return
	The value returned is that of the converted letter, or c if the conversion
	was not possible.
 */
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
