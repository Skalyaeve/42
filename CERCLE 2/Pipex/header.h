/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 23:28:54 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/08 23:38:27 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	free_array(char **str);
char	**get_cmd(char *av, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *str);
int		ft_error(char *error_message, char *optional, int ret);
char	*ft_strdup(const char *s);

#endif
