/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:44:00 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/13 17:04:16 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

// NULL protection please
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cnode;
	t_list	*next;

	cnode = *lst;
	while (cnode)
	{
		next = cnode->next;
		ft_lstdelone(cnode, del);
		cnode = next;
	}
	*lst = (t_list *)0;
}
