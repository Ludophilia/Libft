/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:40:10 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/05 11:40:54 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	if (!s[i] && (s[i] == c))
		return (s + i);
	while (--i)
		if (s[i] == c)
			return (s + i);
	return ((char *)0);
}
