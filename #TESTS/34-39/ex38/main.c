/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/20 13:46:11 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

void	hdn_free_list(t_list *node);

void	hdn_init_nodes(int *nb, int *content[2], t_list **node_a,
			t_list **node_b);

static void	hdn_test_null_cases_lstadd_back(int *nb)
{
	t_list	*node_a;
	t_list	*node_b;
	int		*content[2];

	hdn_init_nodes(nb, content, &node_a, &node_b);
	printf("[0] ft_lstadd_back(%p, %p)\n", NULL, NULL);
	ft_lstadd_back(&node_a, NULL);
	printf("[1] node_a->content -> %i ; ", *(int *)node_a->content);
	printf("node_b->content -> %i\n", *(int *)node_b->content);
	printf("[1] node_a->next -> %p\n", node_a->next);
	assert(node_a->next == NULL);
	hdn_free_list(node_a);
	hdn_free_list(node_b);
	printf("[OK]\n");
}

static void	hdn_test_regular_lstadd_back(int nb[2])
{
	t_list	*node_a;
	t_list	*node_b;
	int		*content[2];

	hdn_init_nodes(nb, content, &node_a, &node_b);
	ft_lstadd_back(&node_a, node_b);
	printf("[0] ft_lstadd_back(%p, %p)\n", node_a, node_b);
	printf("[1] node_a->content -> %i ; ", *(int *)node_a->content);
	printf("node_a->next->content -> %i\n", *(int *)node_a->next->content);
	assert(node_a->next == node_b && *(int *)node_a->content == *content[0]
		&& *(int *)node_a->next->content == *content[1]);
	hdn_free_list(node_a);
	printf("[OK]\n");
}

static void	hdn_test_edge_cases_lstadd_back(int nb)
{
	t_list	*node_a;
	t_list	*node_b;
	int		*content[2];

	node_a = NULL;
	hdn_init_nodes((int []){0, nb}, content, NULL, &node_b);
	ft_lstadd_back(&node_a, node_b);
	printf("[0] ft_lstadd_back(%p, %p)\n", node_a, node_b);
	printf("[1] node_a->content -> %i\n", *(int *)node_a->content);
	assert(node_a->next == NULL && *(int *)node_a->content == *content[1]);
	hdn_free_list(node_a);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_null_cases_lstadd_back((int []){0, 42});
	hdn_test_regular_lstadd_back((int []){0, 42});
	hdn_test_edge_cases_lstadd_back(21);
}
