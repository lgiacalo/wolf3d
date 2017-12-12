/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:57:56 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/12 14:03:57 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_texture(t_wolf *env)
{
	print_wolf(env);
//	printf("Valeur env->text.x = [%d]\n", env->text.x);
	if (env->side == 0)
		env->text.wallx = env->pos.y + env->walldist * env->dir.y;
	else
		env->text.wallx = env->pos.x + env->walldist * env->dir.x;
	env->text.wallx -= floor(env->text.wallx);

	env->text.tex.x = (int)(env->text.wallx * (double)env->img.width);
	if ((env->side == 0 && env->dir.x > 0) || (env->side == 1 && env->dir.y < 0))
		env->text.tex.x = env->img.width - env->text.tex.x - 1;

}

void	color_texture(t_wolf *env, int x, int y)
{
	int	ind_tab;
	int	ind_tex;

	ind_tab = x * 4 + y * env->fen.size_line;
//	printf("Valeur texX = [%lf] / texY = [%lf]\n", env->text.tex.x, env->text.tex.y);
	if (env->side == 1)
		ind_tex = (int)env->text.tex.y * 4 + (int)env->text.tex.x * env->img.size_line;
	else
		ind_tex = (int)env->text.tex.x * 4 + (int)env->text.tex.y * env->img.size_line;
//	printf("Valeur ind_tex : [%d]\n", ind_tex);
	env->fen.img_str[ind_tab] = env->img.img_str[ind_tex];
	env->fen.img_str[ind_tab + 1] = env->img.img_str[ind_tex + 1];
	env->fen.img_str[ind_tab + 2] = env->img.img_str[ind_tex + 2];
}

void	color(t_wolf *env, int x, int y, int color)
{
	int ind;

	ind = x * 4 + y * env->fen.size_line;
	env->fen.img_str[ind] = color;
	env->fen.img_str[ind + 1] = color;
	env->fen.img_str[ind + 2] = color;
}

void	draw_ground(t_wolf *env, int x)
{
	int	y;

	y = -1;
	while (++y < env->draw.x && y < H)
		color(env, x, y, (int)(0x554477));	
}

void	draw_wall(t_wolf *env, int x)
{
	int y;

	y = env->draw.x - 1;
	ft_init_texture(env);
	printf("\n\n===== COLONNE X = [%d] =============\n", x);
	while (++y < env->draw.y && y < H)
	{
//		printf("Y = [%d] --- hautligne = [%lf] - wallDist = [%lf]\n", y, env->hautligne, env->walldist);
		if (env->hautligne > H)
			env->hautligne = H;
		env->text.tex.y = (y * 2.0 - (H - 1.0) + env->hautligne) * (env->img.height / 2.0) / env->hautligne;
		color_texture(env, x, y);	
//		color(env, x, y, (env->side == 1) ? (int)(0xCCCCCC) : (int)(0xf2f2f2));
	}
}

void	draw_sky(t_wolf *env, int x)
{
	int	y;

	y = env->draw.y - 1;
	while (++y < H && y >= 0)
		color(env, x, y, (int)(0x000044));	
}

void	draw(t_wolf *env, int x)
{
	if (env->walldist == 0)
		env->hautligne = H; /// inutile
	else
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
