/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 22:26:09 by apergens          #+#    #+#             */
/*   Updated: 2014/08/13 23:15:41 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_draw_fdf_line(char **line, int i, t_dot *curr, t_dot *left)
{
	int		j;

	j = -1;
	ft_save_fdf(i ? NULL : curr);
	while (curr != NULL && ++j >= 0 && *(line + j) != NULL)
	{
		if (!j)
			curr->prev = NULL;
		else
		{
			curr->next = NULL;
			if (!*(line + j) || !(curr->next = (t_dot *)malloc(sizeof(t_dot))))
				break ;
			ft_memset(curr->next, 0, sizeof(t_dot));
			curr->next->prev = curr;
			curr = curr->next;
		}
		ft_set_pos(&curr->pos, j, i, ft_atoi(*(line + j)));
		curr->left = left;
		curr->right = NULL;
		if (left)
			left->right = curr;
		left = (left && left->next) ? left->next : NULL;
	}
	return ;
}

void		ft_draw_fdf(char ***file)
{
	int		i;
	int		len;
	t_dot	*fdf;
	char	**line;

	len = ft_tablen(*file);
	if (!len || (fdf = (t_dot *)malloc(sizeof(t_dot) * (len + 1))) == NULL)
	{
		ft_exit(7, "Memory allocation failure");
		return ;
	}
	ft_memset(fdf, 0, sizeof(t_dot));
	i = -1;
	line = NULL;
	while (++i < len && *(*file + i) != NULL)
	{
		if ((line = ft_strsplit(*(*file + i), ' ')) == NULL)
		{
			ft_exit(8, "Memory allocation failure");
			return ;
		}
		ft_draw_fdf_line(line, i, &fdf[i], i ? &fdf[i - 1] : NULL);
		ft_free_strtab(&line);
	}
	ft_free_strtab(file);
	return ;
}
