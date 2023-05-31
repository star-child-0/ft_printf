/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:59:08 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 08:59:11 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
 	The memset() function fills the first n bytes of the memory area pointed to
	by s with the constant byte c.
 * @return
 	The memset() function returns a pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*ps;

	ps = (char *)s;
	while (n)
		ps[--n] = (char)c;
	return (ps);
}
