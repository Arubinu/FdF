/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ini.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 21:49:32 by apergens          #+#    #+#             */
/*   Updated: 2014/08/16 11:09:58 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_INI_H
# define T_INI_H

typedef struct		s_ini
{
	char			*name;
	int				start;
	int				screen_x;
	int				screen_y;
	int				decal_x;
	int				first_x;
	int				first_y;
	double			factor;
}					t_ini;

#endif
