/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:03:49 by anguinau          #+#    #+#             */
/*   Updated: 2021/10/28 23:27:12 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	assign_it(t_sprite **sprite, t_sprite *img, t_mlx *mlx)
{	
	mlx_destroy_image(mlx->ptr, (*sprite)->ptr);
	(*sprite)->ptr = img->ptr;
	(*sprite)->addr = img->addr;
	(*sprite)->bpp = img->bpp;
	(*sprite)->line_size = img->line_size;
	(*sprite)->endian = img->endian;
	(*sprite)->width = img->width;
	(*sprite)->height = img->height;
	return (1);
}

int	resize_sprites(t_mlx *mlx, t_sprite *sprite, double i, double j)
{
	t_sprite	img;
	char		*color;
	int			x;
	int			y;

	x = -1;
	img.ptr = mlx_new_image(mlx->ptr, mlx->x_case_len,
			mlx->y_case_len);
	img.addr = mlx_get_data_addr
		(img.ptr, &img.bpp, &img.line_size, &img.endian);
	while (++x < mlx->x_case_len)
	{
		y = -1;
		j = 0;
		while (++y < mlx->y_case_len)
		{
			color = img.addr + (y * img.line_size + x * (img.bpp / 8));
			*(unsigned int *)color = *(unsigned int *)
				(sprite->addr + ((int)j * img.line_size
						+ (int)i * (img.bpp / 8)));
			j += mlx->y_draw_offset;
		}
		i += mlx->x_draw_offset;
	}
	return (assign_it(&sprite, &img, mlx));
}

int	assign_sprites(t_sprite **sprite, char *path, t_mlx *mlx)
{
	*sprite = malloc(sizeof(t_sprite));
	if (!*sprite)
		return (0);
	(*sprite)->ptr = mlx_xpm_file_to_image
		(mlx->ptr, path, &(*sprite)->width, &(*sprite)->height);
	if (!(*sprite)->ptr)
		return (0);
	(*sprite)->addr = mlx_get_data_addr((*sprite)->ptr, &(*sprite)->bpp,
			&(*sprite)->line_size, &(*sprite)->endian);
	if (!(*sprite)->addr)
		return (0);
	if (!resize_sprites(mlx, *sprite, 0, 0) && !free_sprites(mlx, *sprite))
		return (0);
	return (1);
}
