/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:08:56 by anguinau          #+#    #+#             */
/*   Updated: 2020/11/25 18:18:55 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;

	if ((start = NULL) == NULL && (!lst || !(f)))
		return (NULL);
	while (lst)
	{
		if (!(new = ft_lstnew((f)(lst->content))))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		if (!(new->content))
		{
			ft_lstclear(&start, del);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new);
		lst = lst->next;
	}
	return (start);
}
