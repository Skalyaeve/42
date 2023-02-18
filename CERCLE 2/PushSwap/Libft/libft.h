/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:24:01 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 20:55:08 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

char		*ft_substr(const char *s, unsigned int start, size_t len);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
char		**ft_split(char const *s, char c);
int			ft_putstr_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd);
void		*ft_memset(void *s, int c, size_t n);
long long	ft_long_long_atoi(const char *nptr);
char		*ft_itoa(int n);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_isalnum(int c);
int			ft_atoi(const char *nptr);
int			ft_strchr(char *str, const char *to_find);
char		*ft_strcut(const char *src, int start, const char stop);
int			malloc_str(char **str, int size);
int			malloc_str_tab(char ***str, int size);
int			ft_strncmp(char *src, char *to_find, int n);
int			ft_swap(int *ptr1, int *ptr);
int			return_min(int n1, int n2);
int			return_max(int n1, int n2);

#endif