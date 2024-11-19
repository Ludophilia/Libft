/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/19 17:32:41 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_free_list(t_list *node)
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

static void	hdn_init_nodes(int nb[2], int *content[2], t_list **node_a,
	t_list **node_b)
{
	content[0] = malloc(sizeof(int));
	content[1] = malloc(sizeof(int));
	assert(content[0] != NULL && content[1] != NULL);
	*content[0] = nb[0];
	*content[1] = nb[1];
	*node_a = ft_lstnew(content[0]);
	*node_b = ft_lstnew(content[1]);
	assert(*node_a != NULL && *node_b != NULL);
	printf("(*node_a)->content -> %i ; ", *(int *)(*node_a)->content);
	printf("(*node_b)->content -> %i\n", *(int *)(*node_b)->content);
}

static void	hdn_test_lstadd_back(int nb[2])
{
	t_list	*node_a;
	t_list	*node_b;
	int		*content[2];

	hdn_init_nodes(nb, content, &node_a, &node_b);
	ft_lstadd_back(&node_a, node_b);
	printf("ft_lstadd_back(%p, %p)\n", node_a, node_b);
	printf("node_a->content -> %i ; ", *(int *)node_a->content);
	printf("node_b->content -> %i\n", *(int *)node_a->next->content);
	assert(node_a->next == node_b && *(int *)node_a->content == *content[0]
		&& *(int *)node_a->next->content == *content[1]);
	hdn_free_list(node_a);
	printf("[OK]\n");
}

static void	hdn_test_edges_lstadd_back(int *nb, int test_for_null)
{
	t_list	*node_a;
	t_list	*node_b;
	int		*content[2];

	if (test_for_null)
	{
		hdn_init_nodes(nb, content, &node_a, &node_b);
		printf("ft_lstadd_back(%p, %p)\n", NULL, NULL);
		ft_lstadd_back(NULL, NULL);
		printf("node_a->content -> %i ; ", *(int *)node_a->content);
		printf("node_b->content -> %i\n", *(int *)node_b->content);
		printf("node_a->next -> %p\n", node_a->next);
		assert(node_a->next == NULL);
		hdn_free_list(node_a);
		hdn_free_list(node_b);
		printf("[OK]\n");
	}
}


int	main(void)
{
	hdn_test_lstadd_back((int []){0, 42});
}
