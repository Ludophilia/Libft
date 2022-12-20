/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:08:05 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/20 22:27:56 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_arrlen(char **strs)
{
	int		i;
	size_t	len;

	i = -1;
	len = 0;
	while (strs[++i])
		if (*strs[i])
			len++;
	return (len);
}

void	debug_str(const char *s, char *str1, char *str2)
{
	printf("\t[ft_split] s %% 16 -> %li\n", (intptr_t)s % 16);
	printf("\t[ft_split] str1 - s -> %li\n", (intptr_t)(str1 - s));
	printf("\t[ft_split] str2 - s -> %li\n", (intptr_t)(str2 - s));
	printf("\t[ft_split] str2 - str1 -> %li\n\n", (intptr_t)(str2 - str1));
}

void	debug_strs(char **strs, int nl)
{
	printf("\t[debug_strs] arrlen = %lu\n", ft_arrlen(strs));
	if (!*strs)
		printf("\t\t-> just a null (char*)\n");
	while (*strs)
		printf("\t\t-> '%s'\n", *strs++);
	if (nl)
		printf("\n");
}

// First - The Algo
// Then - Memory (free those empty strs)
static char	**ft_join_words(char **strs1, char **strs2)
{
	char	**strs;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	len1 = ft_arrlen(strs1);
	len2 = ft_arrlen(strs2);
	// debug_strs(strs1, 0);
	// debug_strs(strs2, 0);
	strs = (char **)malloc((len1 + len2 + 1) * sizeof(char *));
	if (!strs)
		return ((char **)0);
	j = 0;
	i = 0;
	while (strs1[i])
	{
		// printf("\t[debug_strs] *strs1[%lu] = '%s'\n", i, strs1[i]);
		if (*strs1[i])
		{
			strs[j] = strs1[i]; // strs[j++] 
			j++;
		}
		else
			free(strs1[i]);
		i++;
	}
	i = 0;
	while (strs2[i])
	{
		// printf("\t[debug_strs] *strs2[%lu] = '%s'\n", i, strs2[i]);
		if (*strs2[i])
		{
			strs[j] = strs2[i]; // strs[j++] 
			j++;
		}
		else
			free(strs2[i]);
		i++;
	}
	strs[j] = (char *)0;
	// debug_strs(strs, 1);
	free(strs1);
	free(strs2);
	return (strs);
}
char	**ft_create_word(char *s)
{
	char	**strs;
	size_t	len;
	int		i;

	len = 0;
	if (*s)
		len++;
	strs = (char **)malloc((len + 1) * sizeof(char *));
	if (!strs)
		return ((char **)0);
	if (!((intptr_t)s % 16 == 0))// || ((intptr_t)(str1 - s) > 128128))
		s = ft_strdup(s);
	i = 0;
	while (len--)
		strs[i++] = s;
	strs[i] = (char *)0;
	return (strs);
}

// Returns sometimes ['0'] (arrjoin) and sometimes [''. '0'] (else branch)
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
		if ((intptr_t)s % 16 == 0)//|| !((intptr_t)(str1 - s) > 128128)) //MEH
			free((char *)s);
		strs = ft_join_words(ft_split(str1, c), ft_split(str2, c));
	}
	else
		strs = ft_create_word((char *)s);
	return (strs);
}
