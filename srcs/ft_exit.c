/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/12 21:56:21 by apergens          #+#    #+#             */
/*   Updated: 2014/08/12 21:56:30 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_exit(int ret, char *str)
{
	if (str != NULL && *str)
	{
		ft_putstr("fdf: ");
		ft_putendl(str);
	}
	return (ret);
}
