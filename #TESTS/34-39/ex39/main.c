/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 19:19:34 by jegerman         ###   ########.fr       */
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

void	hdn_init_node(int nb, t_list **node_a)
{
	int	*content;

	if (node_a != NULL)
	{
		content = malloc(sizeof(int));
		*content = nb;
		assert(content != NULL);
		*node_a = ft_lstnew(content);
		assert(*node_a != NULL);
		// printf("[0] (*node_a)->content -> %i\n", *(int *)(*node_a)->content);
	}
}

static void	hdn_del_content(void *content)
{
	free(content);
}

static void	hdn_test_regular_lstdelone(int nb)
{
	t_list	*node_a;

	hdn_init_node(nb, &node_a);
	ft_lstdelone(NULL, hdn_del_content);
	// printf("[0] ft_lstdelone(%p)\n", NULL);
	// printf("[1] node_a->content -> %i\n", *(int *)node_a->content);
	assert(node_a->next == NULL && *(int *)node_a->content == nb);
	// printf("[1] ft_lstdelone(%p)\n", node_a);
	ft_lstdelone(node_a, hdn_del_content);
}

int	main(void)
{
	hdn_test_regular_lstdelone(420);
	printf("[OK] lstdelone\n");
}
