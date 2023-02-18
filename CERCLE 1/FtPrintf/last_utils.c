/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 09:20:03 by anguinau          #+#    #+#             */
/*   Updated: 2021/02/17 15:08:42 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_duxxp(t_type_list *value, const char *str, int *i, va_list ap)
{
	if (str[*i] == 'd' || str[*i] == 'i')
		if (!(value->i = va_arg(ap, int)))
			value->w = 1;
	if (str[*i] == 'u')
		if (!(value->u = va_arg(ap, unsigned int)))
			value->w = 1;
	if (str[*i] == 'x')
		if (!(value->x = va_arg(ap, unsigned int)))
			value->w = 1;
	if (str[*i] == 'X')
		if (!(value->z = va_arg(ap, unsigned int)))
			value->w = 1;
	if (str[*i] == 'p')
		if (!(value->p = va_arg(ap, unsigned long long int)))
			value->q = 1;
}
