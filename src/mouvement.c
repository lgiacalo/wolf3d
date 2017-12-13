/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:58:32 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/13 11:45:18 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	avancer_reculer(t_wolf *env, int mov)
{
	t_dcoord	tmp;

	tmp.x = env->dir.x * env->dep.vitmarche * mov;
	tmp.y = env->dir.y * env->dep.vitmarche * mov;
	if (env->tab[(int)(env->pos.x + tmp.x)][(int)env->pos.y] == 0)
		env->pos.x += tmp.x;
	else
		return ;
	if (env->tab[(int)env->pos.x][(int)(env->pos.y + tmp.y)] == 0)
		env->pos.y += tmp.y;
	else
		env->pos.x -= tmp.x;
}

void	tourner(t_wolf *env, int mov)
{
	double	tmp;
	double	vit;

	vit = env->dep.vitrot * mov;
	tmp = env->dir.x;
	env->dir.x = tmp * cos(-vit) - env->dir.y * sin(-vit);
	env->dir.y = tmp * sin(-vit) + env->dir.y * cos(-vit);
	tmp = env->norm.x;
	env->norm.x = tmp * cos(-vit) - env->norm.y * sin(-vit);
	env->norm.y = tmp * sin(-vit) + env->norm.y * cos(-vit);
}

void	lateral(t_wolf *env, int mov)
{
	t_dcoord	tmp;

	tmp.x = env->norm.x * env->dep.vitmarche * mov;
	tmp.y = env->norm.y * env->dep.vitmarche * mov;
	if (env->tab[(int)(env->pos.x + tmp.x)][(int)env->pos.y] == 0)
		env->pos.x += tmp.x;
	else
		return ;
	if (env->tab[(int)(env->pos.x)][(int)(env->pos.y + tmp.y)] == 0)
		env->pos.y += tmp.y;
	else
		env->pos.x -= tmp.x;
}

void	mouvement(t_wolf *env)
{
	(void)env;
	if (env->dep.m_up)
		avancer_reculer(env, 1);
	if (env->dep.m_down)
		avancer_reculer(env, (-1));
	if (env->dep.t_right)
		tourner(env, 1);
	if (env->dep.t_left)
		tourner(env, (-1));
	if (env->dep.ml_right)
		lateral(env, 1);
	if (env->dep.ml_left)
		lateral(env, (-1));
}
