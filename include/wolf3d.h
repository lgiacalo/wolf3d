/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:40:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/12 21:13:45 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "clavier.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <pthread.h> ///
# include <stdio.h> //TODO: a retirer

# define W				800
# define H				600

# define KEY_PRESS		2
# define KEY_PRESS_MASK	(1L << 0)

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_dcoord
{
	double				x;
	double				y;
}						t_dcoord;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	char				*img_str;
}						t_mlx;

typedef struct			s_dep
{
	int					m_up;
	int					m_down;
	int					t_right;
	int					t_left;
	int					ml_right;
	int					ml_left;
	double				vitmarche;
	double				vitrot;
	clock_t				time;
}						t_dep;

typedef struct			s_image
{
	void				*image;
	int					width;
	int					height;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	char				*img_str;
}						t_image;

typedef struct			s_text
{
	double				wallx;
	t_dcoord			tex;
	int					x;
}						t_text;

typedef struct			s_wolf
{
	t_mlx				fen;
	int					**tab;
	t_coord				len_tab;	// Taille map fichier externe
	t_dcoord			pos;		// Position de la camera
	t_dcoord			dir;		// Vecteur de direction de la camera
	t_dcoord			norm;		// Vecteur du plan de projection (perpendiculaire)
	double				cam;		// Position de la colonne par rapport au centre (compris entre -1 et 1)
	t_dcoord			raypos;		// Position de depart du rayon
	t_dcoord			raydir;		// Direction de rayon sur chaque axe
	t_coord				map;		// Cases de la cam
	t_dcoord			deltadist;	// Longeur du rayon entre chaques intersection
	t_dcoord			sidedist;	// Longeur de rayon
	t_coord				step;		// Pas du rayon ou -1 ou +1 (en fonction de la pente de la droite)
	int					hit;		// mur = 1, vide = 0
	int					side;		// orientation du mur
	double				walldist;	// Distance corrigee du rayon
	double				hautligne;
	t_coord				draw;
	t_dep				dep;
	t_image				img;
	t_text				text;
}						t_wolf;

/*
** ****************************************************************************
*/

t_wolf					*ft_wolf(void);
void					ft_init_wolf(t_wolf *env);

int						**ft_file(int argc, char **argv);
int						**ft_check_file(char **mapc);

int						my_press_funct(int keycode, t_wolf *env);
int						my_release_funct(int keycode, t_wolf *env);
int						my_mouse_funct(int button, int x, int y, t_wolf *env);
int						my_loop_funct(t_wolf *env);

void					mouvement(t_wolf *env);

void					boucle(t_wolf *env);
void					draw(t_wolf *env, int x);

void					ft_usage(void);
void					ft_error(char *str, int us);
void					ft_arrayintdel(int ***tab);
t_list					*ft_lstnew_light(void *content, size_t content_size);

void					print_wolf(t_wolf *env);

#endif
