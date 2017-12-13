/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:28:12 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/13 13:18:04 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_error(char *str, int us)
{
	ft_putstr_fd("Erreur : ", 2);
	if (str)
		ft_putendl_fd(str, 2);
	else
		ft_putendl_fd("inconnu", 2);
	if (us)
		ft_putendl_fd("Usage : ./wolf3d file", 2);
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

int		ft_abs(int n)
{
	return ((n >= 0) ? n : (-n));
}
