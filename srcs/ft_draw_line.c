/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 22:43:46 by apergens          #+#    #+#             */
/*   Updated: 2014/08/15 22:36:26 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_draw_line_set_point(int *pos, int val)
{
	*pos = (val < 0) ? -1 : 0;
	*pos = (val > 0) ? 1 : *pos;
	return ;
}

static void	ft_draw_line_loop(t_env *e, t_pos *start, t_pos *dx, t_pos *dy)
{
	int		i;
	int		num;

	i = -1;
	num = dx->z >> 1;
	while (++i <= dx->z)
	{
		mlx_pixel_put(e->mlx, e->win, start->x, start->y, 0xFFFFFF);
		num += dy->z;
		if (num >= dx->z)
		{
			num -= dx->z;
			ft_set_pos(start, start->x + dx->x, start->y + dx->y, 0);
		}
		else
			ft_set_pos(start, start->x + dy->x, start->y + dy->y, 0);
	}
	return ;
}

static void	ft_draw_line_algo(t_env *e, t_pos *start, t_pos *end)
{
	t_pos	dx;
	t_pos	dy;
	t_pos	size;

	ft_set_pos(&size, end->x - start->x, end->y - start->y, 0);
	ft_draw_line_set_point(&dx.x, size.x);
	ft_draw_line_set_point(&dx.y, size.y);
	ft_draw_line_set_point(&dy.x, size.x);
	dy.y = 0;
	size.x = (size.x < 0) ? -size.x : size.x;
	size.y = (size.y < 0) ? -size.y : size.y;
	if (size.x <= size.y)
	{
		dy.x = 0;
		ft_set_pos(&size, size.y, size.x, 0);
		ft_draw_line_set_point(&dy.y, size.y);
	}
	dx.z = size.x;
	dy.z = size.y;
	ft_draw_line_loop(e, start, &dx, &dy);
	return ;
}

void		ft_draw_line(t_env *e, t_pos *start, t_pos *end)
{
	//printf("  %d  %d  %d  %d\n", start->x, start->y, end->x, end->y);
	if (start->x <= end->x && start->y <= end->y)
		ft_draw_line_algo(e, start, end);
	else
		ft_draw_line_algo(e, end, start);
	return ;
}
