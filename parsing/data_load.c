/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaronda <elaronda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:30:10 by elaronda          #+#    #+#             */
/*   Updated: 2021/01/28 02:27:14 by elaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tex_parser2(t_all *all, char *s, int code)
{
	if (code == 3 && check_xpm_extension(s))
	{
		(all->check.we) ? ft_error(101) : 0;
		while (*s != ' ')
			s += 1;
		while (*s == ' ')
			s += 1;
		(open(s, O_RDONLY) < 0) ? exit(0) : 0;
		all->tex.w.path = ft_strdup(s);
		all->check.we = 1;
	}
	else if (code == 4 && check_xpm_extension(s))
	{
		(all->check.ea) ? ft_error(101) : 0;
		while (*s != ' ')
			s += 1;
		while (*s == ' ')
			s += 1;
		(open(s, O_RDONLY) < 0) ? exit(0) : 0;
		all->tex.e.path = ft_strdup(s);
		all->check.ea = 1;
	}
}

void	tex_parser(t_all *all, char *s, int code)
{
	if (code == 1 && check_xpm_extension(s))
	{
		(all->check.no) ? ft_error(101) : 0;
		while (*s != ' ')
			s += 1;
		while (*s == ' ')
			s += 1;
		(open(s, O_RDONLY) < 0) ? exit(0) : 0;
		all->tex.n.path = ft_strdup(s);
		all->check.no = 1;
	}
	if (code == 2 && check_xpm_extension(s))
	{
		(all->check.so) ? ft_error(101) : 0;
		while (*s != ' ')
			s += 1;
		while (*s == ' ')
			s += 1;
		(open(s, O_RDONLY) < 0) ? exit(0) : 0;
		all->tex.s.path = ft_strdup(s);
		all->check.so = 1;
	}
}

void	sprite_parser(t_all *all, char *s, int code)
{
	if (code == 5 && check_xpm_extension(s))
	{
		(all->check.s) ? ft_error(101) : 0;
		while (*s != ' ')
			s += 1;
		while (*s == ' ')
			s += 1;
		(open(s, O_RDONLY) < 0) ? exit(0) : 0;
		all->tex.sprite.path = ft_strdup(s);
		all->check.s = 1;
	}
}

void	c_color_parser(t_all *all, char *s)
{
	int	r;
	int	g;
	int	b;
	int	i;

	r = -1;
	g = -1;
	b = -1;
	i = 0;
	(all->check.c) ? ft_error(101) : 0;
	while (*s != '\0')
	{
		while (!ft_isdigit(*s))
			s += 1;
		(!i) ? r = ft_atoi(s) : 0;
		(i == 1) ? g = ft_atoi(s) : 0;
		(i == 2) ? b = ft_atoi(s) : 0;
		while (ft_isdigit(*s))
			s += 1;
		i++;
	}
	all->tex.ceiling_color = rgb_to_hex(r, g, b);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_error(4);
	all->check.c = 1;
}

void	f_color_parser(t_all *all, char *s)
{
	int	r;
	int	g;
	int	b;
	int	i;

	r = -1;
	g = -1;
	b = -1;
	i = 0;
	(all->check.f) ? ft_error(101) : 0;
	while (*s != '\0')
	{
		while (!ft_isdigit(*s))
			s += 1;
		(!i) ? r = ft_atoi(s) : 0;
		(i == 1) ? g = ft_atoi(s) : 0;
		(i == 2) ? b = ft_atoi(s) : 0;
		while (ft_isdigit(*s))
			s += 1;
		i++;
	}
	all->tex.floor_color = rgb_to_hex(r, g, b);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_error(4);
	all->check.f = 1;
}
