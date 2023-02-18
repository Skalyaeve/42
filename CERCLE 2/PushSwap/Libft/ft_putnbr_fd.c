/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 02:14:01 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 15:20:59 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Ecrit un int dans fd

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
		if (n == -2147483648)
		{
			c = '2';
			write(fd, &c, 1);
			n = -147483648;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = 48 + (n % 10);
	write(fd, &c, 1);
	return (1);
}
