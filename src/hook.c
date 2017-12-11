/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 09:38:32 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/11 13:30:11 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

//TODO: donner la possibilite de choisir ces touches de mouvement

int	my_press_funct(int keycode, t_wolf *env)
{
	if (keycode == KEY_W)
		env->dep.m_up = 1;
	if (keycode == KEY_S)
		env->dep.m_down = 1;
	if (keycode == KEY_D)
		env->dep.t_right = 1;
	if (keycode == KEY_A)
		env->dep.t_left = 1;
	if (keycode == KEY_E)
		env->dep.ml_right = 1;
	if (keycode == KEY_Q)
		env->dep.ml_left = 1;
	return (0);
}

int	my_release_funct(int keycode, t_wolf *env)
{
	if (keycode == KEY_ESC)
		exit(0); // free + destruction image : faire fonction
	if (keycode == KEY_W)
		env->dep.m_up = 0;
	if (keycode == KEY_S)
		env->dep.m_down = 0;
	if (keycode == KEY_D)
		env->dep.t_right = 0;
	if (keycode == KEY_A)
		env->dep.t_left = 0;
	if (keycode == KEY_E)
		env->dep.ml_right = 0;
	if (keycode == KEY_Q)
		env->dep.ml_left = 0;
	return (0);
}

int	my_mouse_funct(int button, int x, int y, t_wolf *env)
{
	(void)button;
	(void)x;
	(void)y;
	(void)env;
	ft_fdprintf(1, "Fonction my mouse funct !!\n");
	return (0);
}

int	my_loop_funct(t_wolf *env)
{
	clock_t	tmp;
	t_dep	dep;

	tmp = clock();
	dep = env->dep;
	if (env->dep.time > tmp)
		return (0);
	env->dep.time = tmp + 10000; // a reduire, pour augmenter le rafraichis.. !!
	if (dep.m_up || dep.m_down || dep.t_right || dep.t_left || dep.ml_right || dep.ml_left)
	{
		mouvement(env);
		boucle(env);
	}
	return (0);
}
