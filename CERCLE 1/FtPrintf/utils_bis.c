/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 04:58:25 by anguinau          #+#    #+#             */
/*   Updated: 2021/02/17 15:50:24 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr_fd(const char *s, ssize_t fd, ssize_t *ret, t_tab *molp)
{
	ssize_t	count;
	ssize_t	i;

	i = -1;
	if (molp->p - 1 > -1)
	{
		count = molp->p - 1;
	}
	else
		count = ft_strlen(s);
	while (s && s[++i] && count)
	{
		write(fd, &s[i], 1);
		*ret += 1;
		count--;
	}
}

ssize_t	count_nbr(ssize_t nbr)
{
	ssize_t	count;

	count = 1;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= 10)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	print_hex(t_type_list *value, ssize_t *ret, t_tab *molp)
{
	t_hex_list	*old;
	t_hex_list	*count;
	ssize_t		i;

	i = 1;
	count = value->hex;
	while (count->prev && i++)
		count = count->prev;
	while (--molp->p > i && ++*ret)
		write(1, "0", 1);
	while (value->hex->prev)
	{
		write(1, &value->hex->c, 1);
		old = value->hex;
		value->hex = value->hex->prev;
		old->c = 0;
		old->next = NULL;
		free(old);
		*ret += 1;
	}
	write(1, &value->hex->c, 1);
	value->hex->c = 0;
	value->hex->next = NULL;
	free(value->hex);
	*ret += 1;
}

ssize_t	get_value(t_type_list *value, const char *str, int *i, va_list ap)
{
	init_values(value);
	if (str[*i] == 'c')
	{
		value->c = va_arg(ap, ssize_t);
		if (!value->c)
			value->a = 'x';
	}
	if (str[*i] == '%')
		value->a = '%';
	if (str[*i] == 's')
	{
		value->s = va_arg(ap, const char *);
		if (!value->s)
			value->s = "(null)";
	}
	fill_duxxp(value, str, i, ap);
	if (!value->c && !value->s && !value->i && !value->u && !value->x
	&& !value->z && !value->p && !value->a && !value->q && !value->w)
		return (1);
	return (0);
}

ssize_t	fill_hex_struct(unsigned long long nbr, t_type_list *value,
	char *base, ssize_t *i)
{
	t_hex_list	*old;

	while (nbr >= 16)
	{
		old = value->hex;
		value->hex->c = base[nbr % 16];
		nbr /= 16;
		*i += 1;
		if (!(value->hex->next = malloc(sizeof(t_hex_list))))
		{
			clean_hex(value, old);
			return (0);
		}
		value->hex = value->hex->next;
		value->hex->prev = old;
	}
	value->hex->c = base[nbr % 16];
	value->hex->next = NULL;
	return (1);
}
