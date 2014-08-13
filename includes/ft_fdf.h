/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:52:33 by apergens          #+#    #+#             */
/*   Updated: 2014/08/13 17:23:51 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <errno.h>
# include <fcntl.h>
# include <mlx.h>

# include "t_dirs.h"
# include "t_ldir.h"
# include "libft.h"
# include "libft_gnl.h"

# include "t_dot.h"
# include "t_env.h"
# include "t_pos.h"

extern int	errno;

t_dot		*ft_save_fdf(t_dot *fdf);
int			ft_exit(int ret, char *str);

int			ft_check_file(char *file);
int			ft_parse_file(char *file, char ***out);

void		ft_start_mlx(t_env *e);
void		ft_draw_fdf(char ***file);
void		ft_draw_all(t_env *e, t_dot *all);
void		ft_draw_line(t_env *e, t_pos *start, t_pos *end);

void		ft_declare_size(t_dot *all, int *width, int *height);

int			ft_expose_hook(t_env *e);
int			ft_key_hook(int keycode, t_env *e);
int			ft_mouse_hook(int button, int x, int y, t_env *e);

void		ft_set_pos(t_pos *pos, int x, int y, int z);

#endif
