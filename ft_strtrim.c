/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:59:24 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/06 17:28:23 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// MEMORY LEAK SAFE OR NOT ?
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	lenset;
	size_t	lens1;
	char	*str;
	char	*start;
	char	*end;
	// Maybe would be simpley with trad i and j ??

	lenset = ft_strlen(set);
	lens1 = ft_strlen(s1);
	start = (char *)s1;
	end = (char *)s1 + lens1;
	if (ft_strnstr(start, set, lenset))
		start = (char *)s1 + lenset;
	if (ft_strnstr((end - lenset), set, lenset))
		end = (char *)s1 + lens1 - lenset;
	str = malloc(((uintptr_t)end - (uintptr_t)start + 1) * sizeof(char));
	if (!str)
		return ((char *)0);
	while (str)
		// ???
	// Newstr with set at start and/or at end
}
