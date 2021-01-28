/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaronda <elaronda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:48:44 by elaronda          #+#    #+#             */
/*   Updated: 2021/01/28 02:24:33 by elaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_in_array_parser(t_all *all, int cnt)
{
	int	i;
	int	lines;

	lines = 0;
	while (all->map[lines] != NULL)
	{
		i = -1;
		while (all->map[lines][++i] != '\0')
		{
			if (all->map[lines][i] == 'N' || all->map[lines][i] == 'S' ||
			all->map[lines][i] == 'W' || all->map[lines][i] == 'E')
				player_detect(all, lines, i);
			(all->map[lines][i] == '2') ? all->cnt += 1 : 0;
			if ((all->map[lines][i] == '1') && (all->map[lines][i + 1] != '\0')
					&& (lines != 0) && (lines != cnt) && (i != 0))
				all->map[lines][i] = '3';
		}
		lines++;
	}
	(all->ray.pa == -1) ? ft_error(7) : 0;
}

char	*ft_strdup_modified(t_all *all, const char *str)
{
	int		i;
	char	*copy;

	i = 0;
	if (!(copy = malloc(sizeof(char) * (all->longer_string + 1))))
		exit(0);
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	while (i < all->longer_string)
		copy[i++] = ' ';
	copy[i] = '\0';
	return (copy);
}

int		line_count(t_all *all, char *av)
{
	char	*line;
	int		i;
	int		fd;

	all->longer_string = 0;
	i = 0;
	fd = open(av, O_RDONLY);
	(fd < 0) ? exit(0) : 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '1' || line[0] == ' ')
		{
			if ((int)ft_strlen(line) > all->longer_string)
				all->longer_string = ft_strlen(line);
			i++;
		}
		free(line);
	}
	i += 2;
	free(line);
	line = NULL;
	return (i);
}

int		get_values(t_all *all, char *line, int *i)
{
	if (line[0] == '\0' && all->check.done != 2)
		return (1);
	(line[0] == 'R') ? resolution_parser(all, line) : 0;
	(line[0] == 'N' && line[1] == 'O') ? tex_parser(all, line, 1) : 0;
	(line[0] == 'S' && line[1] == 'O') ? tex_parser(all, line, 2) : 0;
	(line[0] == 'W' && line[1] == 'E') ? tex_parser2(all, line, 3) : 0;
	(line[0] == 'E' && line[1] == 'A') ? tex_parser2(all, line, 4) : 0;
	(line[0] == 'S' && line[1] == ' ') ? sprite_parser(all, line, 5) : 0;
	(line[0] == 'F') ? f_color_parser(all, line) : 0;
	(line[0] == 'C') ? c_color_parser(all, line) : 0;
	isdone(all);
	if ((access_symbols(line[0]) || line[0] == ' ') && all->check.done)
	{
		all->check.done = 2;
		all->map[*i] = ft_strdup_modified(all, line);
		*i += 1;
	}
	else if (all->check.done == 2)
		ft_error(5);
	if (valid_keys(line[0], line[1]) == 0 && all->check.done != 2)
		ft_error(202);
	return (0);
}

void	open_map(t_all *all, char *av)
{
	char	*line;
	int		fd;
	int		i;
	int		line_cnt;

	i = 0;
	fd = open(av, O_RDONLY);
	(fd < 0) ? exit(0) : 0;
	line_cnt = line_count(all, av);
	(!(all->map = (char**)malloc(sizeof(char*) * line_cnt))) ? exit(0) : 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (get_values(all, line, &i) == 1)
			continue;
		free(line);
	}
	all->map[i++] = ft_strdup_modified(all, line);
	all->map[i] = NULL;
	free(line);
	line = NULL;
	error_check(all);
	map_hole_check(all, line_cnt - 2);
	map_in_array_parser(all, line_cnt - 2);
}
