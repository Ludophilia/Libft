/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:08:05 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/07 16:58:51 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**split(char const *s, char c)
{
	// Let's use divide and conquer

	// Divide phase: recursively.
		// Take a str, a char c which works as the sep
		// if there is a char c:
			// What is on left of the sep c is passed to a new instance of
			// split,
			// What is on the right, same
		// This is repeated until... there is no char c in s or s is an empty 
		// str.
			// Then, what is returned by those instances of split ?
			// An array containing a pointer to the str created

	// What to do ?
		// How to check the str and find c ? (ft_strchr) ?
	char	**arr;
	char	*str1;
	char	*str2;
	char	*sep;
	
	sep = ft_strchr(s, c);
	arr = malloc(3 * sizeof(char *));
	if (!arr)
		return ((char **)0);
	if (sep)
	{
		str1 = ft_substr(s, 0, (sep - s)); 
		str2 = ft_substr(s, ((sep - s) + 1), (ft_strlen(s) - (sep - s + 1)));
		
		arr = split(str1, c);
		arr = split(str2, c);
	}
	else
	{
		
	}


	
		
	// Conquer phase:
		// ???
	return (arr);
}