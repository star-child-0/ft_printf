/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:05:18 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 09:05:19 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	Applies the function ’f’ on each character of the string passed as argument,
	passing its index as first argument.
	Each character is passed by address to ’f’ to be modified if necessary.
 * @param s
	The string on which to iterate.
 * @param f
	The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	char	*c;

	i = -1;
	while (s[++i])
	{
		c = &s[i];
		f(i, c);
	}
}
