/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 21:47:14 by apergens          #+#    #+#             */
/*   Updated: 2014/08/16 11:23:50 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_key_hook(int keycode, t_env *e)
{
	t_ini	*ini;

	if (e)
	{
		ini = ft_ini_fdf(NULL);
		if (keycode == 65307 && (mlx_destroy_window(e->mlx, e->win) || keycode))
			exit(0);
		else if (keycode == 65535 && ft_ini_edit(FIRST_X, FIRST_Y, FACTOR, 0))
			ft_declare_factor();
		else if (keycode == 65451)
			ft_ini_edit(-4, -9, 0.1, -6);
		else if (keycode == 65453)
			ft_ini_edit(4, 9, -0.1, -6);
		else if (keycode == 65362)
			ft_ini_edit(0, -5, 0, -2);
		else if (keycode == 65364)
			ft_ini_edit(0, 5, 0, -2);
		else if (keycode == 65361)
			ft_ini_edit(-5, 0, 0, -1);
		else if (keycode == 65363)
			ft_ini_edit(5, 0, 0, -1);
		ft_clear_window(e);
		ft_draw_all(e, ft_save_fdf(NULL, 0));
	}
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
	ft_clear_window(e);
	ft_draw_all(e, ft_save_fdf(NULL, 0));
	return (!e || 0);
}
