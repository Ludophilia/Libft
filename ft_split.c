/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:08:05 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/21 16:29:32 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// void	debug_str(const char *s, char *str1, char *str2)
// {
// 	printf("\t[ft_split] s %% 16 -> %li\n", (intptr_t)s % 16);
// 	printf("\t[ft_split] str1 - s -> %li\n", (intptr_t)(str1 - s));
// 	printf("\t[ft_split] str2 - s -> %li\n", (intptr_t)(str2 - s));
// 	printf("\t[ft_split] str2 - str1 -> %li\n\n", (intptr_t)(str2 - str1));
// }

// void	debug_strs(char **strs, int nl)
// {
// 	printf("\t[debug_strs] arrlen = %lu\n", ft_wordslen(strs));
// 	if (!*strs)
// 		printf("\t\t-> just a null (char*)\n");
// 	while (*strs)
// 		printf("\t\t-> '%s'\n", *strs++);
// 	if (nl)
// 		printf("\n");
// }

// Solve memory issues:

// IDEA #1 - (In the end : [03] strs [05] arr of strs are still remaining, as 
// wanted. Could work, let's test that...)
	// Instead of using substr, why not start like that ?
	// ft_split (one instance)
		// - [+01] Duplicate str s
		// - look for sep in duplicate
		// - if (sep)
			// - replace sep by a '\0' (this will effectively create a substr
			// within the duplicate) thus making...
				// - str1 = starts at duplicate, \0 terminated at sep
				// - str2 = starts at sep + 1, \0 terminated at end of duplicate
			// - join_words(ft_split(str1, c), ft_split(str2, c)) if needed
			// a new duplicate [+02] will be created and will be freed once
			// split (instance) will reach the end of block [-02]
				// within join_words :
					// - a new arr of str [+05] will be created that could be
					// freed or not, depending if it's the top one
					// - the arr of strs [04] used to create the new arr of str
					// will be destroyed once its content (those [03] that 
					// should not be destroyed) is copied [-04]
		// - else
			// - ft_create_word((char *)s) with the duplicate [01]. The duplicate
			// should not be freed, this is taken care of by split.
				// - if the duplicate is not an empty str, a new duplicate [+03]
				// that should not be freed will be created and added to a 
				// new arr of str [+04] that will be freed in join_words
				// - otherwise, the arr of str will just be comprised of a null 
				// (char *).
		// - [-01] free duplicate(ft_split(str1, c), ft_split(str2, c))

static size_t	ft_wordslen(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len])
			len++;
	return (len);
}

// Then - Memory (free those empty strs)
static char	**ft_join_words(char **strs1, char **strs2)
{
	char	**strs;
	size_t	lens1;
	size_t	i;

	lens1 = ft_wordslen(strs1);
	strs = (char **)malloc((lens1 + ft_wordslen(strs2) + 1) * sizeof(char *));
	if (!strs)
		return ((char **)0);
	i = 0;
	while (strs1[i])
	{
		strs[i] = strs1[i];
		i++;
	}
	while (strs2[i - lens1])
	{
		strs[i] = strs2[i - lens1];
		i++;
	}
	strs[i] = (char *)0;
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
	i = 0;
	while (len--)
		strs[i++] = ft_strdup(s);
	strs[i] = (char *)0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*dup;
	char	*sep;
	
	dup = ft_strdup(s);
	sep = ft_memchr(dup, c, ft_strlen(dup));
	if (sep)
	{
		*sep = '\x0';
		strs = ft_join_words(ft_split(dup, c), ft_split(sep + 1 , c));
	}
	else
		strs = ft_create_word(dup);
	free(dup);
	return (strs);
}
