/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaronda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:14:09 by elaronda          #+#    #+#             */
/*   Updated: 2021/01/28 01:14:14 by elaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_arrays(t_all *all)
{
	int	i;

	i = 0;
	(!(all->info.size = malloc(sizeof(int) * (all->cnt + 1)))) ? exit(0) : 0;
	(!(all->info.x = malloc(sizeof(int) * (all->cnt + 1)))) ? exit(0) : 0;
	(!(all->info.y = malloc(sizeof(int) * (all->cnt + 1)))) ? exit(0) : 0;
	(!(all->info.center = malloc(sizeof(int) * (all->cnt + 1)))) ? exit(0) : 0;
	(!(all->info.sp_len = malloc(sizeof(double) * (all->cnt + 1)))) ?
	exit(0) : 0;
	(!(all->info.luchi_array = malloc(sizeof(double) * (all->width + 1)))) ?
	exit(0) : 0;
	while (i <= all->cnt)
	{
		all->info.x[i] = -1;
		all->info.y[i] = -1;
		all->info.size[i] = -1;
		all->info.center[i] = 15000;
		all->info.sp_len[i] = -1;
		i++;
	}
	all->info.x[i] = '\0';
	all->info.y[i] = '\0';
	all->info.size[i] = '\0';
	all->info.center[i] = '\0';
	all->info.sp_len[i] = '\0';
}

void	init_struct(t_all *all)
{
	all->width = 0;
	all->height = 0;
	all->side = 0;
	all->scale = 10;
	all->minimap_flag = 0;
	all->ray.pdx = 0;
	all->ray.pdy = 0;
	all->ray.pa = -1;
	all->ray.px = 0;
	all->ray.py = 0;
	all->ray.x = 0;
	all->ray.y = 0;
	all->ray.no_clip = 0;
	all->cnt = 0;
	all->win.bits_per_pixel = 0;
	all->win.line_length = 0;
	all->win.endian = 0;
	all->tex.n.path = NULL;
	all->tex.s.path = NULL;
	all->tex.e.path = NULL;
	all->tex.w.path = NULL;
	all->tex.sprite.path = NULL;
	all->tex.floor_color = 0;
	all->tex.ceiling_color = 0;
}

void	init_checker(t_all *all)
{
	all->check.r = 0;
	all->check.so = 0;
	all->check.we = 0;
	all->check.ea = 0;
	all->check.no = 0;
	all->check.s = 0;
	all->check.c = 0;
	all->check.f = 0;
	all->check.done = 0;
}
