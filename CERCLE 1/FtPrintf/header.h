/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:24:11 by anguinau          #+#    #+#             */
/*   Updated: 2021/02/17 16:22:58 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_tab
{
	int	m;
	int	o;
	int	l;
	int	p;
}				t_tab;

typedef struct	s_hex_list
{
	char				c;
	struct s_hex_list	*prev;
	struct s_hex_list	*next;
}				t_hex_list;

typedef struct	s_type_list
{
	unsigned char		c;
	unsigned char		a;
	const char			*s;
	int					i;
	int					w;
	unsigned int		u;
	unsigned int		x;
	unsigned int		z;
	unsigned long long	p;
	unsigned int		q;
	t_hex_list			*hex;
}				t_type_list;

int				ft_printf(const char *str, ...);
void			ft_putnbr_fd(long long n, ssize_t *ret, int p, int o);
ssize_t			convert_it(const char *str, int *i,
			ssize_t *ret, va_list ap);
ssize_t			finish_it(t_tab *molp, t_type_list *value, ssize_t *ret);
ssize_t			get_final_lenght(t_tab *molp, t_type_list *value);
void			avoid_convert(const char *str, int *i,
			ssize_t *ret, t_tab *molp);
void			print_hex(t_type_list *value, ssize_t *ret, t_tab *molp);
ssize_t			count_nbr(ssize_t nbr);
void			ft_putstr_fd(const char *s, ssize_t fd,
			ssize_t *ret, t_tab *molp);
ssize_t			hex_convert(t_tab *molp, t_type_list *value);
ssize_t			fill_mo(t_tab *molp, const char *str,
			int *i, va_list ap);
ssize_t			fill_l(t_tab *molp, const char *str,
			int *i, va_list ap);
ssize_t			fill_p(t_tab *molp, const char *str, int *i, va_list ap);
ssize_t			ft_strlen(const char *s);
ssize_t			get_value(t_type_list *value, const char *str,
			int *i, va_list ap);
ssize_t			fill_hex_struct(unsigned long long nbr,
			t_type_list *value, char *base, ssize_t *i);
ssize_t			clean_up(t_tab *molp, t_type_list *value);
void			clean_hex(t_type_list *value, t_hex_list *old);
ssize_t			last_output(t_tab *molp, t_type_list *value, ssize_t *ret);
void			init_values(t_type_list *value);
void			fill_duxxp(t_type_list *value, const char *str,
			int *i, va_list ap);

#endif
