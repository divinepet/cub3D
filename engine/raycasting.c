#include "../cub3d.h"

double	find_side(t_all *all, int quarter, double start)
{
	while (1)
	{
		if (all->map[(int)all->ray.y][(int)all->ray.x] != '1' &&
				all->map[(int)all->ray.y][(int)all->ray.x] != '3')
			all->ray.x += 0.005 * cos(start);
		else
		{
			(quarter == 4 || quarter == 1) ? all->side = 1 : 0;
			(quarter == 2 || quarter == 3) ? all->side = 3 : 0;
			return (sqrt(pow(all->ray.x - all->ray.px, 2) +
						pow(all->ray.y - all->ray.py, 2)));
		}
		if (all->map[(int)all->ray.y][(int)all->ray.x] != '1' &&
				all->map[(int)all->ray.y][(int)all->ray.x] != '3')
			all->ray.y += 0.005 * sin(start);
		else
		{
			(quarter == 1 || quarter == 2) ? all->side = 2 : 0;
			(quarter == 3 || quarter == 4) ? all->side = 4 : 0;
			return (sqrt(pow(all->ray.x - all->ray.px, 2) +
						pow(all->ray.y - all->ray.py, 2)));
		}
	}
	return (0);
}

void	sub_offset_fov(t_all *all, double off_x, double off_y, int offset_luchi)
{
	double	radius;
	double	temp_x;
	double	temp_y;
	int		i;

	i = 0;
	while ((all->info.x[i] != (int)off_x ||
			all->info.y[i] != (int)off_y) && (all->info.x[i] != -1 &&
			all->info.y[i] != -1))
		i++;
	if (all->info.size[i] == -1)
	{
		temp_x = ((double)((int)off_x)) + 0.5;
		temp_y = ((double)((int)off_y)) + 0.5;
		radius = sqrt(pow(temp_x - off_x, 2) + pow(temp_y - off_y, 2));
		if (radius >= 0.01 && radius <= 0.03)
		{
			all->info.sp_len[i] = sqrt(pow(temp_x - all->ray.px, 2) +
				pow(temp_y - all->ray.py, 2));
			all->info.size[i] = (int)((double)all->width / all->info.sp_len[i]);
			all->info.x[i] = (int)off_x;
			all->info.y[i] = (int)off_y;
			all->info.center[i] = offset_luchi;
		}
	}
}

int		offset_fov(t_all *all, int tmp)
{
	double	start;
	double	offset_x;
	double	offset_y;
	int		offset_luchi;

	offset_luchi = all->width * -1.5;
	start = all->ray.pa - M_PI / 2;
	while (start < all->ray.pa + M_PI / 2)
	{
		offset_x = all->ray.px;
		offset_y = all->ray.py;
		while (all->map[(int)offset_y][(int)offset_x] != '1')
		{
			offset_x += 0.005 * cos(start);
			offset_y += 0.005 * sin(start);
			(all->map[(int)offset_y][(int)offset_x] == '2') ?
				sub_offset_fov(all, offset_x, offset_y, offset_luchi) : 0;
		}
		start += M_PI / (all->width * 4);
		offset_luchi++;
	}
	while (all->info.x[tmp] != -1 && all->info.y[tmp] != -1)
		tmp++;
	return (tmp);
}

int		quarter_set(double start)
{
	if (fix_ang(start) >= 3 * M_PI / 2 && fix_ang(start) < M_PI * 2)
		return (1);
	else if (fix_ang(start) >= 0 && fix_ang(start) < M_PI / 2)
		return (2);
	else if (fix_ang(start) >= M_PI / 2 && fix_ang(start) < M_PI)
		return (3);
	else if (fix_ang(start) >= M_PI && fix_ang(start) < 3 * M_PI / 2)
		return (4);
	return (0);
}

void	draw(t_all *all)
{
	int		luchi;
	int		wall;
	int		cnt;
	double	start;
	double	ray_len;

	luchi = -1;
	start = all->ray.pa - M_PI / 8;
	draw_floor(all);
	while (++luchi < all->width)
	{
		all->ray.x = all->ray.px;
		all->ray.y = all->ray.py;
		ray_len = find_side(all, quarter_set(start), fix_ang(start));
		all->info.luchi_array[luchi] = ray_len;
		wall = (int)((double)all->width / (ray_len * cos(all->ray.pa - start)));
		draw_3d(all, wall, luchi, 0);
		start += (M_PI / 4) / (all->width);
	}
	all->info.luchi_array[luchi] = '\0';
	refresh_vars(all);
	((cnt = offset_fov(all, 0)) > 1) ? sort(all, cnt) : 0;
	while (cnt-- > 0)
		draw_sprite(all, cnt);
	mlx_put_image_to_window(all->win.mlx, all->win.mlx_win, all->win.img, 0, 0);
}
