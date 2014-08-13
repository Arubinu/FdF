/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:31:17 by apergens          #+#    #+#             */
/*   Updated: 2014/03/10 16:25:59 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tablen(char **arr)
{
	int		i;

	i = 0;
	if (arr == NULL || *arr == NULL)
		return (i);
	while (*(arr + i) != NULL)
		i++;
	return (i);
}
