/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/07 11:57:03 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include "libft.h"

static void	hdn_test_and_cmp(int c)
{
	int	ret[2];

	ret[0] = isprint(c);
	ret[1] = ft_isprint(c);
	printf("isprint('%i') -> %i\n", c, ret[0]);
	printf("ft_isprint('%i') -> %i \n", c, ret[1]);
	assert(ret[0] == ret[1]);
}

int	main(void)
{
	char	*str;
	int		i;

	str = "\x010-\x1f lLi#!o42of+-()\x7e\x7f\x80\xff";
	i = -1;
	while (str[++i])
		hdn_test_and_cmp(str[i]);
	hdn_test_and_cmp(str[i]);
}
