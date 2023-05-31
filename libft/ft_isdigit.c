/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:55:33 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 08:55:35 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	Checks for a digit (0 through 9).
 * @return
	The values returned are nonzero if the character c falls into the tested
	class, and zero if not.
 */
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
