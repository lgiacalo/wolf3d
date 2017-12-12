/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 23:01:09 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/12 23:12:08 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_mlx(t_wolf *env)
{
	if (!(env->fen.mlx_ptr = mlx_init(0)))
		ft_error("Probleme initialisation mlx", 0);
	if (!(env->fen.win_ptr = mlx_new_window(env->fen.mlx_ptr, W, H, "Wolf3D")))
		ft_error("Probleme creation fenetre mlx", 0);
	if (!(env->fen.img_ptr = mlx_new_image(env->fen.mlx_ptr, W, H)))
		ft_error("Probleme creation image mlx", 0);
	if (!(env->fen.img_str = mlx_get_data_addr(env->fen.img_ptr,
		&(env->fen.bits_per_pixel), &(env->fen.size_line), &(env->fen.endian))))
		ft_error("Probleme recuperation chaine image mlx", 0);
	printf("============ IMAGE : MAP ===========\n");
	printf("Bits per pixel : [%d]\n", env->fen.bits_per_pixel);
	printf("Size line : [%d]\n", env->fen.size_line);
	printf("Endian : [%d]\n\n", env->fen.endian);
}

void	ft_init_var(t_wolf *env)
{
	env->pos.x = 10; // hauteur
	env->pos.y = 10; // largeur
	env->dir.x = -1;
	env->dir.y = 0;
	env->norm.x = 0;
	env->norm.y = 1;
	env->dep.vitmarche = 0.10;
	env->dep.vitrot = 0.05;
	env->dep.time = 0;
}

void	ft_init_image(t_wolf *env, int ind, char *fic)
{
	if (!(env->img[ind].image = mlx_xpm_file_to_image(env->fen.mlx_ptr, fic, &(env->img[ind].width), &(env->img[ind].height))))
		ft_error("Probleme de chargement d'image !", 0);
	if (!(env->img[ind].img_str = mlx_get_data_addr(env->img[ind].image, &(env->img[ind].bits_per_pixel), &(env->img[ind].size_line), &(env->img[ind].endian))))
		ft_error("Probleme image", 0);
	printf("============= TEXTURE N*%d =============\n", ind);
	printf("Taille image : width = [%d] / height = [%d]\n", env->img[ind].width, env->img[ind].height);
	printf("Bits per pixel : [%d]\n", env->img[ind].bits_per_pixel);
	printf("Size line : [%d]\n", env->img[ind].size_line);
	printf("Endian : [%d]\n\n", env->img[ind].endian);
}

void	ft_init_wolf(t_wolf *env)
{
	ft_init_mlx(env);
	ft_init_var(env);
	if (env->pos.x >= env->len_tab.x || env->pos.y >= env->len_tab.y
		|| env->pos.x < 1 || env->pos.y < 1)
	{
		printf("Tu m'envoie de la merde !!!\n");
		printf("Je ne peux pas etre positionne en dehors de la map !!!\n");
		exit(0);
	}
	if (env->tab[(int)env->pos.x][(int)env->pos.y] != 0)
	{
		printf("Tu m'as foutu sur un mur !! debile \n");
		exit(0);
	}
	ft_init_image(env, 0, "img/mur.xpm");
	ft_init_image(env, 1, "img/wood.xpm");
}

t_wolf	*ft_wolf(void)
{
	static t_wolf	env;

	return (&env);
}

