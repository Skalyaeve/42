/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:33:37 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/08 23:44:45 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*find_path(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i] + 5);
	return (NULL);
}

char	*get_final_path(char *cmd, char **paths)
{
	char	*ret;
	char	*tmp;
	int		i;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		ret = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(ret, X_OK) != -1)
		{
			free_array(paths);
			return (ret);
		}
		free(ret);
	}
	free_array(paths);
	return (NULL);
}

char	**get_cmd(char *av, char **envp)
{
	char	**cmd;
	char	**paths;
	char	*res;

	cmd = ft_split(av, ' ');
	if (!access(cmd[0], X_OK))
		return (cmd);
	paths = ft_split(find_path(envp), ':');
	if (paths == NULL)
	{
		ft_error("command not found: ", av, 1);
		free_array(cmd);
		return (NULL);
	}
	res = get_final_path(cmd[0], paths);
	if (res == NULL)
	{
		free_array(cmd);
		ft_error("command not found: ", av, 1);
		return (NULL);
	}
	free(cmd[0]);
	cmd[0] = res;
	return (cmd);
}
