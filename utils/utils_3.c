#include "../cub3d.h"

void	no_clip2(t_all *all, int a, double *temppx, double *temppy)
{
	if (a == 3)
	{
		*temppx += all->ray.pdy * 0.3;
		*temppy -= all->ray.pdx * 0.3;
	}
	else if (a == 4)
	{
		*temppx -= all->ray.pdy * 0.3;
		*temppy += all->ray.pdx * 0.3;
	}
}

void	new_image(t_all *all)
{
	all->win.img = mlx_new_image(all->win.mlx, all->width, all->height);
	all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bits_per_pixel,
			&all->win.line_length, &all->win.endian);
}

int		ft_isdigit(int ch)
{
	return ((ch >= '0' && ch <= '9') ? 1 : 0);
}

int		ft_atoi(const char *str)
{
	int					i;
	int					ink;
	unsigned long int	num;

	i = 0;
	ink = 1;
	num = 0;
	if (!str[i])
		return (0);
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ' || str[i] == '\r')
		i += 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			ink = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	if (num > 9223372036854775807 && ink > 0)
		return (-1);
	else if (num > 9223372036854775807 && ink < 0)
		return (0);
	return (num * ink);
}

void	ft_bzero(void *s, size_t n)
{
	char	*src;
	int		i;

	i = 0;
	src = s;
	while (i < (int)n)
		src[i++] = '\0';
}
