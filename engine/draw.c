#include "../cub3d.h"

void	init_3d_vars(t_all *all, double *iter, double *mx, int wall)
{
	(all->side == 1) ?
		*iter = (double)all->tex.n.tex_height / (double)wall : 0;
	(all->side == 2) ?
		*iter = (double)all->tex.e.tex_height / (double)wall : 0;
	(all->side == 3) ?
		*iter = (double)all->tex.s.tex_height / (double)wall : 0;
	(all->side == 4) ?
		*iter = (double)all->tex.w.tex_height / (double)wall : 0;
	(all->side == 1) ?
		*mx = (all->ray.x - (int)all->ray.x) * all->tex.n.tex_width : 0;
	(all->side == 2) ?
		*mx = (all->ray.y - (int)all->ray.y) * all->tex.e.tex_width : 0;
	(all->side == 3) ?
	*mx = all->tex.s.tex_width -
	(all->ray.x - (int)all->ray.x) * all->tex.s.tex_width : 0;
	(all->side == 4) ?
	*mx = all->tex.w.tex_width - (all->ray.y -
			(int)all->ray.y) * all->tex.w.tex_width : 0;
}

void	draw_3d(t_all *all, int wall, int luchi, double k)
{
	int		start;
	int		end;
	int		color;
	double	iter;
	double	mx;

	start = all->height / 2 - wall / 2;
	end = all->height / 2 + wall / 2;
	init_3d_vars(all, &iter, &mx, wall);
	while (start++ < 0)
		k += iter;
	while (start < end && start < all->height)
	{
		if (all->side == 1)
			color = get_color(&(all->tex.n), mx, k);
		else if (all->side == 2)
			color = get_color(&(all->tex.e), mx, k);
		else if (all->side == 3)
			color = get_color(&(all->tex.s), mx, k);
		else
			color = get_color(&(all->tex.w), mx, k);
		pxl(&(all->win), luchi, start++, color);
		k += iter;
	}
}

double	init_sprite_vars(t_all *all, int q)
{
	int		to_skip;
	double	n;

	n = 0;
	all->sprite.start = all->height / 2 - all->info.size[q] / 2;
	all->sprite.end = all->height / 2 + all->info.size[q] / 2;
	all->sprite.left = all->info.center[q] - all->info.size[q] / 2;
	all->sprite.right = all->info.center[q] + all->info.size[q] / 2;
	all->sprite.act_width = all->sprite.right - all->sprite.left;
	all->sprite.h_iter = (double)all->tex.sprite.tex_height /
		(double)all->info.size[q];
	all->sprite.w_iter = (double)all->tex.sprite.tex_width /
		(double)all->sprite.act_width;
	if (all->sprite.left < 0)
		all->sprite.fact_width = all->sprite.right;
	else if (all->sprite.right > all->width && all->sprite.left < all->width)
		all->sprite.fact_width = all->width - all->sprite.left;
	else
		all->sprite.fact_width = all->sprite.act_width;
	to_skip = all->sprite.act_width - all->sprite.fact_width;
	if (all->sprite.left < 0)
		while (to_skip-- > 0)
			n += all->sprite.w_iter;
	return (n);
}

void	draw_sprite(t_all *all, int q)
{
	int		color;
	double	k;
	double	n;

	n = init_sprite_vars(all, q);
	(all->sprite.left < 0) ? all->sprite.left = 0 : 0;
	(all->sprite.right > all->width) ? all->sprite.right = all->width : 0;
	while (all->sprite.left < all->sprite.right)
	{
		k = 0;
		all->sprite.start = all->height / 2 - all->info.size[q] / 2;
		while (all->sprite.start < all->sprite.end &&
				all->sprite.start <= all->height)
		{
			color = get_color(&(all->tex.sprite), n, k);
			if (all->info.luchi_array[all->sprite.left] >
				all->info.sp_len[q] && color)
				pxl(&(all->win), all->sprite.left, all->sprite.start, color);
			all->sprite.start++;
			k += all->sprite.h_iter;
		}
		all->sprite.left++;
		n += all->sprite.w_iter;
	}
}

void	draw_floor(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (++i < all->width)
	{
		j = all->height / 2;
		while (j < all->height)
			pxl(&(all->win), i, j++, all->tex.floor_color);
	}
	i = -1;
	while (++i < all->width)
	{
		j = 0;
		while (j < all->height / 2)
			pxl(&(all->win), i, j++, all->tex.ceiling_color);
	}
	mlx_put_image_to_window(all->win.mlx, all->win.mlx_win, all->win.img, 0, 0);
}
