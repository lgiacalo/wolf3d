/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:57:56 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/13 09:31:12 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_texture(t_wolf *env)
{
	int	ind;

	ind = env->side;
	if (env->side == 0)
		env->text[ind].wallx = env->raypos.y + env->walldist * env->raydir.y;
	else
		env->text[ind].wallx = env->raypos.x + env->walldist * env->raydir.x;
	env->text[ind].wallx -= floor(env->text[ind].wallx);
	env->text[ind].tex.x = (int)(env->text[ind].wallx
			* (double)env->img[ind].width);
	if ((ind == 0 && env->dir.x > 0) || (ind == 1 && env->dir.y < 0))
		env->text[ind].tex.x = env->img[ind].width - env->text[ind].tex.x - 1;
}

void	color_texture(t_wolf *env, int x, int y)
{
	int	ind_tab;
	int	ind_tex;
	int	ind;

	ind_tab = x * 4 + y * env->fen.size_line;
	ind_tex = (int)env->text[env->side].tex.x * 4
		+ (int)env->text[env->side].tex.y * env->img[env->side].size_line;
	ind = env->side;
	if (ind == 1 && env->step.y < 0)
		ind = 2;
	if (ind == 0 && env->step.x > 0)
		ind = 3;
	env->fen.img_str[ind_tab] = env->img[ind].img_str[ind_tex];
	env->fen.img_str[ind_tab + 1] = env->img[ind].img_str[ind_tex + 1];
	env->fen.img_str[ind_tab + 2] = env->img[ind].img_str[ind_tex + 2];
}

void	color(t_wolf *env, int x, int y, int color)
{
	int ind;

	ind = x * 4 + y * env->fen.size_line;
	env->fen.img_str[ind] = color;
	env->fen.img_str[ind + 1] = color;
	env->fen.img_str[ind + 2] = color;
}

void	draw_wall(t_wolf *env, int x)
{
	int y;

	y = env->draw.x - 1;
	ft_init_texture(env);
	while (++y < env->draw.y && y < H)
	{
		env->text[env->side].tex.y = (y * 2.0 - (H - 1.0) + env->hautligne)
			* (env->img[env->side].height / 2.0) / env->hautligne;
		color_texture(env, x, y);	
	}
}

void	draw_sky(t_wolf *env, int x)
{
	int	y;

	y = env->draw.y - 1;
	while (++y < H && y >= 0)
		color(env, x, y, (int)(0x000044));	
}

void	draw_ground(t_wolf *env, int x)
{
	int	y;

	y = -1;
	while (++y < env->draw.x && y < H)
		color(env, x, y, (int)(0x554477));	
}



void	draw(t_wolf *env, int x)
{
	env->hautligne = abs((int)((double)H / env->walldist)); //TODO: abs a changer
	env->draw.x = (int)((H / 2.0) - (env->hautligne / 2.0)); //start
	env->draw.y = (int)((H / 2.0) + (env->hautligne / 2.0)); //end
	(env->draw.x < 0) ? env->draw.x = 0 : 0;
	(env->draw.y >= H) ? env->draw.y = (H - 1) : 0;
	draw_wall(env, x);
	if (env->draw.y < 0)//
		env->draw.y = H;//
	draw_ground(env, x);
	draw_sky(env, x);
}
