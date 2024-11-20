/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:42:14 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/20 13:47:05 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

void	hdn_free_list(t_list *node)
{
	t_list	*next;

	next = node;
	while (node)
	{
		next = node->next;
		free(node->content);
		free(node);
		node = next;
	}
}

void	hdn_init_nodes(int *nb, int *content[2], t_list **node_a,
	t_list **node_b)
{
	if (node_a != NULL)
	{
		content[0] = malloc(sizeof(int));
		*content[0] = nb[0];
		assert(content[0] != NULL);
		*node_a = ft_lstnew(content[0]);
		printf("[0] (*node_a)->content -> %i\n", *(int *)(*node_a)->content);
		assert(*node_a != NULL);
	}
	if (node_b != NULL)
	{
		content[1] = malloc(sizeof(int));
		*content[1] = nb[1];
		assert(content[1] != NULL);
		*node_b = ft_lstnew(content[1]);
		printf("[0] (*node_b)->content -> %i\n", *(int *)(*node_b)->content);
		assert(*node_b != NULL);
	}
}
