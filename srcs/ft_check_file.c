/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 21:20:05 by apergens          #+#    #+#             */
/*   Updated: 2014/08/12 22:25:53 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_check_file(char *file)
{
	int		c;
	int		i;

	i = -1;
	if (file == NULL || *file == '\0' || *file == '\n')
		return (0);
	while (*(file + (++i)))
	{
		c = *(file + i);
		if (c != ' ' && c != '\n' && !ft_isdigit(c))
			return (0);
	}
	return (1);
}
