/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 15:47:30 by apergens          #+#    #+#             */
/*   Updated: 2014/08/16 10:48:04 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_dot	*ft_save_fdf(t_dot *fdf, int choice)
{
	static t_dot	*save;
	static t_dot	*save_x;
	static t_dot	*save_y;
	static t_dot	*save_xy;

	save = (fdf != NULL && choice == 0) ? fdf : save;
	save_x = (fdf != NULL && choice == 1) ? fdf : save_x;
	save_y = (fdf != NULL && choice == 2) ? fdf : save_y;
	save_xy = (fdf != NULL && choice > 2) ? fdf : save_xy;
	if (choice >= 2)
		return ((choice == 2) ? save_y : save_xy);
	else if (choice == 1)
		return (save_x);
	return (save);
}
