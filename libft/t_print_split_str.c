/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print_split_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:01:02 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 09:01:03 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	For each item in str, add node whit str item (char) as content.
 * @param str
	String to split.
 * @return
	New malloc() allocated linked list.
 */
t_print	*t_print_split_str(char *str, bool need_to_free)
{
	t_print	*lst;
	int		i;

	i = 0;
	lst = t_print_new_char_node(str[i]);
	while (str[i++ + 1])
		t_print_add_back(&lst, t_print_new_char_node(str[i]));
	if (need_to_free)
		ft_free((void **)&str);
	return (lst);
}
