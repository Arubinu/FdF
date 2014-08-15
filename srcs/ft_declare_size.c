/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declare_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 21:51:44 by apergens          #+#    #+#             */
/*   Updated: 2014/08/15 17:38:00 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_declare_size(t_dot *all, int *width, int *height)
{
	t_pos	iso;
	t_pos	size;
	t_dot	*temp;

	temp = all;
	while (temp->next)
		temp = temp->next;
	ft_algo_iso(&iso, temp->x, temp->y, temp->z);
	size.x = iso.x;
	size.y = -iso.y;

	temp = all;
	while (temp->right)
		temp = temp->right;
	ft_algo_iso(&iso, temp->x, temp->y, temp->z);
	size.x -= iso.x;

	while (temp->next)
		temp = temp->next;
	ft_algo_iso(&iso, temp->x, temp->y, temp->z);
	size.y = iso.y;

	*width = size.x + 1 + 42;
	*height = size.y + 1 + 42;
	return ;
}
