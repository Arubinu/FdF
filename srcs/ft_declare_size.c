/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declare_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 21:51:44 by apergens          #+#    #+#             */
/*   Updated: 2014/08/16 11:18:05 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_declare_size(int *width, int *height, t_ini *ini)
{
	t_pos	iso;
	t_pos	size;
	t_dot	*all;

	ft_declare_factor();
	ft_algo_iso(&iso, 0, 1, 0);
	ini->decal_x = -iso.x;
	all = ft_save_fdf(NULL, 1);
	ft_algo_iso(&iso, all->x, all->y, all->z);
	size.x = iso.x;
	size.y = -iso.y;
	all = ft_save_fdf(NULL, 2);
	ft_algo_iso(&iso, all->x, all->y, all->z);
	size.x -= iso.x;
	ini->decal_x += -iso.x;
	all = ft_save_fdf(NULL, 3);
	ft_algo_iso(&iso, all->x, all->y, all->z);
	size.y = iso.y;
	*width = size.x + (ini->first_x * 2) + 1;
	*height = size.y + (ini->first_y * 2) + 1;
	return ;
}
