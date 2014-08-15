/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 21:39:07 by apergens          #+#    #+#             */
/*   Updated: 2014/08/15 23:17:48 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_start_mlx(t_env *e)
{
	int		width;
	int		height;

	ft_declare_size(ft_save_fdf(NULL), &width, &height);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, width, height, "fdf");
	mlx_key_hook(e->win, ft_key_hook, e);
	mlx_mouse_hook(e->win, ft_mouse_hook, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop(e->mlx);
	return ;
}
