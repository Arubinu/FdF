/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 15:47:30 by apergens          #+#    #+#             */
/*   Updated: 2014/08/13 16:22:02 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_dot	*ft_save_fdf(t_dot *fdf)
{
	static t_dot	*save;

	save = (fdf != NULL) ? fdf : save;
	return (save);
}
