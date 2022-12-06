/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:56:25 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/06 15:50:54 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// MEMORY LEAK SAFE OR NOT ?
char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = malloc((ft_strlen(s) * sizeof(char)) + 1);
	if (!str)
		return ((char *)0);
	i = 0;
	while (s[i])
		str[i++] = s[i];
	str[i] = '\x0';
	return ((char *)str);
}
