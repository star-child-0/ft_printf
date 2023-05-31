/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:55:08 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 08:55:11 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
 	Checks for an alphanumeric character; it is equivalent to (isalpha(c) ||
	isdigit(c)).
 * @return
	The values returned are nonzero if the character c falls into the tested
	class, and zero if not.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) == 1 || ft_isdigit(c) == 1);
}
