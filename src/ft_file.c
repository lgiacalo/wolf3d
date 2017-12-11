/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:17:36 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/08 10:23:09 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		ft_putendl((char *)lst->content);
		lst = lst->next;
	}
	//TODO: supprimer cette fonction
}

void	ft_lstfree(t_list **alst)
{
	t_list	*tmp;

	while (*alst)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
		tmp = NULL;
	}
}

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

void	ft_display_liste(t_list **alst, int fd)
{
	char	*line;

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

	ft_printf("Debut lecture fichier !!\n");
	alst = NULL;
	ft_display_liste(&alst, fd);
	map = ft_create_map(alst);
	ft_lstfree(&alst);
	return (map);
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
	if (close(fd) == -1)
		ft_error("Probleme fermeture fichier", 0);
	return (map);
}
