/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 21:39:07 by apergens          #+#    #+#             */
/*   Updated: 2014/08/16 11:11:29 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_start_mlx(t_env *e, char *name)
{
	char	*basename;
	t_ini	*ini;

	ini = ft_ini_fdf(NULL);
	basename = ft_strrchr(name, '/');
	basename = (basename != NULL) ? basename + 1 : name;
	ini->name = basename;
	ft_declare_size(&ini->screen_x, &ini->screen_y, ft_ini_fdf(NULL));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, ini->screen_x, ini->screen_y, "fdf");
	mlx_key_hook(e->win, ft_key_hook, e);
	mlx_mouse_hook(e->win, ft_mouse_hook, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop(e->mlx);
	return ;
}
