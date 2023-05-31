/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:58:57 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 08:58:58 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	The memmove() function copies n bytes from memory area src to memory area
	dest.
	The memory areas may overlap: copying takes place as though the bytes in src
	are first copied into a temporary array that does not overlap src or dest,
	and the bytes are then copied from the temporary array to dest.
 * @return
	The memmove() function returns a pointer to dest.
 */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (dst > src)
	{
		while (n--)
			d[n] = s[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
