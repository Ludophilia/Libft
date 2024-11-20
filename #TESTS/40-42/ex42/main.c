/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/20 17:26:23 by jegerman         ###   ########.fr       */
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

static void	hdn_test_lstmap(int size, int max)
{
	t_list	*old_list;
	t_list	*new_list;
	void	*hdn_set_content_to_minus_one(void *);
	void	hdn_init_nodes(int, int, t_list **);

	old_list = NULL;
	hdn_init_nodes(size, max, &old_list);
	hdn_print_nodes(old_list);
	assert(ft_lstmap(NULL, hdn_set_content_to_minus_one, free) == NULL);
	hdn_check_nodes(old_list, 1, -1);
	hdn_print_nodes(old_list);
	new_list = ft_lstmap(old_list, hdn_set_content_to_minus_one, free);
	assert(new_list != NULL);
	hdn_check_nodes(new_list, 0, -1);
	hdn_print_nodes(new_list);
	assert(new_list != old_list);
	ft_lstclear(&old_list, NULL);
	ft_lstclear(&new_list, free);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_lstmap(5, 10);
}
