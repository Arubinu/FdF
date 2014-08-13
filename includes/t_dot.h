/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dot.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 21:49:32 by apergens          #+#    #+#             */
/*   Updated: 2014/08/13 23:13:17 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DOT_H
# define T_DOT_H

# include "t_pos.h"

typedef struct		s_dot
{
	t_pos			pos;
	struct s_dot	*left;
	struct s_dot	*right;
	struct s_dot	*prev;
	struct s_dot	*next;
}					t_dot;

#endif
