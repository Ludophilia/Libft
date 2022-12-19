/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:08:05 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/19 18:25:27 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// RIP NORMINETTE
static size_t	ft_arrlen(char **strs)
{
	size_t	len;
    int     i;
    
    i = -1;
	len = 0;
	while (strs[++i])
		//if (strs[i][0])
		len++;
	//printf("len - %lu\n", len);
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
		//if (strs1[i][0])
		//    printf("strs1[i][0] = %s\n", strs1[i]);
		strs[i] = strs1[i];
		//else
        //    free(strs1[i]);
		i++;
	}
	while (strs2[i - len1])
	{
		//if (strs2[i - len1][0])
		//    printf("strs2[i - len1][0] = %s\n\n", strs2[i - len1]);
		strs[i] = strs2[i - len1];
		//else
		//    free(strs2[i - len1]);
		i++;
	}
	strs[i] = (char *)0;
	free(strs1);
	free(strs2);
	return (strs);
}


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
		printf("str1 -> '%s', str2 -> '%s'\n", str1, str2);

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
	}
	
	// ft_arrjoin(ft_split(str1, c), ft_split(str2, c))
	// ft_arrjoin(, )
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

int main() {
    char    **strs;
    int     i;
    
    strs = ft_split("  tripouille  42  ", ' ');
    i = -1;
    //while (strs[++i])
    //    printf("'%s'\n", strs[i]);
    return 0;
}

//////////////////////////////////////////////////////

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	size;
// 	size_t	slen;
// 	size_t	i;

// 	size = 0;
// 	slen = ft_strlen(s);
// 	while (((start + size) < slen) && (size < len))
// 		size++;
// 	substr = malloc((size + 1) * sizeof(char));
// 	if (!substr)
// 		return ((char *)0);
// 	i = 0;
// 	while ((i < size) && ((start + i) < slen))
// 	{
// 		substr[i] = s[start + i];
// 		i++;
// 	}
// 	substr[i] = '\x0';
// 	return (substr);
// }


// void	*ft_memchr(const void *s, int c, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (((unsigned char *)s)[i] == (unsigned char)c)
// 			return ((void *)s + i);
// 		i++;
// 	}
// 	return ((void *)0);
// }