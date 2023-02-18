/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:50:34 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/04 20:03:19 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef HEADER_H
# define HEADER_H

# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

typedef struct s_map
{
	char	*map_struct;
	int		map_size;
	int		map_len;
	int		**map_tab;
}		t_map;

typedef struct s_parsing
{
	char				c;
	struct s_parsing	*next;
}		t_parsing;

typedef struct s_sprite
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
	int		width;
	int		height;
	int		ica;
}		t_sprite;

typedef struct s_col
{
	int	x;
	int	y;
	int	alive;
}		t_col;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	double		x_draw_offset;
	double		y_draw_offset;
	int			x_case_len;
	int			y_case_len;
	int			redraw;
	int			pts;
	int			escape_x;
	int			escape_y;
	int			end;
	int			moves;
	int			started;
	int			frame;
	int			width;
	int			height;
	int			col_nbr;
	int			x;
	int			old_x;
	int			y;
	int			old_y;
	int			dir;
	int			phase;
	t_sprite	*wall_sprite;
	t_sprite	*floor_sprite;
	t_sprite	**col_sprite;
	t_sprite	*exit_sprite;
	t_sprite	**char_static_sprite;
	t_col		**col;
	t_map		*map_infos;
}		t_mlx;

int		system_error(char *step, t_mlx *mlx);
int		parsing(int fd, t_map *map_infos);
int		map_error(char *str, t_map *map_infos);
int		free_map_infos(t_map *map_infos);
int		check_map_infos(t_map *map_infos, int p, int e, int c);
int		create_map_tab(int i, int size, char *str, t_map *map_infos);
int		free_map_tab(int size, int **map);
int		init_mlx(t_mlx *mlx, t_map *map_infos);
int		upload_sprites(t_mlx *mlx);
int		keyrelease_hook(int keycode, t_mlx *mlx);
int		loop_hook(t_mlx *mlx);
int		free_sprites(t_mlx *mlx, t_sprite *sprite);
void	draw(int i, int j, t_mlx *mlx);
void	free_mlx(t_mlx *mlx);
void	putstr_fd(char *s, int fd);
void	put_images(int i, int j, t_mlx *mlx, t_sprite *sprite);
int		assign_sprites(t_sprite **sprite, char *path, t_mlx *mlx);
int		free_col(t_col **col, int size);
int		reversed_char(t_sprite *src, t_sprite **dest, double i, t_mlx *mlx);
int		start(t_mlx *mlx, int i, int j);

#	endif
