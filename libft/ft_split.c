/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:05:39 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 09:05:40 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_struct_init(struct s_split *s, char c)
{
	(*s).set[0] = c;
	(*s).i = 0;
	(*s).j = 0;
	(*s).k = 0;
	(*s).l = 0;
}

static int	ft_count_str(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c && ++j)
		{
			while (s[i] && s[i] == c)
				i++;
		}
		i++;
	}
	if (!*s)
		return (0);
	return (j);
}

/*!
 * @brief
	Allocates (with malloc(3)) and returns an array	of strings obtained by
	splitting ’s’ using the	character ’c’ as a delimiter.
	The array must end with a NULL pointer.
 * @param s
	The string to be split.
 * @param c
	The delimiter character.
 * @return
	The array of new strings resulting from the split.
	NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	struct s_split	var;
	char			*trimmed;
	char			**arr;

	ft_struct_init(&var, c);
	trimmed = ft_strtrim(s, var.set);
	if (!trimmed || !*trimmed)
		return (ft_calloc(1, sizeof(char *)));
	arr = ft_calloc((ft_count_str(trimmed, c) + 2), sizeof(char *));
	while (trimmed[var.i])
	{
		if (trimmed[var.i] == c)
		{
			while (trimmed[var.i] == c)
				var.i++;
			arr[var.k++] = ft_substr(trimmed, var.j, var.l);
			var.j = var.i;
			var.l = 0;
		}
		var.l++;
		var.i++;
	}
	arr[var.k] = ft_substr(trimmed, var.j, var.l);
	free(trimmed);
	return (arr);
}
