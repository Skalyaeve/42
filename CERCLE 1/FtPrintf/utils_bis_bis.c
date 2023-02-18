/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:28:38 by anguinau          #+#    #+#             */
/*   Updated: 2021/02/17 16:24:04 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

ssize_t	clean_up(t_tab *molp, t_type_list *value)
{
	molp->m = 0x0;
	molp->o = 0x0;
	molp->l = 0x0;
	molp->p = 0x0;
	free(molp);
	value->c = 0;
	value->a = 0;
	value->s = NULL;
	value->i = 0x0;
	value->w = 0x0;
	value->u = 0x0;
	value->x = 0x0;
	value->z = 0x0;
	value->p = 0x0;
	value->q = 0x0;
	value->hex = NULL;
	free(value);
	return (0);
}

void	clean_hex(t_type_list *value, t_hex_list *old)
{
	while (value->hex->prev)
	{
		old = value->hex;
		value->hex = value->hex->prev;
		free(old);
	}
	value->hex->c = 0;
	value->hex->next = NULL;
	free(value->hex);
}

ssize_t	fill_p(t_tab *molp, const char *str, int *i, va_list ap)
{
	if (str[*i] == '.')
	{
		while (str[++*i] && (str[*i] >= '0' && str[*i] <= '9'))
			molp->p = molp->p * 10 + ((int)str[*i] - 48);
		if (str[*i] == '*')
		{
			if (molp->p != 0 && (molp->p = va_arg(ap, int)))
				return (0);
			molp->p = va_arg(ap, int);
			if (molp->p < 0)
				molp->p = -1;
			*i += 1;
		}
		molp->p += 1;
	}
	return (1);
}

ssize_t	last_output(t_tab *molp, t_type_list *value, ssize_t *ret)
{
	if (value->a == 'x' && ++*ret)
		write(1, "\0", 1);
	if ((value->c || (value->a && value->a == '%')) && ++*ret)
		value->c ? write(1, &value->c, 1) : write(1, &value->a, 1);
	if (value->s)
		ft_putstr_fd(value->s, 1, ret, molp);
	if (value->i)
		ft_putnbr_fd(value->i, ret, molp->p - 1, molp->o);
	if (value->w)
		if (molp->p - 1)
			ft_putnbr_fd(value->w - 1, ret, molp->p - 1, molp->o);
	if (value->u)
		if (molp->p - 1 || value->u)
			ft_putnbr_fd(value->u, ret, molp->p - 1, molp->o);
	if (value->p && !molp->o && (*ret += 2) > 0)
		write(1, "0x", 2);
	if (value->q && (*ret += 2) > 0)
		molp->p - 1 ? write(1, "0x0", 3) : write(1, "0x", 2);
	if (value->hex)
		print_hex(value, ret, molp);
	if (molp->m)
		while (molp->l-- > 0 && ++*ret)
			write(1, " ", 1);
	return (1);
}

void	init_values(t_type_list *value)
{
	value->c = 0;
	value->a = 0;
	value->s = NULL;
	value->i = 0;
	value->w = 0;
	value->u = 0;
	value->x = 0;
	value->z = 0;
	value->p = 0;
	value->q = 0;
	value->hex = NULL;
}
