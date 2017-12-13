/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:04:41 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/13 14:50:43 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_isarray_rect(char **mapc)
{
	int	i;
	int	save;
	int	ret;

	i = -1;
	save = (int)ft_strlen(mapc[0]);
	while (mapc && mapc[++i])
	{
		ret = (int)ft_strlen(mapc[i]);
		if (save != ret)
			return (0);
	}
	if (mapc && *mapc)
		return (1);
	return (0);
}

int	*ft_trans(char *str)
{
	int	*ret;
	int	len;
	int	i;

	if (!str || !*str)
		return (NULL);
	len = ft_strlen(str) / 2;
	ret = (int *)ft_memalloc(sizeof(int) * (len + 1));
	len = -1;
	i = -1;
	while (str && str[++len])
	{
		if (!(len % 2))
			ret[++i] = str[len] - '0';
	}
	return (ret);
}

int	ft_isgoodformat(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i] != '\0')
	{
		if ((i % 2) && str[i] != ' ')
			return (0);
		else if (!(i % 2) && (!ft_isdigit(str[i])))
			return (0);
	}
	if (str && *str)
		return (1);
	return (0);
}

int	**ft_check_file(char **mapc)
{
	int	**map;
	int	len;
	int	i;

	map = NULL;
	if (ft_isarray_rect(mapc))
	{
		i = -1;
		len = ft_arraylen(mapc);
		map = (int **)ft_memalloc(sizeof(int *) * (len + 1));
		ft_wolf()->len_tab.x = len;
		map[len] = 0;
		while (mapc && mapc[++i] && (len != -1))
		{
			map[i] = 0;
			if (ft_isgoodformat(mapc[i]))
				map[i] = ft_trans(mapc[i]);
			else
				len = -1;
		}
		(len == -1) ? ft_arrayintdel(&map) : 0;
	}
	ft_wolf()->len_tab.y = 1 + ft_strlen(*mapc) / 2;
	ft_arraydel(&mapc);
	return (map);
}
