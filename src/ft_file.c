/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:17:36 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/13 14:50:41 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	**ft_create_map(t_list *lst)
{
	char	**map;
	int		len;

	len = ft_lstsize(lst);
	map = (char **)ft_memalloc(sizeof(char *) * (len + 1));
	map[len] = NULL;
	len = 0;
	while (lst)
	{
		map[len] = (char *)lst->content;
		lst->content = NULL;
		lst = lst->next;
		len++;
	}
	return (map);
}

int		ft_verif_position(t_wolf *env, char *line)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(line);
	if (len > 5 || len < 3)
		return (0);
	while (line && line[++i] != '\0')
		if (!ft_isdigit(line[i]) && line[i] != ' ')
			return (0);
	if (line[0] == ' ')
		return (0);
	env->pos.y = ft_atoi(line);
	env->pos.x = ft_atoi(line + ((env->pos.y >= 10) ? 2 : 1));
	return (1);
}

void	ft_display_liste(t_list **alst, int fd)
{
	char	*line;

	if (get_next_line(fd, &line) <= 0)
		ft_error("Ta map est nulle :(", 0);
	if (!ft_verif_position(ft_wolf(), line))
		ft_error("Mauvaise position", 0);
	else
		ft_strdel(&line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstadd_end(alst,\
			(ft_lstnew_light((void*)line, ft_strlen(line))));
		line = NULL;
	}
}

char	**ft_reading_file(int fd)
{
	char	**map;
	t_list	*alst;

	alst = NULL;
	ft_display_liste(&alst, fd);
	map = ft_create_map(alst);
	ft_lstfree(&alst);
	return (map);
}

void	ft_verif_map(t_wolf *env, int **map)
{
	int	i;

	i = -1;
	while (map && ++i < env->len_tab.y)
		if (map[0][i] != 1 || map[env->len_tab.x - 1][i] != 1)
			ft_error("Map non conforme !", 0);
	i = -1;
	while (map && ++i < env->len_tab.x)
		if (map[i][0] != 1 || map[i][env->len_tab.y - 1] != 1)
			ft_error("Map non conforme !", 0);
}

int		**ft_file(int argc, char **argv)
{
	char	**mapc;
	int		**map;
	int		fd;

	if (argc != 2)
		ft_error("Nombre d'argument incorrect !!", 1);
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		ft_error("Probleme ouverture fichier", 0);
	mapc = ft_reading_file(fd);
	map = ft_check_file(mapc);
	ft_verif_map(ft_wolf(), map);
	if (close(fd) == -1)
		ft_error("Probleme fermeture fichier", 0);
	return (map);
}
