/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:54:26 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 18:54:26 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_charl
{
	char			content;
	struct s_charl	*next;
}	t_charl;

typedef struct s_flags
{
	int		hash;
	int		space;
	int		plus;
	int		minus;
	int		zero;
	int		dot;
	int		width;
}	t_flags;

int		ft_strlf(const char *str, ...);
int		strl_format(va_list args, char ph, t_flags flags);
void	assembly_line(t_charl **string, t_flags *flags, char ph);

#endif
