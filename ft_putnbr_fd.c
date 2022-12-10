/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:21:01 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/10 17:34:35 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Those fd need to be protected at all costs!! But how? Is that even necesary
// knowing that write will print nothing if fd is not in the correct range??
void	ft_putnbr_fd(int nb, int fd)
{
	if (!(fd >= 0 && fd <= 2))
		return ;
	if (nb >= 10 || nb <= -10)
		ft_putnbr_fd(nb / 10, fd);
	if (nb < 0 && nb > -10)
		ft_putchar_fd('-', fd);
	if (nb < 0)
		nb = '0' + -(nb % 10);
	else
		nb = '0' + (nb % 10);
	ft_putchar_fd(&nb, fd);
}
