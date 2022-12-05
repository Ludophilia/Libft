/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:44:51 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/05 13:31:38 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return (big);
	i = 0;
	while ((i < len) && big[i])
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (!little[j + 1])
				return (big + i);
			j++;
		}
		i++;
	}		
	return ((char *)0);
}
