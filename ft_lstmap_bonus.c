/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:28:27 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/13 17:04:47 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*last;
	t_list	*new;

	first = (t_list *)0;
	last = (t_list *)0;
	while (lst)
	{
		if (f)
			lst->content = f(lst->content);
		else if (del)
			del(lst->content);
		new = ft_lstnew(lst->content);
		if (!new)
			return ((t_list *)0);
		if (!first)
			first = new;
		if (last)
			last->next = new;
		last = new;
		lst = lst->next;
		ft_lstdelone(lst, 0);
	}
	return (first);
}
