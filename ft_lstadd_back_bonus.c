/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:34:13 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/13 17:04:21 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

// NULL protection please
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	ft_lstlast(*lst)->next = new;
	new->next = (t_list *)0;
}
