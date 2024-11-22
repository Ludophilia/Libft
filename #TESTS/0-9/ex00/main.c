/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 17:37:10 by jegerman         ###   ########.fr       */
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

	str = "0- lLi#!oof+-()\x80\xff";
	i = -1;
	while (str[++i])
	{
		ret[0] = isalpha(str[i]);
		ret[1] = ft_isalpha(str[i]);
		// printf("isalpha('%c') -> %i\n", str[i], ret[0]);
		// printf("ft_isalpha('%c') -> %i \n", str[i], ret[1]);
		assert(ret[0] == ret[1]);
	}
	printf("[OK] isalpha\n");
}
