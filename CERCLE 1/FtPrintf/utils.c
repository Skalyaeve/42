/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 06:24:13 by anguinau          #+#    #+#             */
/*   Updated: 2021/02/17 15:40:25 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

ssize_t	ft_strlen(const char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr_fd(long long n, ssize_t *ret, int p, int o)
{
	char	c;
	ssize_t	count;

	count = count_nbr(n);
	if (n < 0 && !o && ++*ret)
		write(1, "-", 1);
	if (p > count)
		while (p-- > count && ++*ret)
			write(1, "0", 1);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "2", 1);
			*ret += 1;
			n = -147483648;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, ret, -1, -1);
	c = 48 + (n % 10);
	write(1, &c, 1);
	*ret += 1;
}

ssize_t	fill_l(t_tab *molp, const char *str, int *i, va_list ap)
{
	if (str[*i] >= '0' && str[*i] <= '9')
	{
		while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
		{
			molp->l = molp->l * 10 + ((int)str[*i] - 48);
			*i += 1;
		}
	}
	if (str[*i] == '*')
	{
		if (molp->l != 0 && (molp->l = va_arg(ap, int)))
			return (0);
		molp->l = va_arg(ap, int);
		if (molp->l < 0)
		{
			molp->l *= -1;
			molp->m = 1;
		}
		*i += 1;
	}
	return (fill_p(molp, str, i, ap));
}

ssize_t	fill_mo(t_tab *molp, const char *str, int *i, va_list ap)
{
	molp->m = 0;
	molp->o = 0;
	molp->l = 0;
	molp->p = 0;
	while (str[*i] && (str[*i] == '0' || str[*i] == '-'))
	{
		if (str[*i] == '-')
			molp->m = 1;
		if (str[*i] == '0')
			molp->o = 1;
		*i += 1;
	}
	if (molp->m == 1 && molp->o == 1)
		molp->o = 0;
	return (!fill_l(molp, str, i, ap) ? 1 : 0);
}

ssize_t	hex_convert(t_tab *molp, t_type_list *value)
{
	unsigned long long	nbr;
	char				*hex_base;
	ssize_t				i;

	hex_base = value->z ? "0123456789ABCDEF" : "0123456789abcdef";
	if (value->x)
		nbr = value->x;
	if (value->w)
		return (!molp->p - 1 ? molp->l - molp->p + 1 : molp->l - 1);
	if (value->q)
		return (molp->p - 1 ? molp->l - 3 : molp->l - 2);
	if ((i = 1) == 1 && value->z)
		nbr = value->z;
	if (molp->p - 1 == 0 && nbr == 0)
		return (molp->l);
	if (!(value->hex = malloc(sizeof(t_hex_list))))
		return (-2147483648);
	if ((value->hex->prev = NULL) == NULL && value->p)
		nbr = value->p;
	if (!(fill_hex_struct(nbr, value, hex_base, &i)))
		return (-2147483648);
	if (molp->p - 1 > 0 && !value->p)
		return (molp->p - 1 > i ? molp->l - molp->p + 1 : molp->l - i);
	return (value->p ? molp->l - 2 - i : molp->l - i);
}
