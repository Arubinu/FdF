/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 15:47:30 by apergens          #+#    #+#             */
/*   Updated: 2014/08/15 22:00:21 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_ini	*ft_ini_fdf(t_ini *ini)
{
	static t_ini	save;

	if (!save.start && (save.start = 1))
		ft_ini_edit(FIRST_X, FIRST_Y, FACTOR, 0);
	if (ini != NULL)
	{
		save.first_x = ini->first_x;
		save.first_y = ini->first_y;
		save.factor = ini->factor;
	}
	return (&save);
}

void	ft_ini_edit(int first_x, int first_y, double factor, int choice)
{
	int				add;
	t_ini			*ini;

	ini = ft_ini_fdf(NULL);
	add = (choice < 0) ? 1 : 0;
	choice = add ? -choice : choice;
	if (!choice)
	{
		ini->first_x = first_x;
		ini->first_y = first_y;
		ini->factor = factor;
	}
	if (choice == 1 || choice == 4 || choice == 6)
		ini->first_x = add ? ini->first_x + first_x : first_x;
	if (choice == 2 || choice >= 4)
		ini->first_y = add ? ini->first_y + first_y : first_y;
	if (choice == 3 || choice >= 5)
		ini->factor = add ? ini->factor + factor : factor;
	ft_tree_ini();
	return ;
}
