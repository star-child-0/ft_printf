/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:03:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 09:03:07 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	Reverse a string.
 * @param str
	String to reverse.
 * @return
	Returns the inverted string.
 */
char	*ft_strrev(char *str)
{
	char	c;
	int		i;
	int		n;

	if (!str)
		return (str);
	i = 0;
	n = ft_strlen(str);
	while (i < n / 2)
	{
		c = str[n - i - 1];
		str[n - i - 1] = str[i];
		str[i] = c;
		i++;
	}
	return (str);
}
