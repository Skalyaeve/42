/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:28:05 by anguinau          #+#    #+#             */
/*   Updated: 2022/09/13 17:28:45 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../ressources/libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# define ROTATE_SPEED	0.15
# define FWD_SPEED		0.15
# define BWD_SPEED		0.1
# define SIDE_SPEED		0.1
# define SYNTAX			"Error\nWrong map syntax\n"

typedef struct s_parsing
{
	char				c;
	struct s_parsing	*next;
}						t_parsing;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_map
{
	char	*map_infos;
	int		**map;
	int		map_size;
	int		c_color;
	int		f_color;
	t_img	*n_tex;
	t_img	*s_tex;
	t_img	*e_tex;
	t_img	*w_tex;
}			t_map;				

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}			t_mlx;

typedef struct s_data
{
	int		ret;
	t_mlx	mlx;
	t_map	map;
	int		screen_width;
	int		screen_height;
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	int		moved;
	int		move_up;
	int		move_down;
	int		move_right;
	int		move_left;
	int		turn_right;
	int		turn_left;
	int		screen_x;
	float	ratio;
	float	ray_dir_x;
	float	ray_dir_y;
	float	dist_x;
	float	dist_y;
	float	total_dist_x;
	float	total_dist_y;
	float	wall_dist;
	int		step_x;
	int		step_y;
	int		ray_x;
	int		ray_y;
	short	hit;
	int		line_size;
	int		draw_start;
	int		draw_end;
	int		side;
	float	tex_x_offset;
	int		tex_y_offset;
	int		dont_draw;
	t_img	*actual_tex;
	t_img	display;
}			t_data;

t_data	*data(void);
int		exit_proprely(int ret);
int		parse_file(char *path, int i, int fd, t_parsing *index);
int		upload_textures(char ref, char *path);
int		fill_colors(int l, int ref, int colors[3]);
int		fill_map_struct(char *str, int i);
int		check_map_infos(void);
int		check_map_walls(int i, int j);
int		create_2d_map(int i, int j, int k, int l);
int		keyrelease_hook(int keycode);
int		keypress_hook(int keycode);
int		loop_hook(void);
int		draw_line(int x, int y, int color);
void	move_up(void);
void	turn_right(void);
int		iset(int *to_set, int value, int ret);
void	init_values(void);

#	endif
