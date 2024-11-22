/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 19:04:58 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

#define FL_NAME "test31"

static void	hdn_test_putstr(char *str)
{
	int		fd;
	char	buffer[50];

	assert(str != NULL);
	ft_bzero(buffer, 50);
	fd = open(FL_NAME, O_CREAT | O_TRUNC | O_RDWR);
	if (fd == -1 && dprintf(2, "Failed to create file.\n"))
		return ;
	// printf("ft_putstr_fd(\"%s\", %i)\n", str, fd);
	ft_putstr_fd(str, fd);
	if (lseek(fd, 0, SEEK_SET) == -1 || (read(fd, buffer, ft_strlen(str)) == -1
			&& dprintf(2, "Failed to read file.\n")))
	{
		close(fd);
		unlink(FL_NAME);
		return ;
	}
	// printf("buffer -> \"%s\"\n", buffer);
	assert(ft_memcmp(buffer, str, ft_strlen(str) + 1) == 0);
	close(fd);
	unlink(FL_NAME);
}

int	main(void)
{
	hdn_test_putstr("");
	hdn_test_putstr("0123456789");
	printf("[OK] putstr_fd\n");
}
