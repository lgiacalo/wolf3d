/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 21:25:44 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/13 22:26:28 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	color(t_wolf *env, int x, int y, int opt)
{
	int ind;

	ind = x * 4 + y * env->fen.size_line;
	env->fen.img_str[ind] = (!opt) ? 120 : 77;
	env->fen.img_str[ind + 1] = (!opt) ? 97 : 86;
	env->fen.img_str[ind + 2] = (!opt) ? 33 : 86;
}

void	draw_floor(t_wolf *env, int x)
{
	int	y;
	y = -1;
	while (++y < env->draw.x && y < H)
		color(env, x, y, 0);
	y = env->draw.y - 1;
	while (++y < H && y >= 0)
		color(env, x, y, (int)(0x000044));
}
