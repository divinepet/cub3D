/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaronda <elaronda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:31:54 by elaronda          #+#    #+#             */
/*   Updated: 2021/01/27 22:55:06 by elaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_spaces(t_all *all)
{
	int	i;
	int	lines;

	lines = 0;
	while (all->map[lines] != NULL)
	{
		i = 0;
		while (i < all->longer_string)
		{
			if (!access_symbols(all->map[lines][i]))
				all->map[lines][i] = '1';
			i++;
		}
		lines++;
	}
}

int		passed_symbols(t_all *all, int lines, int i)
{
	if (all->map[lines][i] == '0' || all->map[lines][i] == '2' ||
			all->map[lines][i] == 'N' || all->map[lines][i] == 'S' ||
			all->map[lines][i] == 'W' || all->map[lines][i] == 'E')
		return (1);
	else
		return (0);
}

int		external_symbols(t_all *all, int lines, int i, int line_max)
{
	if (lines == 0 || lines == line_max || i == 0 ||
		all->map[lines][i + 1] == ' ' || all->map[lines][i + 1] == '\0')
		return (1);
	else
		return (0);
}

void	test(t_all *all, int lines, int i, int line_max)
{
	if (lines != 0 || lines != line_max || i != 0 ||
			all->map[lines][i + 1] != ' ' ||
			all->map[lines][i + 1] != '\0')
		if (passed_symbols(all, lines, i))
			if (!access_symbols(all->map[lines][i + 1]) ||
				!access_symbols(all->map[lines][i - 1]) ||
				!access_symbols(all->map[lines + 1][i]) ||
				!access_symbols(all->map[lines - 1][i]))
				ft_error(5);
}

void	map_hole_check(t_all *all, int line_max)
{
	int	i;
	int	lines;

	lines = 0;
	while (all->map[lines] != NULL)
	{
		i = 0;
		while (all->map[lines][i] != '\0')
		{
			if (!access_symbols(all->map[lines][i]) &&
					all->map[lines][i] != ' ')
				ft_error(6);
			if (external_symbols(all, lines, i, line_max))
				if (passed_symbols(all, lines, i))
					ft_error(5);
			test(all, lines, i, line_max);
			i++;
		}
		lines++;
	}
	fill_spaces(all);
}
