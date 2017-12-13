/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 20:41:49 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/13 17:00:32 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	Headers utiles :
**	- /System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h
*/

void	ft_free_map(int ***s, int size)
{
	int	i;

	i = -1;
	while (*s && ++i < size)
	{
		free(((*s)[i]));
		(*s)[i] = NULL;
	}
	free(*s);
	*s = NULL;
}

void	ft_end(t_wolf **env)
{
	mlx_destroy_image((*env)->fen.mlx_ptr, (*env)->fen.img_ptr);
	mlx_destroy_image((*env)->fen.mlx_ptr, (*env)->img[0].image);
	mlx_destroy_image((*env)->fen.mlx_ptr, (*env)->img[1].image);
	mlx_destroy_image((*env)->fen.mlx_ptr, (*env)->img[2].image);
	mlx_destroy_image((*env)->fen.mlx_ptr, (*env)->img[3].image);
	mlx_destroy_window((*env)->fen.mlx_ptr, (*env)->fen.win_ptr);
	ft_free_map(&((*env)->tab), (*env)->len_tab.x);
	free(*env);
	exit(0);
}

int		ft_croix_rouge(t_wolf *env)
{
	ft_end(&env);
	return (0);
}

void	boucle_mlx(t_wolf *env)
{
	mlx_loop_hook(env->fen.mlx_ptr, &my_loop_funct, env);
	mlx_key_hook(env->fen.win_ptr, &my_release_funct, env);
	mlx_hook(env->fen.win_ptr, KEY_PRESS, KEY_PRESS_MASK, &my_press_funct, env);
	mlx_hook(env->fen.win_ptr, DESTROY_NOTIFY, KEY_RELEASE_MASK,
			ft_croix_rouge, env);
	mlx_loop(env->fen.mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_wolf	*env;

	env = ft_wolf();
	if (!(env->tab = ft_file(argc, argv)))
		ft_error("Fichier incorrect !!", 0);
	ft_init_wolf(env);
	boucle(env);
	boucle_mlx(env);
	return (0);
}
