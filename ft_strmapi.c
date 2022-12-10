/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:55:29 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/10 16:10:23 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// MEMORY LEAK FREE OR WOT?
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ns;
	unsigned int		i;

	ns = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ns)
		return ((char *)0);
	i = 0;
	while (s[i])
		ns[i++] = f(i, s[i]);
	ns[i] = '\x0';
	return (ns);
}
