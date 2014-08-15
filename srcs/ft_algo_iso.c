/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/15 09:11:15 by apergens          #+#    #+#             */
/*   Updated: 2014/08/15 17:50:44 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_algo_iso(t_pos *pos, int x, int y, int z)
{
	double	pre;

	pre = -0.471404520791 * FACTOR;
	pos->x = 0.707106781187 * ((x - y) * DECAL_X * FACTOR);
	pos->y = pre * (z * DECAL_Z);
	pos->y -= pre * ((x + y) * DECAL_Y);
	pos->x += 229;
	/*
	printf("  %d  %d  %d\n", x, y, z);
	pos->x = x * 20;
	pos->y = y * 20 - z;
	*/
	pos->x += 21;
	pos->y += 21;
	pos->z = 0;
	return ;
}
