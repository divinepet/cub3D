/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_load_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaronda <elaronda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:13:38 by elaronda          #+#    #+#             */
/*   Updated: 2021/01/28 02:29:56 by elaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_detect(t_all *all, int lines, int i)
{
	if (all->ray.pa == -1)
	{
		(all->map[lines][i] == 'N') ?
		all->ray.pa = M_PI * 3 / 2 : 0;
		(all->map[lines][i] == 'E') ? all->ray.pa = 0 : 0;
		(all->map[lines][i] == 'S') ? all->ray.pa = M_PI / 2 : 0;
		(all->map[lines][i] == 'W') ? all->ray.pa = M_PI : 0;
		all->ray.px = (double)i + .5;
		all->ray.py = (double)lines + .5;
	}
	else
		ft_error(77);
}

void	resolution_parser(t_all *all, char *s)
{
	(all->check.r) ? ft_error(101) : 0;
	while (!ft_isdigit(*s++))
		;
	all->width = ft_atoi(--s);
	(all->width > 2560) ? all->width = 2560 : 0;
	while (ft_isdigit(*s++))
		;
	while (!ft_isdigit(*s++))
		;
	all->height = ft_atoi(--s);
	(all->height > 1440) ? all->height = 1440 : 0;
	while (ft_isdigit(*s++))
		;
	s -= 1;
	(!(*s == '\0')) ? ft_error(202) : 0;
	all->check.r = 1;
}

void	isdone(t_all *all)
{
	if (all->check.r && all->check.no && all->check.so &&
		all->check.we && all->check.ea && all->check.c &&
		all->check.f && all->check.s && all->check.done != 2)
		all->check.done = 1;
}

int		valid_keys(char c, char d)
{
	if ((c == 'R' && d == ' ') ||
		(c == 'F' && d == ' ') ||
	(c == 'C' && d == ' ') ||
	(c == 'S' && d == ' ') ||
	(c == 'N' && d == 'O') ||
	(c == 'E' && d == 'A') ||
	(c == 'W' && d == 'E') ||
	c == '\0' ||
	(c == 'S' && d == 'O'))
		return (1);
	else
		return (0);
}
