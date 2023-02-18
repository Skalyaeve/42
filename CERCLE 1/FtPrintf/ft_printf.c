/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:20:27 by anguinau          #+#    #+#             */
/*   Updated: 2021/02/17 16:24:21 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	avoid_convert(const char *str, int *i, ssize_t *ret, t_tab *molp)
{
	ssize_t	dot_n_star[2];

	while (*i > 0 && str[*i] != '%')
		--*i;
	while (str[*i] && str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\n'
			&& str[*i] != '\r' && str[*i] != '\v' && str[*i] != '\f')
	{
		if (str[*i] == '.')
			dot_n_star[0] = 1;
		if (str[*i] == '*' && !dot_n_star[1])
		{
			dot_n_star[1] = 1;
			if (!dot_n_star[0])
			{
				ft_putnbr_fd(molp->l, ret, -1, -1);
			}
			else
				ft_putnbr_fd(molp->p, ret, -1, -1);
		}
		else
			str[*i] == '0' && molp->m ?
				write(1, "", 0) : write(1, &str[*i], 1);
		*ret += (str[*i] == '0' && molp->m ? 0 : 1);
		++*i;
	}
}

ssize_t	get_final_lenght(t_tab *molp, t_type_list *value)
{
	long long	nbr;
	ssize_t		count;

	if (value->c || value->a)
		return (molp->l - 1);
	if (value->s)
	{
		if (molp->p - 1 > -1)
		{
			return (ft_strlen(value->s) > molp->p - 1 ?
					molp->l - molp->p + 1 : molp->l - ft_strlen(value->s));
		}
		return (molp->l - ft_strlen(value->s));
	}
	if ((value->i && (nbr = value->i) == value->i) ||
			(value->u && (nbr = value->u) == value->u))
	{
		if (molp->p - 1 == 0 && nbr == 0)
			return (molp->l);
		if (nbr < 0)
			molp->l--;
		count = count_nbr(nbr);
		return (molp->p - 1 > count ? molp->l - molp->p + 1 : molp->l - count);
	}
	return (hex_convert(molp, value));
}

ssize_t	finish_it(t_tab *molp, t_type_list *value, ssize_t *ret)
{
	ssize_t	returned;

	if ((molp->l = get_final_lenght(molp, value)) == -2147483648)
		return (0);
	if (molp->o && molp->p - 1 > 0 && (value->i || value->w || value->u
				|| value->x || value->z))
		molp->o = 0;
	if (value->p && molp->o && (*ret += 2) > 0)
		write(1, "0x", 2);
	if (value->i < 0 && molp->o && ++*ret)
		write(1, "-", 1);
	if (!molp->m)
		while ((molp->l-- > 0) && ++*ret)
			molp->o && !value->c
				? write(1, "0", 1) : write(1, " ", 1);
	returned = last_output(molp, value, ret);
	if (value->q && molp->p - 1 && ++*ret)
		while ((molp->p-- > 2) && ++*ret)
			write(1, "0", 1);
	return (returned);
}

ssize_t	convert_it(const char *str, int *i, ssize_t *ret, va_list ap)
{
	t_tab		*molp;
	t_type_list	*value;

	if (!(molp = malloc(sizeof(t_tab))))
		return (0);
	if (!(value = malloc(sizeof(t_type_list))))
	{
		free(molp);
		return (0);
	}
	if (++*i && !fill_mo(molp, str, i, ap)
			&& !get_value(value, str, i, ap))
	{
		if (!(finish_it(molp, value, ret)))
			return (clean_up(molp, value));
	}
	else
	{
		avoid_convert(str, i, ret, molp);
		--*i;
	}
	clean_up(molp, value);
	return (1);
}

int		ft_printf(const char *str, ...)
{
	ssize_t	ret;
	va_list	ap;
	int		i;

	i = -1;
	if ((ret = 0) == 0 && !str)
		return (-1);
	if (!str[0])
		return (ret);
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			ret++;
		}
		else if (!(convert_it(str, &i, &ret, ap)))
			return (-1);
	}
	va_end(ap);
	return (ret);
}
