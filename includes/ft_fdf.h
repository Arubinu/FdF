/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:52:33 by apergens          #+#    #+#             */
/*   Updated: 2014/08/16 11:25:16 by apergens         ###   ########.fr       */
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
# include "t_ini.h"
# include "t_pos.h"

# define SCREEN_X	1600
# define SCREEN_Y	900

# define FIRST_X	21
# define FIRST_Y	21
# define FACTOR		1.8

# define DECAL_X	18
# define DECAL_Y	23.5
# define DECAL_Z	3

extern int	errno;

t_ini		*ft_ini_fdf(t_ini *ini);
t_ini		*ft_ini_edit(int first_x, int first_y, double factor, int choice);
t_dot		*ft_save_fdf(t_dot *fdf, int choice);
void		ft_clear_window(t_env *e);
int			ft_exit(int ret, char *str);

int			ft_check_file(char *file);
int			ft_parse_file(char *file, char ***out);

void		ft_start_mlx(t_env *e, char *name);
void		ft_tree_ini(void);
void		ft_tree_fdf(char ***file);
void		ft_draw_all(t_env *e, t_dot *all);
void		ft_draw_line(t_env *e, t_pos *start, t_pos *end);

void		ft_declare_factor(void);
void		ft_declare_size(int *width, int *height, t_ini *ini);

int			ft_expose_hook(t_env *e);
int			ft_key_hook(int keycode, t_env *e);
int			ft_mouse_hook(int button, int x, int y, t_env *e);

void		ft_set_pos(t_pos *pos, int x, int y, int z);
void		ft_algo_iso(t_pos *pos, int x, int y, int z);

#endif
