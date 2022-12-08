/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:08:05 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/08 19:26:32 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// MEMORY LEAK SAFE OR NOT ?
static char	**ft_arrjoin(char **strs1, char **strs2)
{
	char	**strs;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = 0;
	len2 = 0;
	while (strs1[len1])
		len1++;
	while (strs2[len2])
		len2++;
	strs = (char **)malloc((len1 + len2 + 1) * sizeof(char *));
	if (!strs)
		return ((char **)0);
	i = 0;
	while (strs1[i])
		strs[i++] = strs1[i];
	while (strs2[i - len1])
		strs[i++] = strs2[i - len1];
	strs[i] = (char *)0;
	free(strs1);
	free(strs2);
	return (strs);
}

// MEMORY LEAK SAFE OR NOT ?
char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*str1;
	char	*str2;
	char	*sep;
	size_t	slen;

	// s is initialy not from heap so not modifiable, BUT could be...
	// so how can I tell the difference???
	slen = ft_strlen(s);
	sep = ft_memchr(s, c, slen);
	if (sep)
	{
		str1 = ft_substr(s, 0, (sep - s)); // Alt that does not use the heap
		str2 = ft_substr(s, ((sep - s) + 1), (slen - (sep - s + 1)));
		//free(s);
		strs = ft_arrjoin(ft_split(str1, c), ft_split(str2, c));
	}
	else
	{
		strs = (char **)malloc((1 + 1) * sizeof(char *));
		if (!strs)
			return ((char **)0);
		str1 = s; // or ft_strdup(s);
		str2 = (char *)0;
		strs[0] = str1;
		strs[1] = str2;
	}
	return (strs);
}
