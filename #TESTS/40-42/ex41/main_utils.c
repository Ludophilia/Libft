/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:52:46 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/20 15:54:19 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

void	hdn_set_content_to_minus_one(void *content)
{
	if (content)
		*(int *)content = -1;
}

void	hdn_init_nodes(int size, int max, t_list **node)
{
	int		*tmp_content;
	t_list	*tmp_node;

	while (size--)
	{
		tmp_content = malloc(sizeof(int));
		assert(tmp_content != NULL);
		*tmp_content = rand() % max;
		tmp_node = ft_lstnew(tmp_content);
		assert(tmp_node != NULL);
		ft_lstadd_back(node, tmp_node);
	}
}

void	hdn_print_nodes(t_list *node)
{
	t_list	*first;

	if (node->next == NULL && printf("[%i]\n", *(int *)node->content))
		return ;
	first = node;
	while (node)
	{
		if (node == first)
			printf("[%i ", *(int *)node->content);
		else if (node->next == NULL)
			printf("%i]\n", *(int *)node->content);
		else
			printf("%i ", *(int *)node->content);
		node = node->next;
	}
}
