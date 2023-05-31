/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:54:10 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 08:54:11 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	The bzero() function erases the data in the n bytes of the memory starting
	at the location pointed to by s, by writing zeros (bytes containing '\0')
	to that area.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
