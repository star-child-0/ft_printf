/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:01:33 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 09:01:34 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	Takes as a parameter a node and frees the memory of the node’s content using
	the function ’del’ given as a parameter and free the node.
	The memory of ’next’ must not be freed.
 * @param lst
	The node to free.
 * @param del
	The address of the function used to delete the content.
 */
void	t_print_delone(t_print *lst, void (*del)(void*))
{
	del(lst);
}
