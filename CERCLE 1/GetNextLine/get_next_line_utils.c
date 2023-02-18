/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:23:35 by anguinau          #+#    #+#             */
/*   Updated: 2020/11/28 00:01:12 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		if ((*lst)->str)
			free((*lst)->str);
		free(*lst);
		*lst = next;
	}
	lst = NULL;
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = -1;
	while (s && s[++i])
		if (s[i] == c)
			return (s + i);
	if (s && s[i] == '\0' && c == '\0')
		return (s + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	ssize_t	i;
	ssize_t	j;
	char	*str;

	if ((i = 0) == 0 && !s2)
		return (NULL);
	while ((j = 0) == 0 && s1 && s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(str = malloc(i + j + 1)))
		return (NULL);
	i = -1;
	while ((j = -1) == -1 && s1 && s1[++i])
		str[i] = s1[i];
	if (!s1)
		i++;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	if (s1)
		free(s1);
	return (str);
}

int		check_rest(t_list **rest, ssize_t read_ret, t_list **begin)
{
	t_list	*next;

	if (read_ret == 0)
	{
		if ((*begin)->fd == (*rest)->fd)
		{
			next = (*rest)->next;
			free((*rest)->str);
			free(*rest);
			*begin = next;
			return (0);
		}
		while (((*begin)->next) && ((*begin)->next->fd != (*rest)->fd))
			begin = &(*begin)->next;
		if ((*begin)->next)
			(*begin)->next = (*begin)->next->next;
		free((*rest)->str);
		free(*rest);
		return (0);
	}
	return (1);
}
