/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:59:43 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/01 17:41:19 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Size t? How do I implement this?
size_t	ft_strlen(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}
