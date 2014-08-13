/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/13 14:01:37 by apergens          #+#    #+#             */
/*   Updated: 2014/08/13 21:22:34 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int		i;
	int		n;
	int		a;

	i = -1;
	n = 0;
	a = 0;
	while (*(s + (++i)))
	{
		if (*(s + i) != c && (!i || (i > 0 && *(s + (i - 1)) == c)))
			n++;
		else if (*(s + i) == c)
			a++;
	}
	if (!a)
		return (0);
	else if (!n && ft_strlen(s))
		return (1);
	return (n);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		max;
	int		word;
	char	*copy;
	char	**split;

	if (s == NULL || *s == '\0' || (copy = ft_strdup(s)) == NULL)
		return (NULL);
	max = ft_count(copy, c);
	split = (char **)malloc(sizeof(char *) * (max + 1));
	ft_memset(split, 0, sizeof(char *) * (max + 1));
	i = -1;
	word = 0;
	while (word <= max && *(copy + (++i)) != '\0')
	{
		if (*(copy + i) != c && (!i || (i > 0 && *(copy + (i - 1)) == c)))
			*(split + (word++)) = copy + i;
	}
	ft_strreplace(copy, c, '\0');
	i = -1;
	while (*(split + (++i)) != NULL)
		*(split + i) = ft_strdup(*(split + i));
	ft_strdel(&copy);
	return (split);
}
