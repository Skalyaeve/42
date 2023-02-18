/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversed_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:19:33 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/27 01:19:33 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	reversed_char_bis(t_sprite *src, t_sprite **dest, double i, t_mlx *mlx)
{
	char		*color;
	int			x;
	int			y;

	y = -1;
	while (++y < mlx->y_case_len)
	{
		x = -1;
		i = mlx->x_case_len - 1;
		while (++x < mlx->x_case_len)
		{
			color = (*dest)->addr + (y * (*dest)->line_size + x
					* ((*dest)->bpp / 8));
			*(unsigned int *)color = *(unsigned int *)
				(src->addr + (((int)y * (*dest)->line_size)
						+ ((int)i * ((*dest)->bpp / 8))));
			i--;
		}
	}
	return (1);
}

int	reversed_char(t_sprite *src, t_sprite **dest, double i, t_mlx *mlx)
{
	*dest = malloc(sizeof(t_sprite));
	if (!*dest)
		return (0);
	(*dest)->ptr = mlx_new_image(mlx->ptr, mlx->x_case_len,
			mlx->y_case_len);
	(*dest)->addr = mlx_get_data_addr
		((*dest)->ptr, &(*dest)->bpp, &(*dest)->line_size, &(*dest)->endian);
	return (reversed_char_bis(src, dest, i, mlx));
}
