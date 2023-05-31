/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:56:22 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 08:56:24 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	The memcpy() function copies n bytes from memory area src to memory area
	dest.
	The memory areas must not overlap.
	Use memmove(3) if the memory areas do overlap.
 * @return
	The memcpy() function returns a pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	i = 0;
	while (i++ < n)
		*d++ = *s++;
	return (dest);
}
