/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:03:35 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 09:03:36 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	Applies the function ’f’ to each character of the string ’s’, and passing
	its index as first argument to create a new string (with malloc(3))
	resulting from successive applications of ’f’.
 * @param s
	The string on which to iterate.
 * @param f
	The function to apply to each character.
 * @return
	The string created from the successive applications of ’f’.
	Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	char	c;

	i = 0;
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (0);
	while (s[i])
	{
		c = f(i, s[i]);
		str[i++] = c;
	}
	return (str);
}
