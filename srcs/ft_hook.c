/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 21:47:14 by apergens          #+#    #+#             */
/*   Updated: 2014/08/15 17:37:24 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_key_hook(int keycode, t_env *e)
{
	if (e && keycode == 65307)
		exit(0);
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_env *e)
{
	int		color;

	--x;
	--y;
	color = (button == 1) ? 0x00CCCC : 0xCCCC00;
	mlx_pixel_put(e->mlx, e->win, x - 1, y - 1, color);
	mlx_pixel_put(e->mlx, e->win, x, y - 1, color);
	mlx_pixel_put(e->mlx, e->win, x + 1, y - 1, color);
	mlx_pixel_put(e->mlx, e->win, x - 1, y, color);
	mlx_pixel_put(e->mlx, e->win, x, y, color);
	mlx_pixel_put(e->mlx, e->win, x + 1, y, color);
	mlx_pixel_put(e->mlx, e->win, x - 1, y + 1, color);
	mlx_pixel_put(e->mlx, e->win, x, y + 1, color);
	mlx_pixel_put(e->mlx, e->win, x + 1, y + 1, color);
	mlx_pixel_put(e->mlx, e->win, x, y - 2, color);
	mlx_pixel_put(e->mlx, e->win, x + 2, y, color);
	mlx_pixel_put(e->mlx, e->win, x, y + 2, color);
	mlx_pixel_put(e->mlx, e->win, x - 2, y, color);
	return (0);
}

int		ft_expose_hook(t_env *e)
{
	ft_putendl("EXPOSE");
	ft_draw_all(e, ft_save_fdf(NULL));
	return (!e || 0);
}
