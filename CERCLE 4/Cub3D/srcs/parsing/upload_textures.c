/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:06:26 by anguinau          #+#    #+#             */
/*   Updated: 2022/09/08 19:26:35 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	upload_n_tex(char *path)
{
	(data())->map.n_tex = malloc(sizeof(t_img));
	if (!(data())->map.n_tex && ft_putstr_fd("Error\nMalloc failed\n", 2))
		return (0);
	(data())->map.n_tex->img
		= mlx_xpm_file_to_image((data())->mlx.ptr, path,
			&(data())->map.n_tex->width, &(data())->map.n_tex->height);
	if (!(data())->map.n_tex->img
		&& ft_putstr_fd("Error\nInvalid north texture\n", 2))
		return (0);
	(data())->map.n_tex->addr = mlx_get_data_addr((data())->map.n_tex->img,
			&(data())->map.n_tex->bits_per_pixel,
			&(data())->map.n_tex->line_length,
			&(data())->map.n_tex->endian);
	return (1);
}

int	upload_s_tex(char *path)
{
	(data())->map.s_tex = malloc(sizeof(t_img));
	if (!(data())->map.s_tex && ft_putstr_fd("Error\nMalloc failed\n", 2))
		return (0);
	(data())->map.s_tex->img
		= mlx_xpm_file_to_image((data())->mlx.ptr, path,
			&(data())->map.s_tex->width, &(data())->map.s_tex->height);
	if (!(data())->map.s_tex->img
		&& ft_putstr_fd("Error\nInvalid south texture\n", 2))
		return (0);
	(data())->map.s_tex->addr = mlx_get_data_addr((data())->map.s_tex->img,
			&(data())->map.s_tex->bits_per_pixel,
			&(data())->map.s_tex->line_length,
			&(data())->map.s_tex->endian);
	return (1);
}

int	upload_e_tex(char *path)
{
	(data())->map.e_tex = malloc(sizeof(t_img));
	if (!(data())->map.e_tex && ft_putstr_fd("Error\nMalloc failed\n", 2))
		return (0);
	(data())->map.e_tex->img
		= mlx_xpm_file_to_image((data())->mlx.ptr, path,
			&(data())->map.e_tex->width, &(data())->map.e_tex->height);
	if (!(data())->map.e_tex->img
		&& ft_putstr_fd("Error\nInvalid east texture\n", 2))
		return (0);
	(data())->map.e_tex->addr = mlx_get_data_addr((data())->map.e_tex->img,
			&(data())->map.e_tex->bits_per_pixel,
			&(data())->map.e_tex->line_length,
			&(data())->map.e_tex->endian);
	return (1);
}

int	upload_w_tex(char *path)
{
	(data())->map.w_tex = malloc(sizeof(t_img));
	if (!(data())->map.w_tex && ft_putstr_fd("Error\nMalloc failed\n", 2))
		return (0);
	(data())->map.w_tex->img
		= mlx_xpm_file_to_image((data())->mlx.ptr, path,
			&(data())->map.w_tex->width, &(data())->map.w_tex->height);
	if (!(data())->map.w_tex->img
		&& ft_putstr_fd("Error\nInvalid west texture\n", 2))
		return (0);
	(data())->map.w_tex->addr = mlx_get_data_addr((data())->map.w_tex->img,
			&(data())->map.w_tex->bits_per_pixel,
			&(data())->map.w_tex->line_length,
			&(data())->map.w_tex->endian);
	return (1);
}

int	upload_textures(char ref, char *path)
{
	if (ref == 'n')
	{
		if ((data())->map.n_tex && ft_putstr_fd("Error\nDouble key\n", 2))
			return (0);
		return (upload_n_tex(path));
	}
	if (ref == 's')
	{
		if ((data())->map.s_tex && ft_putstr_fd("Error\nDouble key\n", 2))
			return (0);
		return (upload_s_tex(path));
	}
	if (ref == 'e')
	{
		if ((data())->map.e_tex && ft_putstr_fd("Error\nDouble key\n", 2))
			return (0);
		return (upload_e_tex(path));
	}
	if (ref == 'w')
	{
		if ((data())->map.w_tex && ft_putstr_fd("Error\nDouble key\n", 2))
			return (0);
		return (upload_w_tex(path));
	}
	return (1);
}
