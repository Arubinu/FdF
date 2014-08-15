/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 10:26:25 by apergens          #+#    #+#             */
/*   Updated: 2014/08/13 23:13:14 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_set_pos(t_pos *pos, int x, int y, int z)
{
	if (pos == NULL)
		return ;
	pos->x = x;
	pos->y = y;
	pos->z = z;
	return ;
}
