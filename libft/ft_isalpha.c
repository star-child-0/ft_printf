/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:55:20 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 08:55:21 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	Checks  for  an  alphabetic  character; in the standard "C" locale, it is
	equivalent to (isupper(c) || islower(c)).  In some locales, there may be
	additional characters for which isalpha() is true—letters which are neither
	uppercase nor lowercase.
 * @return
 	The values returned are nonzero if the character c falls into the tested
	class, and zero if not.
 */
int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
