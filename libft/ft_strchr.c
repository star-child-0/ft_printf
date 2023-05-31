/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:05:29 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 09:05:30 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	The strchr() function return a pointer to the first occurrence of the
	character c in the string s.
 * @return
	The  strchr() function return a pointer to the matched character or NULL if
	the character is not found.
	The terminating null byte is considered part of the string, so that if c is
	specified as '\0', this function return a pointer to the terminator.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!c)
	{
		while (s[i])
			i++;
		return ((char *) s + i);
	}
	c %= 256;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) s + i);
		i++;
	}
	return (0);
}
