/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 20:38:50 by apergens          #+#    #+#             */
/*   Updated: 2014/08/13 15:39:39 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_parse_file(char *file, char ***out)
{
	int		fd;
	int		gnl;
	char	*temp;
	char	*lines;

	gnl = 0;
	temp = NULL;
	lines = NULL;
	if (file == NULL || (fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while ((gnl = ft_get_next_line(fd, &temp)) > 0 && temp != NULL && *temp)
	{
		temp = ft_strfjoin1(&temp, "\n", 1);
		if (lines == NULL)
			lines = temp;
		else if ((lines = ft_strfjoin(&lines, &temp, 3)) == NULL)
			return (-2);
	}
	close(fd);
	if (gnl == -1 || !lines || (lines = ft_strfjoin(&lines, &temp, 3)) == NULL)
		return (-2);
	if (!ft_check_file(lines))
		return (-3);
	*out = ft_strfsplit(&lines, '\n', 1);
	return (1);
}
