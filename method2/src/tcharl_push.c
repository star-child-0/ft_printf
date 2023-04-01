/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcharl_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:34:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 19:34:24 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tcharl_push(t_charl **list, char c)
{
	t_charl	*new;

	new = malloc(sizeof(t_charl));
	new->content = c;
	new->next = *list;
	*list = new;
}
