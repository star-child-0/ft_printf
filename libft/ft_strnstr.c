/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:03:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 09:03:25 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	The strnstr() function locates the first occurrence of the null-terminated
	string little in the string big, where not more than len characters are
	searched.
	Characters that	appear after a ‘\0’ character are not searched.
	Since the strnstr() function is a FreeBSD specific API, it should only be
	used when portability is not a concern.
 * @return
	If little is an empty string, big is returned; if little occurs nowhere in
	big, NULL is returned; otherwise a pointer to the first character of the
	first occurrence of little is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[j])
		return ((char *) big);
	while (i < len && big[i])
	{
		if (big[i] == little[j])
		{
			j++;
			if (ft_strlen(little) == j)
				return ((char *) big + (i - j + 1));
		}
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	return (0);
}
