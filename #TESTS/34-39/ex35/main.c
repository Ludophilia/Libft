/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 19:13:29 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_init_nodes(int nb[2], int *content[2], t_list **node_a,
	t_list **node_b)
{
	content[0] = malloc(sizeof(int));
	assert(content[0] != NULL);
	*content[0] = nb[0];
	content[1] = malloc(sizeof(int));
	assert(content[1] != NULL);
	*content[1] = nb[1];
	*node_a = ft_lstnew(content[0]);
	assert(*node_a != NULL && (*node_a)->next == NULL
		&& *(int *)(*node_a)->content == *content[0]);
	// printf("(*node_a)->content -> %i ; ", *(int *)(*node_a)->content);
	*node_b = ft_lstnew(content[1]);
	assert(*node_b != NULL && (*node_b)->next == NULL
		&& *(int *)(*node_b)->content == *content[1]);
	// printf("(*node_b)->content -> %i\n", *(int *)(*node_b)->content);
}

static void	hdn_test_lstadd_front(int nb[2])
{
	t_list	*node_a;
	t_list	*node_a0;
	t_list	*node_b;
	int		*content[2];

	hdn_init_nodes(nb, content, &node_a, &node_b);
	node_a0 = node_a;
	ft_lstadd_front(&node_a, node_b);
	// printf("ft_lstadd_front(%p, %p)\n", node_a, node_b);
	// printf("node_a->content -> %i ; ", *(int *)node_a->content);
	assert(*(int *)node_a->content == *content[1]);
	assert(node_a == node_b && node_a->next == node_a0);
	// printf("node_b->content -> %i\n", *(int *)node_a->next->content);
	assert(*(int *)node_a->next->content == *content[0]);
	free(content[0]);
	free(content[1]);
	free(node_a->next);
	free(node_a);
}

int	main(void)
{
	hdn_test_lstadd_front((int []){0, 42});
	printf("[OK] lstadd_front\n");
}
