/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 11:23:32 by apergens          #+#    #+#             */
/*   Updated: 2014/08/16 09:38:13 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
/* Itératif minimaliste
void		ft_draw_all(t_env *e, t_dot *all)
{
	t_dot	*temp;

	while (all != NULL)
	{
		temp = all;
		while (temp != NULL)
		{
			if (!temp->edit)
			{
				temp->edit = 1;
				ft_algo_iso(&temp->save, temp->pos.x, temp->pos.x, temp->pos.x);
			}
			mlx_pixel_put(e->mlx, e->win, temp->save.x, temp->save.y, 0xCC00CC);

			if (temp->prev)
				ft_draw_line(e, &temp->save, &temp->prev->save);
			if (temp->left)
				ft_draw_line(e, &temp->save, &temp->left->save);
			temp = temp->next;
		}
		all = all->right;
	}
	return ;
}
*/
// Itératif détaillé
void		ft_draw_all(t_env *e, t_dot *all)
{
	t_ini	*ini;
	t_dot	*temp;
	t_pos	curr_pos;
	t_pos	other_pos;

	ini = ft_ini_fdf(NULL);
	while (all != NULL)
	{
		temp = all;
		while (temp != NULL)
		{
			if (!temp->edit)
			{
				temp->edit = 1;
				ft_algo_iso(&curr_pos, temp->x, temp->y, temp->z);
				curr_pos.x = curr_pos.x + ini->first_x;
				curr_pos.y = curr_pos.y + ini->first_y;
				temp->x2 = curr_pos.x;
				temp->y2 = curr_pos.y;
				temp->z2 = curr_pos.z;
			}
			else
				ft_set_pos(&curr_pos, temp->x2, temp->y2, temp->z2);
			mlx_pixel_put(e->mlx, e->win, curr_pos.x, curr_pos.y, 0xCC00CC);

			if (temp->prev)
			{
				ft_set_pos(&other_pos, temp->prev->x2, temp->prev->y2, temp->prev->z2);
				ft_draw_line(e, &curr_pos, &other_pos);
			}

			if (temp->left)
			{
				ft_set_pos(&other_pos, temp->left->x2, temp->left->y2, temp->left->z2);
				ft_draw_line(e, &curr_pos, &other_pos);
			}
			temp = temp->next;
		}
		all = all->right;
	}
	return ;
}
/* Récursif minimaliste
void		ft_draw_all(t_env *e, t_dot *all)
{
	if (all != NULL)
	{
		if (!all->edit && (all->edit = 1))
			ft_algo_iso(&all->save, all->pos.x, all->pos.y, all->pos.z);
		//mlx_pixel_put(e->mlx, e->win, all->save.x, all->save.y, 0xCC00CC);

		if (all->prev)
			ft_draw_line(e, &all->save, &all->prev->save);
		if (all->left)
			ft_draw_line(e, &all->save, &all->left->save);

		ft_draw_all(e, all->next);
		ft_draw_all(e, all->right);
	}
	return ;
}
*/
/* Récursif détaillé
void		ft_draw_all(t_env *e, t_dot *all)
{
	t_pos	curr_pos;
	t_pos	other_pos;

	if (all != NULL)
	{
		if (!all->edit)
		{
			all->edit = 1;
			ft_algo_iso(&curr_pos, all->x, all->y, all->z);
			//ft_algo_iso(&curr_pos, all->pos.x, all->pos.y, all->pos.z);
			all->x2 = curr_pos.x;
			all->y2 = curr_pos.y;
			all->z2 = curr_pos.z;
		}
		else
			ft_set_pos(&curr_pos, all->x2, all->y2, all->z2);
		mlx_pixel_put(e->mlx, e->win, curr_pos.x, curr_pos.y, 0xCC00CC);

		if (all->prev)
//			ft_draw_line(e, &all->pos, &all->prev->pos);
		{
			//ft_set_pos(&other_pos, all->prev->x2, all->prev->y2, all->prev->z2);
			//ft_draw_line(e, &curr_pos, &other_pos);
			//ft_draw_line(e, &curr_pos, &all->prev->pos);
			//printf("  %d  %d  %d  %d\n", curr_pos.x, curr_pos.y, other_pos.x, other_pos.y);
		}

		if (all->left)
//			ft_draw_line(e, &all->pos, &all->left->pos);
		{
			ft_set_pos(&other_pos, all->left->x2, all->left->y2, all->left->z2);
			ft_draw_line(e, &curr_pos, &other_pos);
			//ft_draw_line(e, &curr_pos, &all->left->pos);
			printf("  %d  %d  %d  %d\n", curr_pos.x, curr_pos.y, other_pos.x, other_pos.y);
		}

		ft_draw_all(e, all->next);
		ft_draw_all(e, all->right);

*
 * Commenter les deux lignes du dessus pour le test (t_pos différent de x,y,z).
 * Ne pas oublier de décommenter la ligne qui suivent dans ce commentaire.
		printf(" %p  [\t%d\t%d\t%d\t]  [\t%d\t%d\t%d\t]  %s  %s  %s  %s\n", all, all->x, all->y, all->z, all->pos.x, all->pos.y, all->pos.z, all->prev ? " OK " : "NULL", all->next ? " OK " : "NULL", all->left ? " OK " : "NULL", all->right ? " OK " : "NULL");
		ft_draw_all(e, all->next);
*
	}

	return ;
}
*/
