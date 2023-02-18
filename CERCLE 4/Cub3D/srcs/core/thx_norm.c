/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:55:26 by anguinau          #+#    #+#             */
/*   Updated: 2022/09/04 17:16:23 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int	iset(int *to_set, int value, int ret)
{
	*to_set = value;
	return (ret);
}

void	turn_left(void)
{
	float	old_dir_x;
	float	old_plane_x;

	if ((data())->turn_left && ++(data())->moved)
	{
		old_dir_x = (data())->dir_x;
		(data())->dir_x = (data())->dir_x * cos(ROTATE_SPEED) - (data())->dir_y
			* sin(ROTATE_SPEED);
		(data())->dir_y = old_dir_x * sin(ROTATE_SPEED) + (data())->dir_y
			* cos(ROTATE_SPEED);
		old_plane_x = (data())->plane_x;
		(data())->plane_x = (data())->plane_x * cos(ROTATE_SPEED)
			- (data())->plane_y * sin(ROTATE_SPEED);
		(data())->plane_y = old_plane_x * sin(ROTATE_SPEED) + (data())->plane_y
			* cos(ROTATE_SPEED);
	}
}

void	turn_right(void)
{
	float	old_dir_x;
	float	old_plane_x;

	if ((data())->turn_right && ++(data())->moved)
	{
		old_dir_x = (data())->dir_x;
		(data())->dir_x = (data())->dir_x * cos(-ROTATE_SPEED)
			- (data())->dir_y * sin(-ROTATE_SPEED);
		(data())->dir_y = old_dir_x * sin(-ROTATE_SPEED) + (data())->dir_y
			* cos(-ROTATE_SPEED);
		old_plane_x = (data())->plane_x;
		(data())->plane_x = (data())->plane_x * cos(-ROTATE_SPEED)
			- (data())->plane_y * sin(-ROTATE_SPEED);
		(data())->plane_y = old_plane_x * sin(-ROTATE_SPEED) + (data())->plane_y
			* cos(-ROTATE_SPEED);
	}
	turn_left();
}

int	fill_colors(int l, int ref, int colors[3])
{
	if (l != 2 && ft_putstr_fd("Error\nInvalid colors\n", 2))
		return (0);
	if ((colors[0] > 255 || colors[1] > 255 || colors[2] > 255)
		&& ft_putstr_fd("Error\nInvalid colors\n", 2))
		return (0);
	if (ref == 'f')
	{
		if ((data())->map.f_color != -1
			&& ft_putstr_fd("Error\nDouble key\n", 2))
			return (0);
		(data())->map.f_color = (colors[0] << 16 | colors[1] << 8 | colors[2]);
	}
	else
	{
		if ((data())->map.c_color != -1
			&& ft_putstr_fd("Error\nDouble key\n", 2))
			return (0);
		(data())->map.c_color = (colors[0] << 16 | colors[1] << 8 | colors[2]);
	}
	return (1);
}
