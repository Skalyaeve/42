/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 02:04:54 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 15:19:47 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Ecrit un char* dans fd

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	while (s && *s++)
		write(fd, (s - 1), 1);
	return (1);
}
