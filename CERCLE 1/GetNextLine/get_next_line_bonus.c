/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:24:32 by anguinau          #+#    #+#             */
/*   Updated: 2020/11/28 00:52:17 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	new_read(char **readed, t_list *rest, t_list *begin)
{
	ssize_t	i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * BUFFER_SIZE + 1)))
	{
		ft_lstclear(&begin);
		return (-1);
	}
	if ((i = read(rest->fd, str, BUFFER_SIZE)) == -1)
	{
		free(str);
		ft_lstclear(&begin);
		return (-1);
	}
	str[i] = '\0';
	*readed = str;
	return (i);
}

int		parsing_ended(char **line, t_list **rest, char *eol)
{
	char	*str;
	ssize_t	i;

	i = 0;
	while ((*rest)->str[i] != '\n' && (*rest)->str[i] != '\0')
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (-1);
	str[i] = '\0';
	i = -1;
	while ((*rest)->str[++i] != '\n' && (*rest)->str[i] != '\0')
		str[i] = (*rest)->str[i];
	if ((*line = str) == str && eol)
	{
		if (!((*rest)->str = ft_strjoin(NULL, eol + 1)))
			return (-1);
		free(eol - i);
	}
	else if ((eol = ft_strchr((*rest)->str, '\0')) != NULL)
	{
		if (!((*rest)->str = ft_strjoin(NULL, eol)))
			return (-1);
		free(eol - i);
	}
	return (0);
}

int		until_eol(char **line, t_list **rest, t_list **begin)
{
	char	*eol;
	char	*readed;
	ssize_t	read_ret;
	int		ret;

	readed = NULL;
	read_ret = BUFFER_SIZE;
	while (!(eol = ft_strchr((*rest)->str, '\n')) && read_ret != 0)
	{
		if ((read_ret = new_read(&readed, *rest, *begin)) == -1)
			return (-1);
		if (!((*rest)->str = ft_strjoin((*rest)->str, readed)))
		{
			free(readed);
			ft_lstclear(begin);
			return (-1);
		}
		free(readed);
	}
	if ((ret = parsing_ended(line, rest, eol)) == -1)
	{
		ft_lstclear(begin);
		return (-1);
	}
	return (check_rest(rest, read_ret, begin));
}

int		get_in_raw(t_list ***nav, t_list **rest, int fd)
{
	while (((*(*nav))->fd != fd))
	{
		if (!(*(*nav))->next)
		{
			if (!((*(*nav))->next = malloc(sizeof(t_list))))
			{
				ft_lstclear(rest);
				return (-1);
			}
			(*(*nav))->next->fd = fd;
			(*(*nav))->next->str = NULL;
			(*(*nav))->next->next = NULL;
		}
		*nav = &(*(*nav))->next;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*rest;
	t_list			**nav;

	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (!rest)
	{
		if (!(rest = malloc(sizeof(t_list))))
			return (-1);
		rest->fd = fd;
		rest->str = NULL;
		rest->next = NULL;
	}
	nav = &rest;
	if (get_in_raw(&nav, &rest, fd) != 0)
		return (-1);
	return (until_eol(line, nav, &rest));
}
