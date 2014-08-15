/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ini.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 21:49:32 by apergens          #+#    #+#             */
/*   Updated: 2014/08/15 22:38:36 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_INI_H
# define T_INI_H

typedef struct		s_ini
{
	int				start;
	int				decal_x;
	int				first_x;
	int				first_y;
	double			factor;
}					t_ini;

#endif
