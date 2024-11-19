/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/19 13:20:18 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_test_lstnew(int nb)
{
	t_list	*node;
	int		*content;

	content = malloc(sizeof(int));
	assert(content != NULL);
	*content = nb;
	printf("ft_lstnew_fd(%p)\n", content);
	node = ft_lstnew(content);
	assert(node != NULL);
	printf("node->content -> %i\n", *(int *)node->content);
	assert (*(int *)node->content == nb);
	printf("node->next -> %p\n", node->next);
	assert(node->next == NULL);
	free(content);
	free(node);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_lstnew(42);
}
