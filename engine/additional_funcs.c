 #include "cub3d.h"

void	refresh_vars(t_all *all)
{
	int	i;

	i = 0;
	while (i <= all->cnt)
	{
		all->info.x[i] = -1;
		all->info.y[i] = -1;
		all->info.size[i] = -1;
		all->info.center[i] = 15000;
		all->info.sp_len[i] = -1;
		i++;
	}
	all->sprite.start = 0;
	all->sprite.end = 0;
	all->sprite.left = 0;
	all->sprite.right = 0;
	all->sprite.fact_width = 0;
	all->sprite.act_width = 0;
	all->sprite.h_iter = 0;
	all->sprite.w_iter = 0;
}

void	sort(t_all *all, int cnt)
{
	double	tmp;
	int		p;
	int		t;

	t = 1;
	while (t)
	{
		t = 0;
		p = -1;
		while (++p + 1 < cnt)
			if (all->info.sp_len[p] > all->info.sp_len[p + 1])
			{
				tmp = all->info.sp_len[p];
				all->info.sp_len[p] = all->info.sp_len[p + 1];
				all->info.sp_len[p + 1] = tmp;
				tmp = (int)all->info.size[p];
				all->info.size[p] = all->info.size[p + 1];
				all->info.size[p + 1] = (int)tmp;
				tmp = (int)all->info.center[p];
				all->info.center[p] = all->info.center[p + 1];
				all->info.center[p + 1] = (int)tmp;
				t = 1;
			}
	}
}
