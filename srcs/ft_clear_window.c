/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/16 11:24:07 by apergens          #+#    #+#             */
/*   Updated: 2014/08/16 11:25:21 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_clear_window(t_env *e)
{
	int		calc;
	t_ini	*ini;

	ini = ft_ini_fdf(NULL);
	mlx_clear_window(e->mlx, e->win);
	if (ini->name != NULL)
		mlx_string_put(e->mlx, e->win, 5, 15, 0x5555EE, ini->name);
	calc = ini->screen_x - 106;
	mlx_string_put(e->mlx, e->win, calc, 15, 0xEE5555, "+ - < > ^ v SUPPR");
	return ;
}
