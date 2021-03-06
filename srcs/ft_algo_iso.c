/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/15 09:11:15 by apergens          #+#    #+#             */
/*   Updated: 2014/08/15 22:58:29 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_algo_iso(t_pos *pos, int x, int y, int z)
{
	t_ini	*ini;
	double	pre;

	ini = ft_ini_fdf(NULL);
	pre = -0.471404520791 * ini->factor;
	pos->x = 0.707106781187 * ((x - y) * DECAL_X * ini->factor);
	pos->y = (pre * (z * DECAL_Z)) - (pre * ((x + y) * DECAL_Y));
	pos->x += ini->decal_x;
	pos->z = 0;
	return ;
}
