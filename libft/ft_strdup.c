/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:05:22 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 09:05:25 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	The strdup() function returns a pointer to a new string which is a duplicate
	of the string s.
	Memory for the new string is obtained with malloc(3), and can be freed with
	free(3).
 * @return
	On success, the strdup() function returns a pointer to the duplicated
	string.
	It returns NULL if insufficient memory was available, with errno set to
	indicate the cause of the error.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	dup = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!dup)
		return (0);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	return (dup);
}
