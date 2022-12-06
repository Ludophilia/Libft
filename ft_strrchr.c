/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:40:10 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/06 15:56:25 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	if (!s[i] && (s[i] == c))
		return ((char *)s + i);
	while (--i >= 0)
		if (s[i] == c)
			return ((char *)s + i);
	return ((char *)0);
}
