/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaronda <elaronda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:27:32 by elaronda          #+#    #+#             */
/*   Updated: 2021/01/28 02:05:18 by elaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(int code)
{
	(code == 0) ? write(1, "Bad resolution set", 18) : 0;
	(code == 1) ? write(1, "Not enoght arguments", 21) : 0;
	(code == 2) ? write(1, "Bad map extension. Must be '.cub'", 33) : 0;
	(code == 3) ? write(1, "Bad texture extension", 21) : 0;
	(code == 4) ? write(1, "Bad color set", 13) : 0;
	(code == 5) ? write(1, "The map isn't closed or not corrected", 37) : 0;
	(code == 6) ? write(1, "Not access symbols in map", 25) : 0;
	(code == 7) ? write(1, "No player in the map", 20) : 0;
	(code == 77) ? write(1, "Two player in map", 17) : 0;
	(code == 99) ? write(1, "Fail third argument", 19) : 0;
	(code == 101) ? write(1, "Duplicate parameters", 20) : 0;
	(code == 202) ? write(1, "Trash in file", 13) : 0;
	write(1, "\n", 1);
	exit(0);
}

void	error_check(t_all *all)
{
	(all->tex.e.path == NULL || all->tex.n.path == NULL ||
	all->tex.s.path == NULL || all->tex.w.path == NULL ||
	all->tex.sprite.path == NULL) ? ft_error(3) : 0;
	(all->tex.floor_color == 0 || all->tex.ceiling_color == 0) ?
		ft_error(4) : 0;
	(all->width <= 0 || all->height <= 0) ? ft_error(0) : 0;
}
