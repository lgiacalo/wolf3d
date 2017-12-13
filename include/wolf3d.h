/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:40:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/12/13 16:40:18 by lgiacalo         ###   ########.fr       */
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

# define W				800
# define H				600

# define KEY_PRESS			2
# define KEY_PRESS_MASK		(1L << 0)
# define KEY_RELEASE_MASK	(1L << 1)
# define DESTROY_NOTIFY		17

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
}						t_text;

typedef struct			s_wolf
{
	t_mlx				fen;
	int					**tab;
	t_coord				len_tab;
	t_dcoord			pos;
	t_dcoord			dir;
	t_dcoord			norm;
	double				cam;
	t_dcoord			raypos;
	t_dcoord			raydir;
	t_coord				map;
	t_dcoord			deltadist;
	t_dcoord			sidedist;
	t_coord				step;
	int					hit;
	int					side;
	double				walldist;
	double				hautligne;
	t_coord				draw;
	t_dep				dep;
	t_image				img[4];
	t_text				text[2];
}						t_wolf;

/*
** ****************************************************************************
*/

t_wolf					*ft_wolf(void);
void					ft_init_wolf(t_wolf *env);

int						**ft_file(int argc, char **argv);
int						**ft_check_file(char **mapc);
void					ft_verif_map(t_wolf *env, int **map);

int						my_press_funct(int keycode, t_wolf *env);
int						my_release_funct(int keycode, t_wolf *env);
int						my_loop_funct(t_wolf *env);

void					mouvement(t_wolf *env);

void					boucle(t_wolf *env);
void					draw(t_wolf *env, int x);

void					ft_end(t_wolf **env);
void					ft_error(char *str, int us);
int						ft_abs(int n);
void					ft_arrayintdel(int ***tab);
t_list					*ft_lstnew_light(void *content, size_t content_size);
void					ft_lstfree(t_list **alst);

#endif
