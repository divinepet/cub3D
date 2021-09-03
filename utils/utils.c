#include "../cub3d.h"

int		check_side2(t_all *all, int quarter)
{
	double	x;
	double	y;
	int		side;

	x = all->ray.px;
	y = all->ray.py;
	while (1)
	{
		if (all->map[(int)y][(int)x] != '1' && all->map[(int)y][(int)x] != '3')
			x += 0.005 * cos(all->ray.pa);
		else
		{
			side = (quarter == 4 || quarter == 1) ? 1 : 3;
			break ;
		}
		if (all->map[(int)y][(int)x] != '1' && all->map[(int)y][(int)x] != '3')
			y += 0.005 * sin(all->ray.pa);
		else
		{
			side = (quarter == 1 || quarter == 2) ? 2 : 4;
			break ;
		}
	}
	return (side);
}

int		check_side(t_all *all)
{
	int side;

	side = 0;
	if (all->ray.pa >= 3 * M_PI / 2 && all->ray.pa < M_PI * 2)
		side = check_side2(all, 1);
	else if (all->ray.pa >= 0 && all->ray.pa < M_PI / 2)
		side = check_side2(all, 2);
	else if (all->ray.pa >= M_PI / 2 && all->ray.pa < M_PI)
		side = check_side2(all, 3);
	else if (all->ray.pa >= M_PI && all->ray.pa < 3 * M_PI / 2)
		side = check_side2(all, 4);
	return (side);
}

int		no_clip(t_all *all, int a)
{
	double	temppx;
	double	temppy;
	char	c;

	temppx = all->ray.px;
	temppy = all->ray.py;
	if (a == 1)
	{
		temppx += all->ray.pdx * 0.5;
		temppy += all->ray.pdy * 0.5;
	}
	else if (a == 2)
	{
		temppx -= all->ray.pdx * 0.5;
		temppy -= all->ray.pdy * 0.5;
	}
	else if (a == 3 || a == 4)
		no_clip2(all, a, &temppx, &temppy);
	c = all->map[(int)(temppy)][(int)(temppx)];
	return (c == '0' || c == 'S' || c == 'E' || c == 'W' || c == 'N') ? 1 : 0;
}

int		check_xpm_extension(char *s)
{
	int i;

	i = ft_strlen(s);
	if ((s[i - 1] == 'm' || s[i - 1] == 'M') &&
		(s[i - 2] == 'p' || s[i - 2] == 'P') &&
		(s[i - 3] == 'x' || s[i - 3] == 'X') &&
		(s[i - 4] == '.' || s[i - 4] == '.'))
		return (1);
	else
		ft_error(3);
	return (0);
}

int		check_cub_extension(char *s, int av)
{
	int	i;

	i = 0;
	if (av == 1)
	{
		i = ft_strlen(s);
		if (s[i - 1] == 'b' && s[i - 2] == 'u' &&
				s[i - 3] == 'c' && s[i - 4] == '.')
			return (1);
		else
			ft_error(2);
	}
	if (av == 2)
	{
		if (s[i] == '-' && s[i + 1] == '-' && s[i + 2] == 's' &&
				s[i + 3] == 'a' && s[i + 4] == 'v' &&
				s[i + 5] == 'e' && s[i + 6] == '\0')
		{
			write(1, "Screenshot has been saved\n", 26);
			return (1);
		}
		else
			ft_error(99);
	}
	return (0);
}
