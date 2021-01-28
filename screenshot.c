/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaronda <elaronda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:28:14 by elaronda          #+#    #+#             */
/*   Updated: 2021/01/27 23:17:57 by elaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_headers(t_all *all, unsigned char *file_headers,
		unsigned char *info_headers)
{
	int fd;

	fd = 54 + 3 * all->width * all->height;
	file_headers[0] = 'B';
	file_headers[1] = 'M';
	file_headers[2] = fd;
	file_headers[3] = fd >> 8;
	file_headers[4] = fd >> 16;
	file_headers[5] = fd >> 24;
	file_headers[10] = 54;
	info_headers[0] = 40;
	info_headers[4] = all->width;
	info_headers[5] = all->width >> 8;
	info_headers[6] = all->width >> 16;
	info_headers[7] = all->width >> 24;
	info_headers[8] = -all->height;
	info_headers[9] = -all->height >> 8;
	info_headers[10] = -all->height >> 16;
	info_headers[11] = -all->height >> 24;
	info_headers[12] = 1;
	info_headers[14] = all->win.bits_per_pixel;
}

int		create_screen(t_all *all)
{
	int				fd;
	int				i;
	unsigned char	file_headers[14];
	unsigned char	info_headers[40];

	ft_bzero(file_headers, 14);
	ft_bzero(info_headers, 40);
	if ((fd = open("screenshot.bmp", O_RDWR | O_CREAT, 0755)) < 0)
		return (0);
	write_headers(all, file_headers, info_headers);
	write(fd, file_headers, 14);
	write(fd, info_headers, 40);
	i = 0;
	while (i < all->height)
	{
		write(fd, all->win.addr + i * all->win.line_length,
				(all->win.bits_per_pixel / 8 * all->width));
		i++;
	}
	return (1);
}
