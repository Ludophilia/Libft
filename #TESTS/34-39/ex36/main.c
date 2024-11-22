/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 19:15:11 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

static t_list	*hdn_init_nodes(int size)
{
	t_list	*node;
	t_list	*current;

	node = NULL;
	while (size--)
	{
		current = ft_lstnew(NULL);
		assert(current != NULL);
		ft_lstadd_front(&node, current);
	}
	return (node);
}

static void	hdn_free_list(t_list *start)
{
	t_list	*next;

	next = start;
	while (start)
	{
		next = start->next;
		free(start);
		start = next;
	}
}

static void	hdn_test_lstsize(int expect, int test_for_null)
{
	t_list	*start;
	int		size;

	if (test_for_null)
	{
		size = ft_lstsize(NULL);
		// printf("ft_lstsize(%p) -> %i\n", NULL, size);
		assert(size == expect);
		return ;
	}
	start = hdn_init_nodes(expect);
	size = ft_lstsize(start);
	// printf("ft_lstsize(%p) -> %i\n", start, size);
	assert(size == expect);
	hdn_free_list(start);
}

int	main(void)
{
	hdn_test_lstsize(0, 1);
	hdn_test_lstsize(1, 0);
	hdn_test_lstsize(2, 0);
	hdn_test_lstsize(3, 0);
	hdn_test_lstsize(10, 0);
	printf("[OK] lstsize\n");
}
