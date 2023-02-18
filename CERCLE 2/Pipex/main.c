/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:30:44 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/08 23:45:15 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	child_one(int *pipe_fd, int fd1, char **cmd1)
{
	extern char	**environ;

	if (fd1 < 0)
		return ;
	dup2(fd1, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(fd1);
	close(pipe_fd[0]);
	if (cmd1 != NULL)
	{
		if (execve(cmd1[0], cmd1, environ) < 0)
			ft_error("execve error: ", cmd1[0], 1);
	}
}

void	child_two(int *pipe_fd, int fd2, char **cmd2)
{
	extern char	**environ;

	if (fd2 < 0)
		return ;
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(fd2);
	close(pipe_fd[1]);
	if (cmd2 != NULL)
	{
		if (execve(cmd2[0], cmd2, environ) < 0)
			ft_error("execve error: ", cmd2[0], 1);
	}
}

int	pipex(int fd1, int fd2, char **cmd1, char **cmd2)
{
	int		pipe_fd[2];
	pid_t	children[2];

	pipe(pipe_fd);
	children[0] = fork();
	if (children[0] < 0)
		return (ft_error("fork failed\n", NULL, 1));
	if (children[0] == 0)
		child_one(pipe_fd, fd1, cmd1);
	else
	{
		children[1] = fork();
		if (children[1] < 0)
			return (ft_error("fork failed\n", NULL, 1));
		if (children[1] == 0)
			child_two(pipe_fd, fd2, cmd2);
		else
		{
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			waitpid(-1, NULL, 0);
			waitpid(-1, NULL, 0);
		}
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int		fd1;
	int		fd2;
	char	**cmd1;
	char	**cmd2;

	if (ac != 5)
		return (ft_error("expected 5 arguments", NULL, 1));
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd1 < 0)
		ft_error("could not open file: ", av[1], 1);
	if (fd2 < 0)
		ft_error("could not open file: ", av[4], 1);
	cmd1 = get_cmd(av[2], envp);
	cmd2 = get_cmd(av[3], envp);
	pipex(fd1, fd2, cmd1, cmd2);
	free_array(cmd1);
	free_array(cmd2);
	return (0);
}
