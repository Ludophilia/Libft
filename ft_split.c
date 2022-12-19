/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:08:05 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/20 00:13:49 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_arrlen(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}

static char	**ft_arrjoin(char **strs1, char **strs2)
{
	char	**strs;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_arrlen(strs1);
	len2 = ft_arrlen(strs2);
	strs = (char **)malloc((len1 + len2 + 1) * sizeof(char *));
	if (!strs)
		return ((char **)0);
	i = 0;
	while (strs1[i])
	{
		strs[i] = strs1[i];
		i++;
	}
	while (strs2[i - len1])
	{
		strs[i] = strs2[i - len1];
		i++;
	}
	strs[i] = (char *)0;
	free(strs1);
	free(strs2);
	return (strs);
}

#include <stdio.h>

// EXPERIMENT - Let's try a smarter split, that means no split with an empty 
// string. After that, if it works, let's HUNT those mf leaks!
char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*str1;
	char	*str2;
	char	*sep;
	size_t	slen;

	slen = ft_strlen(s);
	sep = ft_memchr(s, c, slen);
	if (sep)
	{
		str1 = ft_substr(s, 0, (sep - s)); 
		str2 = ft_substr(s, ((sep - s) + 1), (slen - (sep - s + 1)));
		printf("\t[ft_split] str1 -> '%s', str2 -> '%s'\n", str1, str2);
		if (*str1 && !*str2)
		{
			strs = ft_split(str1, c);
			free(str2);
		}
		else if (*str2 && !*str1)
		{
			strs = ft_split(str2, c);
			free(str1);
		}
		if (*str1 && *str2)
			strs = ft_arrjoin(ft_split(str1, c), ft_split(str2, c));
		// AND WHAT ABOUT THE CASE WHERE both !*str1 && !*str2 ? point
		// to a null character...?
			// I have to return something as an array of str but there is
			// no str to return... So what should I do? Return a strs
			// with a str pointing to a null ?
			// So getting back to where I started ???
		// Maybe I should try the second idea ?? 
	}
	else
	{
		strs = (char **)malloc((1 + 1) * sizeof(char *));
		if (!strs)
			return ((char **)0);
		str1 = (char *)s;
		str2 = (char *)0;
		strs[0] = str1;
		strs[1] = str2;
	}
	return (strs);
}
