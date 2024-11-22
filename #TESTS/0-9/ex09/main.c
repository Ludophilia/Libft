/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 17:59:18 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

// // What happens when dest > src
static void	hdn_test_fwd_move(int offset, size_t size)
{
	char	*str[2];
	void	*ret[2];

	if (offset < 0 && offset > 7)
		return ;
	str[0] = (char []){'x', '1', '2', '3', '4', '4', '5', '6', 0};
	str[1] = (char []){'x', '1', '2', '3', '4', '4', '5', '6', 0};
	// printf("str[0]: %s\n", str[0]);
	// printf("str[1]: %s\n", str[1]);
	ret[0] = memmove(str[0] + offset, str[0], size);
	ret[1] = ft_memmove(str[1] + offset, str[1], size);
	// printf("str[0]: %s\n", str[0]);
	// printf("str[1]: %s\n", str[1]);
	assert(ret[0] == str[0] + 1 && ret[1] == str[1] + 1);
	assert(ft_strncmp(str[0], "xx123456", 8) == 0);
	assert(ft_strncmp(str[1], "xx123456", 8) == 0);
}

// // What happens when dest < src
static void	hdn_test_bkwd_move(int offset, size_t size)
{
	char	*str[2];
	void	*ret[2];

	if (offset < 0 && offset > 7)
		return ;
	str[0] = (char []){'x', '1', '2', '3', '4', '0', '0', '0', 0};
	str[1] = (char []){'x', '1', '2', '3', '4', '0', '0', '0', 0};
	// printf("str[0]: %s\n", str[0]);
	// printf("str[1]: %s\n", str[1]);
	ret[0] = memmove(str[0], str[0] + offset, size);
	ret[1] = ft_memmove(str[1], str[1] + offset, size);
	// printf("str[0]: %s\n", str[0]);
	// printf("str[1]: %s\n", str[1]);
	assert(ret[0] == str[0] && ret[1] == str[1]);
	assert(ft_strncmp(str[0], "123440", 6) == 0);
	assert(ft_strncmp(str[1], "123440", 6) == 0);
}

// // Regular copy, no overlap
static void	hdn_test_std_copy(void)
{
	char	*str[2];
	void	*ret[2];

	str[0] = (char []){'x', '1', '2', '3', 'z', 'z', 'z', 'z', 0};
	str[1] = (char []){'x', '1', '2', '3', 'z', 'z', 'z', 'z', 0};
	// printf("str[0]: %s\n", str[0]);
	// printf("str[1]: %s\n", str[1]);
	ret[0] = memmove(str[0] + 4, str[0], 4);
	ret[1] = ft_memmove(str[1] + 4, str[1], 4);
	// printf("str[0]: %s\n", str[0]);
	// printf("str[1]: %s\n", str[1]);
	assert(ret[0] == str[0] + 4 && ret[1] == str[1] + 4);
	assert(ft_strncmp(str[0] + 4, "x123\0", 5) == 0);
	assert(ft_strncmp(str[1] + 4, "x123\0", 5) == 0);
}

// // What happens when src == dest ?
int	main(void)
{
	hdn_test_fwd_move(1, 4);
	hdn_test_bkwd_move(1, 4);
	hdn_test_std_copy();
	printf("[OK] memmove\n");
}
