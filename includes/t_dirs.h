/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dirs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 21:46:48 by apergens          #+#    #+#             */
/*   Updated: 2014/04/18 15:20:26 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DIRS_H
# define T_DIRS_H

# include "t_ldir.h"

typedef struct	s_dirs
{
	char	*name;
	t_ldir	*list;
}				t_dirs;

#endif
