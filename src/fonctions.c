/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:28:12 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/12 21:15:35 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_usage(void)
{
	ft_putendl_fd("Usage : ./wolf3d file", 2);
}

void	ft_error(char *str, int us)
{
	ft_putstr_fd("Erreur : ", 2);
	if (str)
		ft_putendl_fd(str, 2);
	else
		ft_putendl_fd("inconnu", 2);
	if (us)
		ft_usage();
	exit(0);
}

t_list	*ft_lstnew_light(void *content, size_t content_size)
{
	t_list	*new;

	new = NULL;
	new = (t_list *)ft_memalloc(sizeof(t_list) * 1);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = content;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

void	ft_arrayintdel(int ***tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (*tab && (*tab)[++i] != 0)
	{
		free(((*tab)[i]));
		(*tab)[i] = NULL;
	}
	free(*tab);
	*tab = NULL;
}

void	print_wolf(t_wolf *env)// TODO: a supprimer
{
	printf("\t\tStructure Wolf : \n");
	printf("===================================================================\n");
	printf("Len_tab\t\t[%d][%d]\n", env->len_tab.x, env->len_tab.y);
	printf("Pos\t\t\t[%lf][%lf]\n", env->pos.x, env->pos.y);
	printf("Dir\t\t\t[%lf][%lf]\n", env->dir.x, env->dir.y);
	printf("Norm\t\t[%lf][%lf]\n", env->norm.x, env->norm.y);
	printf("Camera\t\t[%lf]\n", env->cam);
	printf("Raypos\t\t[%lf][%lf]\n", env->raypos.x, env->raypos.y);
	printf("Raydir\t\t[%lf][%lf]\n", env->raydir.x, env->raydir.y);
	printf("Map\t\t\t[%d][%d]\n", env->map.x, env->map.y);
	printf("DeltaDist\t[%lf][%lf]\n", env->deltadist.x, env->deltadist.y);
	printf("SideDist\t[%lf][%lf]\n", env->sidedist.x, env->sidedist.y);
	printf("Step\t\t[%d][%d]\n", env->step.x, env->step.y);
	printf("Side\t\t[%d]\n", env->side);
	printf("WallDist\t\t[%lf]\n", env->walldist);
	printf("===================================================================\n");
}
