/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declare_factor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/16 11:18:00 by apergens          #+#    #+#             */
/*   Updated: 2014/08/16 11:18:18 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_declare_factor(void)
{
	int		xy;
	t_ini	*ini;
	double	temp;
	double	factor;

	ini = ft_ini_fdf(NULL);
	xy = ft_save_fdf(NULL, 1)->x + ft_save_fdf(NULL, 2)->y;
	factor = SCREEN_X;
	factor /= DECAL_X * ((xy + FIRST_X) / 2);
	temp = SCREEN_Y;
	temp /= DECAL_Y * ((xy + FIRST_Y) / 2);
	ini->factor = (temp < factor) ? temp : factor;
	return ;
}
