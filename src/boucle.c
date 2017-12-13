/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:54:30 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/13 14:51:06 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_rayon(t_wolf *env, int x)
{
	env->cam = ((2.00 * x) / (double)W) - 1.00;
	env->raypos.x = env->pos.x;
	env->raypos.y = env->pos.y;
	env->raydir.x = env->dir.x + env->norm.x * env->cam;
	env->raydir.y = env->dir.y + env->norm.y * env->cam;
	env->map.x = (int)env->raypos.x;
	env->map.y = (int)env->raypos.y;
	env->deltadist.x = sqrt(1 +
	(env->raydir.y * env->raydir.y) / (env->raydir.x * env->raydir.x));
	env->deltadist.y = sqrt(1 +
	(env->raydir.x * env->raydir.x) / (env->raydir.y * env->raydir.y));
	env->sidedist.x = (env->raydir.x < 0)
		? ((env->raypos.x - env->map.x) * env->deltadist.x)
		: ((env->map.x + 1.0 - env->raypos.x) * env->deltadist.x);
	env->step.x = (env->raydir.x < 0) ? (-1) : 1;
	env->sidedist.y = (env->raydir.y < 0)
		? ((env->raypos.y - env->map.y) * env->deltadist.y)
		: ((env->map.y + 1.0 - env->raypos.y) * env->deltadist.y);
	env->step.y = (env->raydir.y < 0) ? (-1) : 1;
}

void	boucle_wall(t_wolf *env)
{
	env->hit = 0;
	while (env->hit == 0)
	{
		if (env->sidedist.x < env->sidedist.y)
		{
			env->sidedist.x += env->deltadist.x;
			env->map.x += env->step.x;
			env->side = 0;
		}
		else
		{
			env->sidedist.y += env->deltadist.y;
			env->map.y += env->step.y;
			env->side = 1;
		}
		if (env->map.x < 0 || env->map.x >= env->len_tab.x)
			env->map.x = (env->map.x < 0) ? 0 : (env->len_tab.x - 1);
		if (env->map.y < 0 || env->map.y >= env->len_tab.y)
			env->map.y = (env->map.y < 0) ? 0 : (env->len_tab.y - 1);
		env->hit = (env->tab[env->map.x][env->map.y] > 0) ? 1 : 0;
	}
}

void	def_wall(t_wolf *env)
{
	if (env->side == 0)
		env->walldist = (((double)env->map.x - env->raypos.x + 0.001
				+ ((1.0 - env->step.x) / 2.0)) / env->raydir.x);
	else
		env->walldist = (((double)env->map.y - env->raypos.y + 0.001
				+ ((1.0 - env->step.y) / 2.0)) / env->raydir.y);
}

void	boucle(t_wolf *env)
{
	int	x;

	x = -1;
	while (++x < W)
	{
		ft_init_rayon(env, x);
		boucle_wall(env);
		def_wall(env);
		draw(env, x);
	}
	mlx_put_image_to_window(env->fen.mlx_ptr, env->fen.win_ptr,
			env->fen.img_ptr, 0, 0);
}
