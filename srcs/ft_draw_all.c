/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 11:23:32 by apergens          #+#    #+#             */
/*   Updated: 2014/08/15 07:17:46 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_draw_all(t_env *e, t_dot *all)
{
	if (all != NULL)
	{
		printf(" %p  [\t%d\t%d\t%d\t]  [\t%d\t%d\t%d\t]  %s  %s  %s  %s\n", all, all->x, all->y, all->z, all->pos.x, all->pos.y, all->pos.z, all->prev ? " OK " : "NULL", all->next ? " OK " : "NULL", all->left ? " OK " : "NULL", all->right ? " OK " : "NULL");
		mlx_pixel_put(e->mlx, e->win, 250 + all->x * 20, 250 + all->y * 20, 0xCC00CC);

		if (all->prev)
			ft_draw_line(e, &all->pos, &all->prev->pos);
		if (all->left)
			ft_draw_line(e, &all->pos, &all->left->pos);

		ft_draw_all(e, all->next);
		ft_draw_all(e, all->right);

/*
 * Commenter les deux lignes du dessus pour le test (t_pos différent de x,y,z).
 * Ne pas oublier de décommenter les lignes qui suivent dans ce commentaire.
		if (all->next)
			printf(" %p  [\t%d\t%d\t%d\t]  %s  %s  %s  %s  N\n", all->next, all->next->pos.x, all->next->pos.y, all->next->pos.z, all->next->prev ? " OK " : "NULL", all->next->next ? " OK " : "NULL", all->next->left ? " OK " : "NULL", all->next->right ? " OK " : "NULL");
		ft_draw_all(e, all->next);
*/
	}
	return ;
}
