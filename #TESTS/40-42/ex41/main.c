/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 19:28:47 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

void	hdn_print_nodes(t_list *node);

static void	hdn_check_nodes(t_list *node, int difference_mode, int nb)
{
	while (node)
	{
		if (difference_mode)
			assert(*(int *)node->content != nb);
		else
			assert(*(int *)node->content == nb);
		node = node->next;
	}
}

static void	hdn_test_lstiter(int size, int max)
{
	t_list	*node;
	void	hdn_set_content_to_minus_one(void *);
	void	hdn_init_nodes(int, int, t_list **);

	node = NULL;
	hdn_init_nodes(size, max, &node);
	// hdn_print_nodes(node);
	ft_lstiter(NULL, free);
	hdn_check_nodes(node, 1, -1);
	// hdn_print_nodes(node);
	ft_lstiter(node, hdn_set_content_to_minus_one);
	hdn_check_nodes(node, 0, -1);
	// hdn_print_nodes(node);
	ft_lstclear(&node, free);
}

int	main(void)
{
	hdn_test_lstiter(5, 10);
	printf("[OK] lstiter\n");
}
