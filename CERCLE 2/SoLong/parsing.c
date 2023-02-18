/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:01:36 by anguinau          #+#    #+#             */
/*   Updated: 2021/10/28 00:46:20 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	parsing_fail(char *step, t_parsing *start)
{
	t_parsing	*to_free;

	while (start->next)
	{
		start->c = 0;
		to_free = start;
		start = start->next;
		free(to_free);
		to_free = NULL;
	}
	start->c = 0;
	free(start);
	start = NULL;
	return (system_error(step, NULL));
}

int	parsing_end(int to_malloc, t_map *map_infos, t_parsing *start)
{
	int			i;
	char		*str;
	t_parsing	*to_free;

	i = 0;
	str = malloc(sizeof(char) * to_malloc);
	if (!str)
		return (parsing_fail("MALLOC", start));
	while (start->next)
	{
		str[i++] = start->c;
		to_free = start;
		start->c = 0;
		start = start->next;
		free(to_free);
		to_free = NULL;
	}
	str[i] = start->c;
	start->c = 0;
	free(start);
	start = NULL;
	map_infos->map_struct = str;
	return (check_map_infos(map_infos, 0, 0, 0));
}

int	read_process(int fd, int *to_malloc, t_parsing *parse, t_parsing *start)
{
	int	read_ret;

	read_ret = -1;
	while (read_ret)
	{
		read_ret = read(fd, &parse->c, 1);
		if (read_ret == -1)
			return (parsing_fail("READ", start));
		if (++*to_malloc && !read_ret)
			break ;
		parse->next = malloc(sizeof(t_parsing));
		if (!parse->next)
			return (parsing_fail("MALLOC", start));
		parse = parse->next;
		parse->c = 0;
		parse->next = NULL;
	}
	return (1);
}

int	parsing(int fd, t_map *map_infos)
{
	int			to_malloc;
	t_parsing	*parse;
	t_parsing	*start;

	to_malloc = 0;
	parse = malloc(sizeof(t_parsing));
	if (!parse)
		return (system_error("MALLOC", NULL));
	map_infos->map_struct = NULL;
	map_infos->map_tab = NULL;
	map_infos->map_size = 0;
	parse->c = 0;
	parse->next = NULL;
	start = parse;
	if (!read_process(fd, &to_malloc, parse, start))
		return (0);
	close(fd);
	return (parsing_end(to_malloc, map_infos, start));
}
