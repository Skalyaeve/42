/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:20:18 by anguinau          #+#    #+#             */
/*   Updated: 2020/11/27 19:01:19 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

typedef struct	s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
int				get_in_raw(t_list ***nav, t_list **rest, int fd);
int				until_eol(char **line, t_list **rest, t_list **begin);
int				parsing_ended(char **line, t_list **rest, char *eol);
int				check_rest(t_list **rest, ssize_t read_ret, t_list **begin);
ssize_t			new_read(char **readed, t_list *rest, t_list *begin);
void			ft_lstclear(t_list **lst);
char			*ft_strchr(char *s, char c);
char			*ft_strjoin(char *s1, char *s2);

#endif
