#include "../cub3d.h"

int		access_symbols(char c)
{
	if (c == '1' || c == '2' || c == '0' || c == 'N' ||
			c == 'W' || c == 'E' || c == 'S' || c == '3')
		return (1);
	else
		return (0);
}

void	pxl(t_data *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		get_color(t_data *polar, int x, int y)
{
	int	color;

	color = 0;
	x = abs(x);
	y = abs(y);
	color = (*(int *)(polar->addr + ((x + (y * polar->tex_width)) *
					(polar->bits_per_pixel / 8))));
	return (color);
}

double	fix_ang(double f)
{
	if (f > 2 * M_PI)
		f -= 2 * M_PI;
	if (f < 0)
		f += 2 * M_PI;
	return (f);
}

int		rgb_to_hex(int r, int g, int b)
{
	return ((1 << 24) + (r << 16) + (g << 8) + b);
}
