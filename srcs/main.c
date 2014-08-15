/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 20:01:11 by apergens          #+#    #+#             */
/*   Updated: 2014/08/13 17:24:00 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		main(int argc, char **argv)
{
	int		error;
	char	*ext;
	char	**file;
	t_env	env;

	++argv;
	error = 0;
	ext = NULL;
	file = NULL;
	if (--argc != 1)
		return (ft_exit(1, "Too few argument"));
	ext = ft_strrchr(*argv, '.');
	if (ext == NULL || ext == *argv || ft_strcmp(ext, ".fdf"))
		return (ft_exit(2, "Wrong file extension"));
	if (!(error = ft_parse_file(*argv, &file)))
		return (ft_exit(4, "Parsing file error"));
	else if (error == -1)
		return (ft_exit(3, strerror(errno)));
	else if (error == -2)
		return (ft_exit(5, "Memory allocation failure"));
	else if (error == -3)
		return (ft_exit(6, "Non-compliant file"));
	ft_draw_fdf(&file);
	ft_start_mlx(&env);
	return (0);
}
