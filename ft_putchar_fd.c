/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:32:01 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/10 17:06:24 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Those fd need to be protected at all costs!! But how? Is that even necesary
// knowing that write will print nothing if fd is not in the correct range??
void	ft_putchar_fd(char c, int fd)
{
	if (!(fd >= 0 && fd <= 2))
		return ;
	write (fd, &c, 1);
}
