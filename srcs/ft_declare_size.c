/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declare_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 21:51:44 by apergens          #+#    #+#             */
/*   Updated: 2014/08/15 22:53:29 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_declare_size(t_dot *all, int *width, int *height)
{
	t_pos	iso;
	t_pos	size;
	t_dot	*temp;

	ft_algo_iso(&iso, 0, 1, 0);
	ft_ini_fdf(NULL)->decal_x = -iso.x;
	temp = all;
	while (temp->next != NULL)
		temp = temp->next;
	ft_algo_iso(&iso, temp->x, temp->y, temp->z);
	size.x = iso.x;
	size.y = -iso.y;
	temp = all;
	while (temp->right != NULL)
		temp = temp->right;
	ft_algo_iso(&iso, temp->x, temp->y, temp->z);
	size.x -= iso.x;
	ft_ini_fdf(NULL)->decal_x += -iso.x;
	while (temp->next != NULL)
		temp = temp->next;
	ft_algo_iso(&iso, temp->x, temp->y, temp->z);
	size.y = iso.y;
	*width = size.x + (ft_ini_fdf(NULL)->first_x * 2) + 1;
	*height = size.y + (ft_ini_fdf(NULL)->first_y * 2) + 1;
	return ;
}
