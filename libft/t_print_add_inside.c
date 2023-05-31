/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print_add_inside.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:01:48 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 09:01:48 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	Add n nodes to the list from the start position with the specified data.
 * @param head
	The address to the first node in the list.
 * @param start
	Position in the list from which to start adding nodes.
 * @param len
	Number of nodes to add.
 * @param data
	Content of the new nodes.
 */
void	t_print_add_inside(t_print **head, size_t start, size_t len, char data)
{
	t_print	*new;

	if (!start)
	{
		while (len--)
		{
			new = t_print_new_char_node(data);
			new->next = *head;
			*head = new;
		}
	}
	else
	{
		start--;
		while (start--)
			*head = (*head)->next;
		while (len--)
		{
			new = t_print_new_char_node(data);
			new->next = (*head)->next;
			(*head)->next = new;
		}
	}
}
