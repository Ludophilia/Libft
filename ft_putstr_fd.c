/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:01:07 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/10 17:07:27 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Those fd need to be protected at all costs!! But how? Is that even necesary
// knowing that write will print nothing if fd is not in the correct range??
void	ft_putstr_fd(char *s, int fd)
{
	if (!(fd >= 0 && fd <= 2))
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}
