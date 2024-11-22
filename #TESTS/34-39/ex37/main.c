/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 19:16:29 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

static t_list	*hdn_init_nodes(int nb[2])
{
	t_list	*node_a;
	t_list	*node_b;
	int		*content[2];

	content[0] = malloc(sizeof(int));
	assert(content[0] != NULL);
	*content[0] = nb[0];
	content[1] = malloc(sizeof(int));
	assert(content[1] != NULL);
	*content[1] = nb[1];
	node_a = ft_lstnew(content[0]);
	node_b = ft_lstnew(content[1]);
	node_a->next = node_b;
	assert(*(int *)node_a->next->content == *content[1]);
	return (node_a);
}

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

static void	hdn_test_lstlast(int nb[2], int test_for_null)
{
	t_list	*node;
	t_list	*last;

	if (test_for_null)
	{
		last = ft_lstlast(NULL);
		// printf("ft_lstlast(%p) -> %p\n", NULL, last);
		// printf("[OK]\n");
		return ;
	}
	node = hdn_init_nodes(nb);
	last = ft_lstlast(node);
	// printf("ft_lstlast(%p) -> %p\n", node, last);
	assert(*(int *)last->content == nb[1] && last->next == NULL);
	hdn_free_list(node);
}

int	main(void)
{
	hdn_test_lstlast(NULL, 1);
	hdn_test_lstlast((int []){0, 42}, 0);
	printf("[OK] lstlast\n");
}
