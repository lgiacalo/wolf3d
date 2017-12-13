/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 20:41:49 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/13 11:48:02 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	boucle_mlx(t_wolf *env)
{
	mlx_loop_hook(env->fen.mlx_ptr, &my_loop_funct, env);
	mlx_key_hook(env->fen.win_ptr, &my_release_funct, env);
	mlx_hook(env->fen.win_ptr, KEY_PRESS, KEY_PRESS_MASK, &my_press_funct, env);
	mlx_mouse_hook(env->fen.win_ptr, &my_mouse_funct, env);
	mlx_loop(env->fen.mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_wolf	*env;

	env = ft_wolf();
	if (!(env->tab = ft_file(argc, argv)))
		ft_error("Fichier incorrect !!", 2);
	ft_init_wolf(env);
	boucle(env);
	boucle_mlx(env);
	return (0);
}

// TODO: free env.tab !!
