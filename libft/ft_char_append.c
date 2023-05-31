/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:54:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 08:54:28 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	If s exist, append c to s, else allocate new string.
 * @param s
	String.
 * @param c
	Char to append.
 * @param need_to_free
	If true and string exist, frees the memory of the s.
 * @return
	Return new allocated string which is the result of s + c.
 */
char	*ft_char_append(char *s, char c, bool need_to_free)
{
	size_t	i;
	char	*str;

	if (!s)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (0);
		str[0] = c;
		str[1] = 0;
		return (str);
	}
	i = 0;
	while (s[i])
		i++;
	str = malloc(sizeof(char) * ++i + 1);
	if (!str)
		return (0);
	str[i - 1] = c;
	str[i--] = 0;
	while (i--)
		str[i] = s[i];
	if (need_to_free)
		free(s);
	return (str);
}
