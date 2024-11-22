/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 17:39:15 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include "libft.h"

int	main(void)
{
	char	*str;
	int		i;
	int		ret[2];

	str = "0- lLi#!o42of+-()\x80\xff";
	i = -1;
	while (str[++i])
	{
		ret[0] = isdigit(str[i]);
		ret[1] = ft_isdigit(str[i]);
		// printf("isdigit('%c') -> %i\n", str[i], ret[0]);
		// printf("ft_isdigit('%c') -> %i \n", str[i], ret[1]);
		assert(ret[0] == ret[1]);
	}
	printf("[OK] isdigit\n");
}
