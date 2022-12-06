/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:59:24 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/06 23:29:31 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// MEMORY LEAK SAFE OR NOT ?
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	lenset;
	size_t	i;
	char	*str;

	start = 0;
	end = ft_strlen(s1);
	lenset = ft_strlen(set);
	if (ft_strnstr(s1, set, lenset))
		start = lenset;
	if (ft_strnstr(s1 + end - lenset, set, lenset))
		end -= lenset;
	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		return ((char *)0);
	i = 0;
	while (i < (end - start))
		str[i++] = s1[start + i];
	str[i] = '\x0';
	return (str);
}
