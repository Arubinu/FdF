/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ldir.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 21:45:41 by apergens          #+#    #+#             */
/*   Updated: 2014/04/18 15:21:32 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LDIR_H
# define T_LDIR_H

typedef struct	s_ldir
{
	struct dirent	*dirent;
	struct stat		*stat;
	struct s_ldir	*next;
}				t_ldir;

#endif
